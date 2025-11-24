# QMK Autocorrect Typo Generator

`autocorrgen.py` is a Python script that generates autocorrect dictionaries for QMK firmware.

It algorithmically "fuzzes" a list of English words to create common mechanical typing errors, validates them against a dictionary to ensure they aren't real words, and formats them for QMK's Autocorrect feature.

It was created to address the lack of available dictionaries which focus exclusively on typographical errors from "fat fingers" rather than spelling errors due to a genuine lack of knowledge.

While created with English in mind, this could easily be adapted to other languages with the appropriate Python libraries.

## Features

Generates the following types of typos from the supplied word list:
- **Transpositions**: Swaps adjacent characters (e.g., `word` -> `wrod`).
- **Deletions**: Removes single characters from words >=4 chars (e.g., `because` -> `becuse`).
- **Key Replacements**: Replaces a character with an adjacent key (e.g., `apple` -> `applw` via `e->w` map).
- **Extra Letters**: Inserts adjacent keys before/after target letters (e.g., `apple` -> `applew` and `applwe` via `e->w`).

Other features:
- **Intelligent Boundaries**: Automatically adds QMK boundary markers (`:typo`, `typo:`, `:typo:`) to prevent typos from triggering inside larger words (e.g., prevents `no` -> `on` from triggering inside `noon`).
- **Adjustable Collision Resolution**: If a typo maps to multiple valid words (e.g., `thn` could be `then` or `than`), it uses a frequency data to pick the statistically likely correction or discards it if ambiguous (`then` and `than` have a frequency ratio close to 1, so the typo is considered ambiguous and is discarded). Users may adjust the frequency ratio used to select or discard the typo.
- **Pattern Generalization**: Consolidates repetitive suffix/prefix errors into wildcard rules (e.g., `*in:` -> `*ing`) to save firmware space.
- **Personalizable and Adjustable**: Specify words you (don't) want corrected and replacement/extra letter combos you specifically struggle with.

## Installation

This script relies on `wordfreq` for frequency analysis and `english-words` for validation.

```bash
# Recommended: Install inside your QMK virtual environment
pip install wordfreq english-words
```

## Basic Usage

The script outputs to `stdout` by default, or to a file if `-o` is specified.

```bash
# Generate corrections for the top 1000 most common English words
python autocorrgen.py --top-n 1000 -o autocorrect.txt

# Generate QMK source code from the text output
qmk generate-autocorrect-data autocorrect.txt
```

## Usage Examples

**Using a custom word list:**
Use `--include` to process specific words instead of (or in addition to) the top-N list. The following command generates transpositions and deletions for everything in `my_words.txt` only.
```bash
python3 autocorrgen.py --include my_words.txt -o autocorrect.txt
```

**Using Adjacent Key Mapping:**
The following command generates transposition, deletion, insertion, and replacement typos from the 500 most frequent words based on the provided adjacent key file.
```bash
python3 autocorrgen.py --top-n 500 --adjacent-letters adjacent_keys.txt -o autocorrect.txt
```

**Using Exclusions and Strict Frequency:**
Generate transposition and deletion typos for the 2000 most frequent words, except those in `exclusions.txt`. If the typo occurs as a substring of a word with a frequency above 1e-7 in `wordfreq`, skip it.
```bash
python3 autocorrgen.py \
    --top-n 2000 \
    --exclude-file exclusions.txt \
    --typo-freq-threshold 1e-7 \
    -o autocorrect.txt
```

Using `--typo-freq-threshold` is recommended for catching conjugations and other transformations, slang, etc. For example, `juts`—a form of the verb "jut" meaning to "extend out, over, or beyond the main body or line of something", but also a transposition of `just`—does not occur in `english-words` (only `jut`), but does occur in `wordfreq` with a frequency of 2.29e-7.

### A Note on Dictionary Size
The QMK Autocorrect dictionary is currently limited in size to somewhere between 4,000-5,000 corrections, depending somewhat on the corrections themselves. It may require some iteration to find the right combination of `--top-n`, `--max-length`, and `--adjacent-letters` to maximize the size of your personal dictionary.

## Command Line Arguments

| Argument | Default | Description |
| :--- | :--- | :--- |
| `--top-n N` | `None` | Process the top N most frequent words from `wordfreq` that meet the length requirements. |
| `--include FILE` | `None` | Specific file of words to process (ignores `--max-length`). |
| `--output`, `-o` | `stdout` | File path to write the generated dictionary. |
| `--jobs`, `-j` | CPU Count | Number of parallel worker processes. |
| `--verbose`, `-v` | `False` | Print statistics, collision warnings, and dropped typos. |

### Tuning & Filtering
| Argument | Default | Description |
| :--- | :--- | :--- |
| `--max-word-length` | `10` | Max length of source words to process. |
| `--min-word-length` | `3` | Minimum length of source word. |
| `--min-typo-length` | `5` | Minimum length of the generated typo to be included. QMK will generate warnings for typos shorter than 5 characters.
| `--freq-ratio` | `10.0` | If a typo matches two words, the winner must be N times more frequent, otherwise the typo is discarded. For example, both `open` and `one` can produce `oen`, and `one` is 9.77 times more frequent than `open`. If set to <9.77, this would include the typo `oen -> one` in the output. |
| `--typo-freq-threshold`| `0.0` | If a generated typo appears in real usage (frequency > N), discard it. Try values around `1e-6` to `1e-8`.|

### External Resources
| Argument | Description |
| :--- | :--- |
| `--exclude-file` | File containing patterns/words to ignore (see below). |
| `--adjacent-letters` | File mapping keys to neighbors for replacement/insertion typos (see below). |

## File Formats

### Inclusion File (`--include`)
Supports comments (`#`) and words.

```text
# words to generate typos for
mechanical
keyboard
firmware
```

### Exclusion File (`--exclude-file`)
Supports comments (`#`), exact words, and wildcards.

```text
# Exact word exclusion (ignore typos correcting to this)
football

# Wildcards (skip word families)
*toin    # Skips phenytoin, allantoin, etc. to allow toin: -> tion
pre* # Skips all words beginning in "pre"

# Pattern exclusion (prevents specific mapping)
in: -> ing  # Don't change informal "-in" to "-ing"
```

### Adjacent Letters File (`--adjacent-letters`)
Maps a key to its physical neighbors. Used for **Replacement** and **Insertion** generation.

Format: `key -> neighbors`

```text
# QWERTY Examples
a -> s
s -> ad
e -> wrd
```
* **Replacement:** `e -> wr` generates `wxample`, `rxample` (plus variations on other 'e's in the word).
* **Insertion:** `e -> wr` generates `wexample`, `ewxample`, `rexample`, `erxample` (plus variations on other 'e's in the word).

Use these sparingly and consciously, as they significantly inflate the dictionary.

## Output Format Logic

The script tries to generate the most "naked" typo possible to save space, but adds colons (`:`) where necessary to define word boundaries.

1.  **`typo`**: Safe to use anywhere (substring match).
2.  **`:typo`**: Only matches if typo is at the start of a word (Space + typo).
3.  **`typo:`**: Only matches if typo is at the end of a word (Typo + Space/Punctuation).
4.  **`:typo:`**: Exact match only (spaces on both sides).

## Credits

Based on the logic for QMK Firmware.
Uses [wordfreq](https://pypi.org/project/wordfreq/) and [english-words](https://pypi.org/project/english-words/).

## License

MIT License

Copyright © 2025 Adam Goldsmith

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
