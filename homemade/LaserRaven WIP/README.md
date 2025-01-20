# Laser Raven
*Laser Corvus Corax. Designed with ![Ergogen](https://github.com/ergogen/ergogen)*

**A 32+6 trackpoint columnar unibody split designed with nordic languages in mind.**

- Lasers are hot. I'm laser cutting the case.
- Ravens are black, like ThinkPads, that have trackpoints.
- Ravens aren't the smallest of birds.
- Ravens are smart tool users. I bet they love lasers. And trackpoints.

![](images/kicad_3d_back.png)

## Trackpoint
I really like ThinkPads (X301, you hold my heart). Not least for their trackpoints. I love trackpoints. For my day-to-day computing, I need no other pointing device.

## 32 alpha keys
As a Dane writing frequent Danish and English, on my main layer, I want a 29 letter alphabet (ABC...WXYZ+ÆØÅ). I also want dot and comma. That's 31 keys. For symmetry, that makes 32 keys. The last is for tab.

## Pinky fans
I like a somewhat aggresive pinky stagger of 1u. I don't find it nice to reach further down than that, so I have no pinky keys under the home row.

I'm not good at hitting a key directly up from home with my pinky. On my [Laser Prosthetic](../LaserProsthetic/README.md), I have pinky clusters where I reach up and out a bit. That's fine, but requires a bit of a hand lift.

With the outer-most key on this board, I'm experimenting with how it'll feel to reach only out, but not up. I've arragned the keys in a fan with a radius the length of my pinky. This way, I hope to have three keys easily reachable with each pinky.

## Outer ring
To reach the 32 alpha keys, I need two extra keys somewhere, with no more forthe pinkies. I could add them on the far inside, but that's far from the home keys. I'm not using those keys much on my Laser Prothetic.

Instead, I've taken a page from the book of my 100 wpm collegue, who types without pinkies. Instead, they  use the ring fingers for those keys. Given the 1u staggered pinky fans, there's ample space for an outer ring finger key.

![](images/kle_qwerty.jpg)
*KLE sketch of keys for DK Qwerty. Dash (-) marks home row keys.*

## Thumb keys, mouse buttons and layers
I use 6 thumb keys because this is the maximum amount I find nice to reach.

Two thumb keys are for the trackpoint: One for left click (and dragging), one middle click (and scrolling). Right click is Shift + middle click.

I use six layers: Shift, Ctrl, Alt, Navigation, Numbers and Symbols. Four are on thumb keys, while the two least used are on pinkies (Alt and Numbers).

## Ergogen & KiCad
I have followed ![FlatFootFox's eminent guide to Ergogen](https://flatfootfox.com/ergogen-part1-units-points/). I use ![Ergogen](https://github.com/ergogen/ergogen) through the command line, on Fedora. Install by `sudo npm -g i ergogen`. From the board's `ergogen` directory, run `ergogen config.yaml`. From there, traces have to be drawn manually in Kicad.

I followed ![these steps](https://forum.kicad.info/t/how-to-add-fancy-graphics-to-your-pcb-tutorial/36138
) to add an graphics silkscreen in KiCad.

I forgot to include my Ergogen screw holes before routing. I imported the Ergogen-generated outline of them, positioned them manually referring to an untraced copy that included them, and added them to the Edge.Cuts layer.

## Components

### Board
- PCB. I made a quick comparison of JLCPCB and PCBWay, and the former gave me a far lower rate. I ordered the minimum of 5 PCBs, FR-4, 1.6mm, LeadFree HASL. With a new customer coupon, the cheapest 10-14 days shipping and taxes, it landed on 36.83 Euro.
- ![Holykeebs Trackpoint module](https://docs.holykeebs.com/guides/trackpoint-module/) kit, incl. black opaque shield, custom low headers and ![Sea Picro controller](https://joshajohnson.com/sea-picro/)
    - 112 USD for 2, free shipping, taxes not included.
- 38 Kaihl hotswap sockets
- 38 XYZ diodes

### Case
It's difficult to find 1,5 mm black acrylic for laser cutting. I've contacted some companies about PE-HD options, but maybe that's poisonous? ![1](https://e-plast.dk/shop/plastplader/ps/polystyren-plade-sort-mat-mat-1006mm-x-1406mm-x-1-5mm), ![2](https://www.lemu.dk/da/catalog/products/pehd-(pehd)-plade-(sort)-2000x1000x15mm/3437002245), ![3](https://www.wattoo.dk/pehd-pehd-plade-sort-2000x1000x1-5mm-3437002245)