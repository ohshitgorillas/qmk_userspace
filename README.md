# ohshitgorillas' QMK Userspace

Welcome to my personal userspace for [QMK Firmware](https://qmk.fm/), where I customize the behavior of my mechanical keyboards. This repository contains all the code for my keyboard layouts and custom modules.


## 60% Keyboards

I use a shared layout for my two 60% boards. You can find detailed information about the layout [here](layouts/60_ansi_tsangan_split_bs_rshift/ohshitgorillas/).

| Luminkey LX60 Copper Edition| KBDfans Tofu60 2.0 |
| :---: | :---: |
| ![Luminkey LX60 Copper Edition](layouts/60_ansi_tsangan_split_bs_rshift/ohshitgorillas/lx60.png) | ![Tofu60 2.0](layouts/60_ansi_tsangan_split_bs_rshift/ohshitgorillas/tofu60-2.png) |
| Green Anodized w/ Copper accent | E-Coating Black |
| CannonKeys British Racing Green Keycaps | Geekark Black-on-Black Keycaps |
| Invokeys Matcha Reserve Switches<br>Spacebar: Gateron Milky Yellow Pro | HMX Retro J Switches<br>Spacebar: HMX Heavy Tactile |
| Copper Plate (Geon 60He) | PC Plate |
| 45A O-Ring Mounted | Silicon Sock Mounted |
| Foamless | Foamless |

Photos by Discord user SolidBrain.

### Layout Philosophy & Features

My primary 60% layout is heavily customized for ergonomics and speed, especially for programming and daily use on macOS.

- **Caps Lock Layer:** The Caps Lock key serves a dual-function, providing lightning-fast access to a feature-rich function layer for navigation, media keys, and more. Mastering Caps Lock as a tap-hold key for extremely rapid access while eliminating misfires requires the full force of QMK's advanced timing features.
- **Home Row Modifiers:** Modifiers (Ctrl, Opt, Cmd, Shift) are on the home row keys using a tap-hold configuration for reduced hand movement.
- **Leader Key Sequences:** For quick access to applications and typing personal information.

For a deep dive into the implementation and philosophy, see the [60% Layout README](layouts/60_ansi_tsangan_split_bs_rshift/ohshitgorillas/README.md).

## Planck rev7 40%

I also have a Planck for a 40% ortholinear typing experience.

![Planck rev7](layouts/planck_1x2uR/ohshitgorillas/planck.jpg)

You can find the layout for it [here](layouts/planck_1x2uR/ohshitgorillas/) and a review [here](layouts/planck_1x2uR/ohshitgorillas/review.md).

## QMK Community Modules

I've written several community modules that can be easily added to your own QMK userspace. You can find them all [here](modules/ohshitgorillas/).

- **[xcase](https://github.com/ohshitgorillas/qmk-xcase):** A module for easily typing in `snake_case`, `camelCase`, `kebab-case`, or even with/custom/delimiters.
- **[spOngEmoCk](https://github.com/ohshitgorillas/spongemock):** A module that randomly capitalizes letters as you type lIkE iN thE spONgeBob mOckiNG mEmE.
- **[BadKeys](modules/ohshitgorillas/badkeys/README.md):** Train yourself against using certain keys by having your keyboard play a sound when you press them.

## Other Tools

- **[Autocorrect](autocorrect):** A custom autocorrect library with a personal dictionary. Unlike most autocorrect solutions that focus on misspelling, this one is focused instead on common mechanical typing errors—transposed letters, doubled characters, and other fat-finger mistakes.
