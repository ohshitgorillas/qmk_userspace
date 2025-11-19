# Planck rev7 Ortholinear 40% Keyboard: A Review

This review is incomplete. Don't read it yet.

I used the Planck keyboard for three weeks. Here are my unfiltered thoughts.

## Why would you do this to yourself? What's the point?

I got these questions a lot in various forms. And they are fair, to be honest. I genuinely frequently looked down at the Planck and asked myself the very same questions.

Some of you are already deep into this hobby and already use keyboards that most people would consider unusable abominations. You already get it. Those who aren't/don't... this review is for you.

There *are* reasons, but to understand them, we first need to start thinking about keyboards a bit differently. Let's begin by stepping down to 60% and slaying a sacred cow: the arrow keys.

### Fuck Arrow Keys
That's right, I said it. Go ahead: gasp, boo, hiss, clutch your fucking pearls.

To be clear, this isn't about *not using* arrow keys. Everyone needs them. What you don't need are *dedicated* arrow keys.

Many of you are sitting in front of a standard full-size or TKL keyboard right now. These are very straightforward: if you want F5, you reach up and press the F5 key; if you want Print Screen, you reach over and press the Print Screen key. If you want the cursor to move up a line, you reach over and press the ↑ key. Easy peasy.

Here's a new way of thinking about this, though: all that reaching around the keyboard for different keys isn't just inefficient, it's poor ergonomics. What if the most critical functions were always right under your fingers on the home row?

Stop reaching and start chording.

This isn't groundbreaking: cut, copy, and paste are indispensable features that have never had dedicated keys on any standardized modern layout. You don't reach across the keyboard for a key, you *chord* Ctrl (or Cmd) + X, C, or V. Your fingers never leave the 40% portion of the keyboard. I'm just taking that same logic and applying it to the arrow keys.

Take a look at your Caps Lock key: it's a useless little bitch of a key taking up prime home row real estate. With the magic of programmable mechanical keyboards, we can transform it into a key that opens up a layer with things like Enter, Backspace, Delete, and arrow keys all within easy reach of home row. Yes, it takes a little elbow grease to get there. Yes, it takes some retraining of your muscle memory... but for serious typists, the payoff can be significant. And fun to configure!

The takeaway: ditching the "one key, one function" paradigm for the "chording and layering" paradigm can lead to gains in efficiency, speed, and ergonomics for those willing to learn.

### The Keyboard Dark Arts
I'm a 60% user at heart. That's my sweet spot. The thought of using anything smaller as a daily driver is extremely unappealing: I write a fair amount of code, and I need easy access to numbers and symbols.

So why the fuck did I buy a 40% keyboard? An ortholinear one, no less?

I'd hit a point of diminishing returns with my configuration. My setup was good, but I knew it could be better. I wanted more, but I had also reached the limits of my knowledge and capacity with the Vial software.

To get to the next level, I needed to go back to school. I saw the Planck as a ticket out of my comfort zone: a masterclass in constraint-driven design; a rich tapestry of flexibility. By stripping away so many keys and adding thumb keys to (somewhat) compesnate, the Planck forces you to fundamentally reconsider the layout. Where does Enter go? Backspace? Where's the fucking right Shift? How do you remember where all the symbols are‽

There are no easy answers, no one-size-fits-all solution. Not even close. The only way is a descent into the keyboard dark arts: the world of advanced QMK programming. This isn't just remapping keys, it's an entire programming language for your keyboard. We're talking tap-hold timing intricacies that let home row keys double as fast-access modifiers, leader sequences that turn your keyboard into a command center, custom macros that automate repetitive tasks, and layering schemes so complex they'd make an Inception architect's head spin. Things no sane person using a standard layout would ever want or need. The result is a layout that is custom-fitted like leather to each typist.

It's that knowledge I was after. The Planck wasn't just a keyboard: it was an internship, a trial by fire in these dark arts. A vision quest.

*Aso*, this brings us to the crux of my reasoning for buying the Planck: sometimes you have to break something so that you can build it back better and stronger. I knew going in that this would be painful. I knew I'd hate it. But to truly master the 60%, I felt needed a keyboard that would force me to rethink the basics and teach me the the art of QMK.

And that's exactly what the Planck did.

## The Review Part of the Review
Look, I'm not going to reinvent the wheel here talking about the Planck's build quality—plenty of people have already beaten that horse to death. But since you're here, you get my takes anyway.

The build quality is aggressively meh... but so is the price, so I wasn't expecting much to begin with. The sound profile out of the box is, to put it politely, quite bad: hollow, metallic, and almost clangy. The foams helped considerably, but we're still a far cry from "good". 

One gripe I will bring up is that the board has "eaten" a fair number of switches, meaning they never came off the plate in one piece. They were in so tight that they pulled apart rather than just coming loose. I've never had that happen before with any of my keyboards and it was genuinely frustrating. Really not a fan of that bullshit.

I tried both the POM and steel plates before settling on BSUN Maple Sugar switches on the steel plate.

## The Good Stuff
Let's cover what I really liked about the Planck. It wasn't all frustrations and typos.

