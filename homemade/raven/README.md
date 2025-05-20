# Raven38

> **A 32+6 trackpoint columnar aggressive stagger unibody split
with horizontal little finger cluster and fourth leech finger key designed with nordic languages in mind.**

- Designed with [Ergogen](https://github.com/ergogen/ergogen)
- [My QMK fork](https://github.com/humanplayer2/qmk_firmware) contains firmware, in the `humanplayer2` branch, under `keyboards/humanplayer2/raven/`.

*Revision 1 (wip). Pinkie fans moved inwards, no splay*
![](images/rev1_keycaps.jpg)

*Version 1: Far, splayed pinky fans*
![](images/v1_keycaps.jpg)

*Next steps:*
- V2: Ergogen+KiCad a PCB, design case.
- Document change from V1 to Rev. 1.
- V1: Add note that outlines needed to be closed manually in KiCad.

# Build Rationale and Notes

- Ravens are black, like ThinkPads, that have trackpoints.
- Ravens are smart tool users. They should love lasers---and trackpoints.
- Lasers are hot. I thought I'd laser cut the case. Now I have a 3D printer...

![](images/rev1_pcb_hack.jpg)
![](images/v1_kicad_3d_back.png)

## Trackpoint
I really like ThinkPads (X301, you hold my heart). Not least for their trackpoints. I love trackpoints. For my day-to-day computing, I need no other pointing device.

## 32 alpha keys
As a Dane writing frequent Danish and English, on my main layer, I want a 29 letter alphabet (ABC...WXYZ+ÆØÅ). I also want dot and comma. That's 31 keys. For symmetry, that makes 32 keys. Tab, you're in.

## Little finger fans / horizontal pinky clusters
I like a somewhat aggresive pinky stagger of 1u. I don't find it nice to reach further down than that, so I have no pinky keys under the home row.

Reaching straight up with my pinky is not something I enjoy. On my [Laser Prosthetic](../LaserProsthetic/README.md), I have pinky clusters where I reach up and out a bit. That's fine, but requires a bit of a hand lift.

With the outer-most key on this board, I'm experimenting with how it'll feel to reach only outwards. The pinky fan has a radius the length of my pinky.

## Outer ring
With 6 index, 3 middle, 3 ring, and 3 pinky keys, I need two extra keys somewhere to reach 32.

I could add them on the far inside, and reach in with my left index. I have tried those on my Laser Prothetic.

Instead, I've taken a page from the book of my 100 US wpm collegue, who types without pinkies. They use the ring fingers for those pinky keys instead. Given the 1u staggered pinky fans, there's ample space for an outer ring finger key.

![](images/v1_kle_qwerty.jpg)
*KLE sketch of keys for DK Qwerty. Dash (-) marks home row keys.*

## Thumb keys, mouse buttons and layers
I've added 6 thumb keys because this is the maximum amount I find nice to reach.

Two thumb keys are for the trackpoint: One for left click (and dragging), one middle click (and scrolling). Right click is Shift + middle click.

I use six layers: Shift, Ctrl, Alt, Navigation, Numbers and Symbols. Four are on thumb keys, while the two least used are on pinkies (Alt and Numbers).

## Ergogen & KiCad
I have followed ![FlatFootFox's eminent guide to Ergogen](https://flatfootfox.com/ergogen-part1-units-points/). I use ![Ergogen](https://github.com/ergogen/ergogen) through the command line, on Fedora. Install by `sudo npm -g i ergogen`. From the board's `ergogen` directory, run `ergogen config.yaml`. From there, traces have to be drawn manually in Kicad.

I followed ![these steps](https://forum.kicad.info/t/how-to-add-fancy-graphics-to-your-pcb-tutorial/36138) to add a graphics silkscreen in KiCad.

I forgot to include my Ergogen screw holes before routing. I imported the Ergogen-generated outline of them, positioned them manually referring to an untraced copy that included them, and added them to the Edge.Cuts layer.

## Competents

### PCB
 I made a quick comparison of JLCPCB and PCBWay, and the former gave me a far lower rate. I ordered the minimum of 5 PCBs, FR-4, 1.6mm, LeadFree HASL.
 - `36.83 Euro`  with the cheapest 10-14 days shipping, taxes, and a new customer coupon.

### Trackpoint and controller
[Holykeebs Trackpoint module](https://docs.holykeebs.com/guides/trackpoint-module/) kit, incl. black opaque shield, custom low headers and ![Sea Picro controller](https://joshajohnson.com/sea-picro/)
    - `112 USD` for 2, free shipping, taxes not included.

### Soldered components
- 38 Kaihl hotswap sockets. `3.62 USD` for 40.
- W1 1N4148 SOD-123 diodes, 38 pieces. `2.53 USD` for 100.
- 10x short profile header sockets (2.54mm, Ph3.5, female headers 12P), as I messed one up: `7.86 USD`.

### Case and Plate
- I had planned to laser-cut a case, but now I bought a 3D printer... TODO.