# Mechanical Keyboard Mods

Notes and photos of mechanical keyboards mods and builds.

## Handwired Builds
- [Laser Prosthetic: Trackpoint ergo laser-cut from acrylic and MDF](LaserProsthetic/README.md)
- [Frejas Hitbox: A gamepad with a case made of HAMA beads](FrejasHitbox/README.md)
- [Lite-Puter Footpanel: Light-controller rewired to run QMK](LitePuter/README.md)

## Mechanical Mods
- [Anne Pro 2: Hotswap mod using cheap rivets](AnnePro2/README.md)

## Builds
- [Tokyo60: Some notes on QMK/VIA](Tokyo60/README.md)

## Reviews
- [AKKO 3068B](AKKO_3068B/README.md)
- [MUCAI MK61-HEI](MUCAI-MK61/README.md)

## QMK on Fedora 40:
The pip install failed, so I use the Docker option:

1. Install: https://docs.docker.com/engine/install/fedora/
2. Run on start: https://docs.docker.com/engine/install/linux-postinstall/#configure-docker-to-start-on-boot-with-systemd
3. QMK: https://docs.qmk.fm/getting_started_docker

Symlinking keyboard directory into qmk_firmware/keyboards seems to not work, so:

rsync -r $HOME/mkmods/qmk_firmware/keyboards/humanplayer2 $HOME/qmk_firmware/keyboards

cd $HOME/qmk_firmware

To compile:
util/docker_build.sh humanplayer2/laser:focus7

To flash:
util/docker_build.sh humanplayer2/laser:focus7:flash

To make /dev/ttyACM0 writable, while QMK flashing waits for this with board in bootloader mode, run in other terminal:

sudo chmod a+rw /dev/ttyACM0

This does not keep until next.