### Thumb Keys Are the Light and the Way
Seriously, having so many keys for my thumbs instead of one giant spacebar is fucking *brilliant*. I love it.

I put a 2U spacebar on the right, since I almost exclusively use my right thumb. It was the perfect size—no more, no less than I needed. (My brief, disastrous experiment with a 1U spacebar proved that.)

Anticipating a steep learning curve with a fuckton of errors, I put Backspace and Delete as left-handed thumb keys. And it was fucking *glorious*! Hands down my single favorite feature of the Planck.

Fuck a giant spacebar, why isn't this standard? And why is it so hard to find a good 60% keyboard with split spacebar support?

### QMK is the Shit
Vial is good, but getting my hands dirty with QMK was where the real magic happened. This is the heart of the "dark keyboard arts" I was chasing.

If Vial is a Honda Civic—reliable, practical, gets the job done—then QMK is a stripped-down Formula 1 car: insanely powerful, infinitely customizable, but demanding serious skill to master. If Vial is a Swiss Army knife, QMK is a fully-equipped machine shop where you can forge any tool you need... assuming you know how to operate a lathe.

I was resistant at first, sticking to the QMK Configurator and avoiding the C code. That was a mistake. Once I dove in, I was hooked. The result is my [QMK userspace repository](https://github.com/ohshitgorillas/qmk_userspace), containing all my code, keymaps, and even a few community module contributions.

Let's take my [implementation of xcase](https://github.com/ohshitgorillas/qmk-xcase) as an example: say I need to type an obnoxiously long file path. I press the Leader key, then `X`, `C`, `/` and voila! All/of/my/spaces/turn/into/slashes. This is just a taste of what's possible with QMK.

This experience also cemented a new rule for me: no more non-QMK keyboards. I was seriously considering a Neo60 Cu until I realized I couldn't load it with QMK. That's a dealbreaker now. Having tasted the raw power of what a keyboard *can* be, I can't go back.

The only downside is: QMK doesn't support wireless, forcing manufacturers to choose. For a business, the decision is simple—wireless sells more boards than QMK support. While I personally am perfectly content to sacrifice wireless functionality to get my hands dirty with C code, I am obviously in the minority there. As a one-man business, I can respect many manufacturer's decisions to go with wireless; as an enthusiast, it's frustrating to now be locked out of so much of the market.

I know the odds are slim, but I hope to see a future where QMK and wireless can finally coexist.

### Comically Small
Finally, this thing is hilariously small. I have a fairly large desk with ample space for a full-sized board, so this thing just looks completely ridiculous in my setup. It makes my 60% boards feel like battleships. It's only twice the size of my mouse.

This translates to portability. Tossing it in a bag is an afterthought, and while I never took it anywhere, it's the perfect coffee shop or travel board. You can have a decent typing experience on the go without lugging around a 15-pound block of aluminum and copper.

But for a dedicated ortho user, this portability is more than just a convenience; it's a necessity. Your brain can store multiple keyboard layouts, but you can only have one proficiently loaded into RAM at a time. You can't just seamlessly switch from ortho to staggered—it takes time and a storm of frustrating typos to readjust your muscle memory. For anyone fully committed to the ortho lifestyle, being able to bring your board with you isn't a luxury, it's a necessity.

## The Bad Stuff

Here are the things about using the Planck that drove me crazy.

### I had to commit to being a shitty typist for a while
- adapting to the ortho layout is not easy. the bottom row is the worst, by far. everything is half a space off from where you expect it, meaning at first you're hitting two keys every time you go for one. it really fucvking sucvked!
- I never fully got used to the layout, even by the time I had learned what I needed and switched back to my 60s. with only words on monkeytype I could do about 110 wpm by the end, but adding punctuation and numbers dropped me down to a little more than half that.

- **The mental overhead is exhausting.** 
- 
- Remembering where I put the ampersand or the caret was a constant cognitive load. It broke my flow when coding or writing.
- switching back to 60s where I could type numbers at will without that mental load was seriously freeing and made me realize how much more mental effort it required to type with that thing.

- **It feels like a cheap toy.** Coming from a premium aluminum and copper board like the LX60, the Planck feels... well, it feels like a cheap piece of shit. It's light, which is good for travel, but it just feels flimsy as hell.

## So, What Did I Learn?
This whole experiment was about pushing my boundaries and seeing what was on the other side. Here's what I'm taking with me:
- **Home Row Mods are the shit.** This is a revelation. Having modifiers on the home row is a massive efficiency boost, and I'm never going back.
- **Mastering dual-key timing is a superpower.** I finally nailed the timing for using Caps Lock as a tap-hold layer key, something I could never get right in Vial. It took diving deep into QMK's advanced timing features, but now it's flawless. I can have my layer and my Caps Lock too.
- **MT3 profile is legit.** It's comfortable as hell and the deep scoops feel amazing. I'm a convert.
- **ABS keycaps can still fuck off.** Yeah, they shine. PBT for life.
- **60% is my home.** This experiment solidified it for me. I need my number row and a layout that doesn't make me feel like I'm solving a puzzle every time I need to type a fucking exclamation point. The Planck was a fun, educational, and occasionally infuriating detour, but I'm glad to be back to a real keyboard.
type 2 fun
