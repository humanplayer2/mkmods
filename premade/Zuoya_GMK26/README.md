# ZUOYA GMK26

> ## Content
> [Introduction](#introduction)  
> [Out of the box](#out-of-the-box)  
> [VIA](#via)  
> [QMK?](#qmk?)
> [Photos](#photos)


## Introduction


![0](premade/Zuoya_GMK26/images/0.jpg)

More photos in the bottom.

Split spacebar by default, can be replaced with big 2u spacebar, but there is not stablizer for it. 🟠 Does the plate allow a stabilizer? If it does, some of the top sticky-foam must be cut away.

## Out of the box
Stablizers are rattle-free. I hear no pings from the switches, neither when in place or when held to ear. The keycaps are dye-sub, with very clean legends everywhere.

Personally, I think the default sound profile is nice. Not the deepest, but not overly sharp. It's not quite.

## VIA
The macropad works with VIA, and that's nice.

1. Download the JSON file [ZUOYA_GMK26_20240517.json](ZUOYA_GMK26_20240517.json) from this repo. It took over a month, but ZUOYA finally send it to me. 
    - 🟠 TODO: fix [ZUOYA_GMK26.json](ZUOYA_GMK26.json), my simplified, English-only version of the json from [the Korean NAVER blog](https://blog.naver.com/PostView.naver?blogId=thrufunlife&logNo=223557922108&noTrackingCode=true). I removed the encoder toggle as you can't physically remove the encoder, but remove the wrong option -- facepalm.
2. Open [usevia.app](http://usevia.app) in a Chromium-based browser.
3. Under`Settings`, activate `Show Design tab`.
4. Load the JSON file:
    - Go to the design tab.
    - Check that V2 definitions are disabled.
    - Drag-n-drop or `Load` the downloaded JSON file.
    - > **Optional**: Toggle `Split Backspace og Big Spacebar` to your liking. This can always be changed under `Configure > Layouts`.
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

The offcial ZUOYA Store on AliExpress sells this macropad stating that it supports **"QMK/VIA"**. I've contacted the store to see if I can get a hold of some QMK source code, because being able to flash a home-compiled QMK firmware would give me ~~satisfaction.~~ a sense of power. Honesty first.

[u/ArgentStonecutter](https://www.reddit.com/user/ArgentStonecutter/) suggested to test whether the pad is running real QMK underneath (or some alternative firmwware that can be interface with VIA). [Their suggested test](https://www.reddit.com/r/BudgetKeebs/comments/1gd85lo/comment/lu0u5hz/) is to check whether tap-hold keys are supported. Gladly, they are: through `Special > Any`, I assigned a key `LT(1, KC_BSPC)`. I send `Backspace` when tapped, and activated `Layer 1` when held. This doesn't prove that the pad runs QMK underneath of course, but it fails to prove that it doesn't.

If it does run QMK, Zuoya should release the source code [to not violate the license as they seemingly are already](https://github.com/qmk/qmk_firmware/issues/24085).

## Photos

![0](premade/Zuoya_GMK26/images/0.jpg)

![0](premade/Zuoya_GMK26/images/1.jpg)

![0](premade/Zuoya_GMK26/images/2.jpg)

![0](premade/Zuoya_GMK26/images/3.jpg)

![0](premade/Zuoya_GMK26/images/4.jpg)

![0](premade/Zuoya_GMK26/images/5.jpg)

![0](premade/Zuoya_GMK26/images/6.jpg)

![0](premade/Zuoya_GMK26/images/7.jpg)

![0](premade/Zuoya_GMK26/images/8.jpg)

![0](premade/Zuoya_GMK26/images/9.jpg)

![0](premade/Zuoya_GMK26/images/10.jpg)

![0](premade/Zuoya_GMK26/images/11.jpg)

![0](premade/Zuoya_GMK26/images/12.jpg)

![0](premade/Zuoya_GMK26/images/13.jpg)

![0](premade/Zuoya_GMK26/images/14.jpg)

![0](premade/Zuoya_GMK26/images/15.jpg)

![0](premade/Zuoya_GMK26/images/16.jpg)

![0](premade/Zuoya_GMK26/images/17.jpg)

![0](premade/Zuoya_GMK26/images/18.jpg)
