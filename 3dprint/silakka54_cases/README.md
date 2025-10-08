# Silakka54 Cases
For AliExpress Silakka54, i.e., where both MCU face up.
>! Check version of your PCB under the MCU.
>! Cases here support either v1.2 or v1.3

# TL;DR

## v1.2
The sandwich case of the v1.2 has the bottom attached with hexagonal spacers.

### One-Piece Case
- Requires only the insets and screws used in the Silakka54 sandwich case (4x Ø3 ?mm hex spacers and 4x ?mm M2 screws).
- STL and Cura profile files (for Ender S1 Plus) for the right side is included.
- For the left side, mirror the right part in Cura, and adjust `Z seam X` from `0.0` to `300`.
- Assembly: Push the hex spacers into the holes in the bottom, slide the MCU and TRRS in under their roofs (carefully, fragility exists), then screw PCB to hex. Add screws under, too, if you want.

## v1.3
The sandwich case of the v1.3 has the bottom attached with spacers soldered to the PCB.

### One-Piece Case
- Adjusted from the v1.2 one-piece case.
- Assembly: Slide the MCU and TRRS in under their roofs (carefully, fragility exists), then add screws from the bottom.

### Two-Piece Case
- Assembly: Screw PCB to bottom from below, fit corner switches in plate, fit plate on PCB, add remaining switches.



# Rant Format
    
The [Silakka54](https://squalius-cephalus.github.io/silakka54/) by [Squalius-cephalus](https://github.com/Squalius-cephalus)
is a sane defaults beginner-friendly split keyboard.
With its budget-friendlyness, generous number of keys and QMK and Vial support, its gotten well-deserved attention.
I bought one to try it out, and am happy to recommend it to people new to more ergo-boards.
Once I'm done with this case, I'll lend it to a programmer colleague who wants to try a split.

In the FR4 sandwich-case design, the RP2040 Zero MCU and TRRS connector are both bared. I think they deserve a bit of cover. 
As I recently acquired a used Ender 3 S1 Plus for 800 DKK, I printed the 
[Slim Silakka54 screwless case](https://www.printables.com/model/1248872-slim-silakka54-screwless-case) by Johnny5iv, 
a remix of the [the original](https://www.printables.com/model/1167880-silakka54-case) by Squalius.
I'm not really good at printing getting the bottom nice, with angles of the cover, and the cover taps breaking off. 
Aesthetically, I find the walls a bit thick.

So, I've tried my hand at 3d modeling a remix. It's one piece, the cover is less and with flat tops, and the walls are thinner. 
The v1.2 is almost from scratch, but for the PCB outline, that I coplied copied from the original `base.step`. For the v1.2, I imported the plate STL into TinkerCAD, exported as SVG, opened in Inkscape and exported as DXF R12, which I could import in Onshape.

Several on [r/ErgoMechKeyboards](https://www.reddit.com/r/ErgoMechKeyboards/) have recently made these neat "spacer cases" for their various boards. I think that's a neat idea, so I've included one here for the v1.3. Another Silakka54 case with such a spacer case is [this one](https://www.printables.com/model/1433122-silakka54-screwless-and-tenting-platform-carry-cas). It also includes a tenting platform!

## Design Files on Onshape
I'm on Linux with zero CAD experience.
I had issues getting [Autodesk-Fusion-360-for-Linux](https://github.com/cryinkfly/Autodesk-Fusion-360-for-Linux) running
and was then too impatient to learn FreeCAD, so I jumped on Onshape. I hope the workspace makes sense to navigate. The edit history may be... somewhat chaotic.

- [Public Onshape Document](https://cad.onshape.com/documents/518b03e72a2b4cf4840c6618/w/309783c02a42935e761f2106/e/88c88d6adf255d44b8f63fc2?renderMode=0&uiState=686eb00237959c2f0f319326)

## STL Files
<img src="bottoms.png" width="500"/>

I've added STL files for three version of the bottom (right only, for left mirror in slicer):
- Solid
- Chaotic honeycomb
- Net

I made the non-solid ones as my prints of the solid bottom kept turning unadhesing or wavy.
I haven't been crazy with the sound of some of the printed Corne cases I've dealt with,
so I also aimed for a bottom pattern that would have less of that plastic enclosedness.

See and rotate them on [Printables]().

## Slicing and Printing
On my Ender 3 S1 Plus with silicone spacers, xxx plate and 0.4 mm nozzle, I use the `right_ender3s1plus.curaprofile` Cura profile to slice, then print from an SD card using PLA.

The Z seam is set to avoid the fragiler beams of the MCU and TRRS covers by being mainly on the lower, outer corner of the MCU cover and on the outside of the TRRS cover.

With this profile and careful (noob) levelling, I've finally managed to print the solid bottomed cases properly.
