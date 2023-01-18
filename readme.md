# Quantum Mechanical Keyboard Firmware

## Keychron Q2 ANSI KNOB Firmware Changelog

### Added

- [QMK-2] Implemented ability to change RGB value and swap songs with volume knob rotation
- [QMK-4] Allow two rotations CCW with pressed knob to play song from the start of the previous song
- [QMK-5] Add support for fn1 press and rotations
- [QMK-6] Add Caps Word functionality
- [QMK-9] Support for changing monitor brightness
- [QMK-8] RGB functionality, different RGB in different states
- [QMK-11] Moved some software shortcuts to hardware

### Changed

- [QMK-1] Changed default keymap
- [QMK-2] Faster volume steps
- [QMK-3] Disable processing volume up/down when knob is held
- [QMK-7] Cleaner custom keypress functionality
- [QMK-10] Change caps word so it doesn't turn off by itself

### Fixed

- [FIX/QMK-5] Added back FN1 functionality

### Future development plans

- !! RGB Is currently not working as expected - caps lock preset doesn't get correct brightness
- ! RGB preset - gradient from almost-caps-lock at the bottom to default at the top
- RGB preset - animated with only specified colors
- RGB reacting to changing Hue/Saturation
- RGB preset on layers
- RGB presets
- Custom RGB animations
- Remapping most of the useful shortcuts used in Power Toys -> key overrides
- Caps lock should change the RGB of the whole board to one of presets (red)
- Tap dance - double tap knob (maybe)
- knob acceleration

---

[![Current Version](https://img.shields.io/github/tag/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/tags)
[![Discord](https://img.shields.io/discord/440868230475677696.svg)](https://discord.gg/Uq7gcHh)
[![Docs Status](https://img.shields.io/badge/docs-ready-orange.svg)](https://docs.qmk.fm)
[![GitHub contributors](https://img.shields.io/github/contributors/qmk/qmk_firmware.svg)](https://github.com/qmk/qmk_firmware/pulse/monthly)
[![GitHub forks](https://img.shields.io/github/forks/qmk/qmk_firmware.svg?style=social&label=Fork)](https://github.com/qmk/qmk_firmware/)

This is a keyboard firmware based on the [tmk\_keyboard firmware](https://github.com/tmk/tmk_keyboard) with some useful features for Atmel AVR and ARM controllers, and more specifically, the [OLKB product line](https://olkb.com), the [ErgoDox EZ](https://ergodox-ez.com) keyboard, and the [Clueboard product line](https://clueboard.co).

## Documentation

- [See the official documentation on docs.qmk.fm](https://docs.qmk.fm)

The docs are powered by [Docsify](https://docsify.js.org/) and hosted on [GitHub](/docs/). They are also viewable offline; see [Previewing the Documentation](https://docs.qmk.fm/#/contributing?id=previewing-the-documentation) for more details.

You can request changes by making a fork and opening a [pull request](https://github.com/qmk/qmk_firmware/pulls), or by clicking the "Edit this page" link at the bottom of any page.

## Supported Keyboards

- [Planck](/keyboards/planck/)
- [Preonic](/keyboards/preonic/)
- [ErgoDox EZ](/keyboards/ergodox_ez/)
- [Clueboard](/keyboards/clueboard/)
- [Cluepad](/keyboards/clueboard/17/)
- [Atreus](/keyboards/atreus/)

The project also includes community support for [lots of other keyboards](/keyboards/).

## Maintainers

QMK is developed and maintained by Jack Humbert of OLKB with contributions from the community, and of course, [Hasu](https://github.com/tmk). The OLKB product firmwares are maintained by [Jack Humbert](https://github.com/jackhumbert), the Ergodox EZ by [ZSA Technology Labs](https://github.com/zsa), the Clueboard by [Zach White](https://github.com/skullydazed), and the Atreus by [Phil Hagelberg](https://github.com/technomancy).

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
