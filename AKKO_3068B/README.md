# AKKO Blue on White 3068B Plus ISO

AKKO was kind to send me a box containing their not-new 3086B 65% board for review, together with their tactile 55gf Creamy Purple Pro and their linear 40gf Rosewood switches.

<img src="images/board_top.jpg" width="512"/>

Everything here is of course just my opinion, so you can prefix every sentence with "IMHO" if you like.

There are some things I don't care much about myself, and therefore know little about. About these, I'll stay quite. These include RGB, stability of bluetooth and 2.4G connections, battery life.

For box content, the extra UK/DE/FI/SE/NO and vanity keycaps, further specs, etc., see the [keyboard product page](https://akkogear.eu/products/blue-on-white-3068b-plus-iso-mechanical-keyboard?_pos=2&_sid=636572fe2&_ss=r).

## Case
For a plastic case board, it's nicely heavy, weighing in at 645g on my kitchen weight. It's stiff, and doesn't feel cheap. I think for casual user of mechanical keyboards, the build quality will be very satisfying. The case is compact, and not with a design I'd be annoyed at having around.

<img src="images/board_left.jpg" width="512"/>

<img src="images/board_right.jpg" width="512"/>

<img src="images/board_profile.jpg" width="512"/>

To open the case, you need to pry off the top, then remove screw located under Tab, I-O, and Return. The the plate-and-pcb assembly lifts out, ready for e.g. a Tempest tape-mod.

## Inside
Opening the case reveals a ~3mm low-density foam sheet, and the 1800mAh battery. I measured the steel plate to be 1.5mm thick, the thickest that Cherry MX switches will fit. That's nice as it ensures that the switches sit tightly.

<img src="images/opened.jpg" width="512"/>

There's not much empty space in the case.

I was hoping to learn something about the MCU model, but no luck. It just reads "Akko". Fair enough, but it voids my hopes that I could maybe port the board to QMK/SonixQMK. At least it makes it tricky, since I don't know what the MCU model is... I'd like to port QMK because QMK is awesome, and the AKKO software for this board is more limited. I'll get back to that.

<img src="images/mcu.jpg" width="512"/>

## Out-of-the-box typing experience
The board came with 45g Akko CS Jelly Pink linear switches. I'm a tactile fan myself, so I won't say much about these. They feel finely smooth, and notice no scratchyness. I'm not too crazy about their sound. They are a bit light in sound for me, and on the upstroke, they sound clattery. I could type on this for long without getting straight-up annoyed, but it'd not be pleasing either. I wouldn't be comfortable using it at the office.

I'm impressed by the stabilizers and their lubrication. They don't require clipping, and can be taken out without opening the board. Only the left side of the spacebar had any kind of rattle, and I don't think the others are overlubed. The stabilizers can be removed without opening the board, so I reworked a bit of the lube from the right side of the spacebar stabilizer to the left, and that largely solved the rattling. I then added dash of dielectric grease again only to the left side of the spacebar, and now I'm satisfied with all the stabilizers.

The keycaps are Cherry-profile, and have a bit of texture. I'm used to Cherry, and I like the texture.

## Keycaps
The keycaps are double-shot PBT, and I measure them to 1.2mm, so not thin, and not the thickest.

I want to praise the keycaps for their regional support options, but also criticize them a bit for their legends.

First, the praise: They support Danish, not just Nordic.

This is Nordic:

<img src="images/nordic.jpg" width="512"/>

This is Danish:

<img src="images/danish.jpg" width="512"/>

See the difference?

For context, here's a rant: I'm Danish. We have ÆØÅ in our alphabet. The Norwegians have the same, but flip Æ and Ø in their layout. The Finnish and Swedes also have ÆØÅ, but write them ÄÖÅ. Now, somebody got the great idea that they could lump all three languages into a Nordic keyboard layout, where the Danish Æ key could feature the legends Æ from Danish, Ø from Norwegian and Ö from Finnish/Swedish, while the Danish Ø key could have legends ØÆÄ. It's atrocious. Now look at the key to the right of backspace. WTF goes on there? If you go exploring further, find pipe---both of them. If you don't use accents and pipe/backspace often, how annoying is it that? Nordic layout is an abomination, a slap in the face, unforgivable. Keychron, I'm looking at you.

AKKO, thank you for not using the Nordic layout, but supporting Danish, Norwegian and Finnish=Swedish! For me, this makes a huge difference. This is definitely a thing I'll mention when pointing other Danes to keyboards brands.

<img src="images/keycaps_æøå.jpg" width="512"/>

Now, to the criticism: The legends are not the most consistent that I've seen. Individually, they are all clean, clear and precise, but they are not fully consistent. I think this is most noticable one the Danish keys, when compared to the others, where Ø is thinner than the other alphas, and E, Æ and Å are wider. The text on some of the modifiers is also a bit inconsistent in width (on the left Win key, "in" is narrower that other mod text).

<img src="images/keycaps_mods.jpg" width="512"/>

All-in-all, given the choice between a nicer, Nordic layout keycap set or this Danish one with slight inconsistencies, I'd most assuredly go for this one. I'd also be satisfied with the legends given the overall price of the board.

## Creamy Purple Pro and Rosewood switches
Uhh, the sound of these Rosewood linears is quite nice! Very much an improvement. Much softer, rounder, and also quiter than the Jelly Pinks. No clattering. With these, I think the board could be used in the office where even my most noise sensitive colleague would have to agree that the board makes an "objectively" acceptable level of noise. I'd be glad to hear a colleague tap away!

The Cream Purple Pros: I think these are about as loud as the Jelly Pinks, but cleaner in their sound profile. They don't have that clattering. The sound is well-defined, clean and clear on both up- and downstroke. Not super deep, but rounded. I'd be happy with this sound.

Ok, thinking about the tactility, I just had to throw in a few Gazzew U4Ts (spring swapped to 55gf), which are what I normally use. The Cream Purple Pros feel like they have a slightly smaller tactile bump, but its position feels the same as the U4Ts. Sound-wise, the U4Ts sound a bit louder and deeper to me. I think I could be happy with these Cream Purples, and will try them in my main board.

## Software and Firmware
Board and firmware are not made for remapping and layering enthusiasts. I'm a QMK + thumbkeys + lots-of-layers person, so I'm biased towards that here.

In the AKKO software, you can define four layers, which you can toggle between in the Cloud driver software (not avaliable for Linux, so ... yay for me). I havn't figured out if you can switch between these layers on the keyboard. Some online results suggest Fn+F9/F10, but this board doesn't have F-keys. There are however also two Fn-layers that you can cycle through using Fn+Right_Alt (that could have been mentioned in the manual).

The four layers are fully free except for the default Fn, so there you can play. But, you need to toggle them. You can't hold a key and momentarily activate one of them. But the Fn-layers allow that. On the first Fn-layer some keys have locked functions for F1-F12, media keys, RGB, etc., but the second Fn-layer is fully free! I think this is really nice. It means you can remap CapsLock to activate a full layer with macros and what not, and that I really appreciate.

More advanced things---like tap-hold etc.---are not in the picture.

The documentation is somewhat lacking. I'd have appreciated a proper overview of all the functions of the board, including layer-switching. Especially using it without access to the AKKO software could be problematic, if you by accident activate something that you can't get out of. I managed to do something so the arrow keys turned to WASD, and even with the software, I couldn't figure out how to undo that, safe for resetting the entire board... So, it's nice with on-board memory, but also a bit of a gamble given the lack of documentation.

## Conclusions
All-in-all, I would say this is a very reasonable starting point for someone new to the mechanical keyboard hobby, or the user that casually wants a mechanical keyboard for work.

Even if the default switches are not really my taste,  you get a reasonable sound out-of-the-box, and can play with switches easily given that it's hotswap. With other switches from AKKO, I think it's totally office-friendly. If you want to play around with remapping, I think you'd be better off running an OS level remapper or another board.

One thing I think most users from the North will end up loving are the specialized keycaps for their language. You can't go wrong with that choice, even if the legends are not at the premium level.

With everything in mind, I can see myself pointing friends or colleagues towards this board, if they aren't remapping powerusers. The software does supports more functions than I think most of my friends and colleagues would use. And the keycaps support Danish!
