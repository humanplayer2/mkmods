# Tokyo60: A HHKB layout board

[Documentation](https://github.com/JnyJny/tokyo60_keymap/tree/master/firmware).

Build and sold with qPBT Terminal keycaps and MMD Princess linear switches. More photos below.

I did a forcebreak mod between the two pieces of case, which removed an annoying pinging. I also did a basic tape mod.

<img src="images/angled.jpg" width="512"/>

## To flash and run VIA
- Download and setup QMK
- Plug in the board and to enter bootloader: Press `left shift + right shift + B`
- Run `qmk flash -kb tokyokeyboard/tokyo60 -km via`
- Open `usevia.app` in browser (Chromium).
  - Got _Received invalid protocol version from device_. [Per this comment](https://github.com/the-via/releases/issues/257), I accessed `chrome://device-log/` and saw `Failed to open '/dev/hidraw1': FILE_ERROR_ACCESS_DENIED`. Running `sudo chown $USER:$USER /dev/hidraw1` solved problem.

<img src="images/top.jpg" width="512"/>

<img src="images/side.jpg" width="512"/>

<img src="images/closeup.jpg" width="512"/>

<img src="images/kit.jpg" width="512"/>
