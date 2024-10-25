# ZUOYA GMK26

> ## Content
> [Out of the box](#introduction)  
> [Out of the box](#out-of-the-box)  
> [VIA](#via)  
> [QMK?](#qmk?)


## Introduction
🟠 TODO: Add some photos.

Split spacebar by default, can be replaced with big 2u spacebar, but there is not stablizer for it. 🟠 Does the plate allow a stabilizer? If it does, some of the top sticky-foam must be cut away.

## Out of the box
Stablizers are rattle-free. I hear no pings from the switches, neither when in place or when held to ear. The keycaps are dye-sub, with very clean legends everywhere.

Personally, I think the default sound profile is nice. Not the deepest, but not overly sharp. It's not quite.

## VIA

1. Download [ZUOYA_GMK26.json](ZUOYA_GMK26.json) from this repo.
    - It's a simplified, English-only version of that from
[the Chinese NAVER blog](https://blog.naver.com/PostView.naver?blogId=thrufunlife&logNo=223557922108&noTrackingCode=true). I removed the encoder toggle as you can't physically remove the encoder.
2. Open [usevia.app](http://usevia.app) in a Chromium-based browser.
3. Under`Settings`, activate `Show Design tab`.
4. Load the JSON file:
    - Go to the design tab.
    - Check that V2 definitions are disabled.
    - Drag-n-drop or `Load` the downloaded JSON file.
    - > **Optional**: Toggle `Split Backspace og Big Spacebar` to your liking. This can always be changed now under `Configure > Layouts`.
5. Go to the `Configure` tab, authorize and remap your makropad!
    - > [Keychron has a VIA introduction](https://www.keychron.com/blogs/archived/how-to-use-via-to-program-your-keyboard).



> ### VIA errors on Linux
> If you get errors in VIA reading
> - `NotAllowedError: Failed to open the device`, and
> - `Received invalid protocol version from device`, then:
> 1. Open a tab to `chrome://device-log/` and look for `Failed to open '/dev/hidraw1': FILE_ERROR_ACCESS_DENIED`, perhaps with another number than `1`.
> 2. In terminal, run `sudo chown $USER:$USER /dev/hidraw1` (with the right number).
> 3. Reload the VIA page and re-authorize the board.

## QMK?

The offcial ZUOYA Store on AliExpress sells this makropad stating that it supports **"QMK/VIA"**. It works with VIA, and that's of course super nice! I've contacted the store to see if I can get a hold of some QMK source code, because being able to flash a home-compiled QMK firmware would give me ~~satisfaction.~~ a sense of power. Honesty first.
