# Ordering PCBs from PCBWay: How-to and Review

I have been so fortunate to get two PCB orders totalling five designs (four PCB, one PCBA) sponsored by [PCBWay](https://www.pcbway.com/) (I paid shipping and VAT).

PCBWay reached out referencing a [/r/ErgoMech post](https://www.reddit.com/r/ErgoMechKeyboards/comments/1nhf08b/thinkpad_keycap_mx_stems/) I made, asking if they could support me. The sponsorship is on the condition that I write up an honest impression of my ordering process, which has been easy and good, except for the what I experience as a very involved process for credit card payment, cf. [my criticisms](#pcbway-criticism).

> [!TIP]
> If you do choose to use PCBWay and need to sign up, you can give me a 10$ discount coupon and receive 5$ yourself by using [this referral link](https://pcbway.com/g/3L2WNq).  
> Expired is the `ERGOGEN` discount code mentioned FlatFootFox's [part 5](https://flatfootfox.com/ergogen-part5-kicad-firmware-assembly/).

## Order as-is directly from production-ready files
Some boards have production-ready Gerber files available: e.g., for [Underset](https://github.com/humanplayer2/underset), `pcbs/underset_v1_production.zip` contains what you need.

If you want to order a directly, download the Gerber files archive, go to [PCBWay](https://www.pcbway.com/), log in, click _Quote now_ then _Upload Gerber files_, then _Upload Gerber files_ again, then `+Add Gerber files` and choose the `.zip`.

I made the following changes to the default settings:
- `Solder mask: Black`. As you prefer, of course :lips:
- `Surface finish: HASL lead free`: I don't want lead.
- `Remove product No.: Yes (extra+$ 1.5)`.

If you don't want assembly services, you can then just order, and you'll be send to a hopefully approving review, then shipping options. For my second production, I used the cheapest option (Global Direct Shipping), and it was surprisingly fast---production was completed on the 17th, and I picked up the order on the 24th.

Finally, payment, where I encountered some hindrance. Payment must be done by either bank transfer (ouch: 30$ fee) or credit card through Payoneer (3% fee). After choosing the Payoneer option, you have to send a message to the sales rep so they can send you a payment link (an automated solution is in the works, I'm told). See [criticisms](#pcbway-criticism) below.

### With assembly
I tried a set of PCBs produced with assembly, with just the diodes soldered on. The Underset `.zip` includes the needed files for that (but it still needs soldering of hotswap sockets, controller, TRRS).

If you want assembly, tick `Assembly Service` in the bottom, leave the `Turnkey` selection (unless you know otherwise) and leave the `Assembly side(s)` at `Top side` (unless you know otherwise for the board you are ordering).

> [!TIP]
> For Underset, you do not need to order both top and bottom side assembled PCBs: The diodes are placed so they interfere with neither hotswap sockets nor swithes no matter which side the diodes are on.

After that, you're send to review, where they'll contact you about specific components for the assembly, depending on what brands they have in stock. Diodes are quite standard, so I just aggreed to their suggestion, which was just a-okay.

Yeah. And then you wait a bit. Assembly takes quite some time longer. Personally, I'll order without assembly next time: I don't mind soldering the diodes. Maybe if I generated the PCB to also include Bill of Material information for also the hotswap sockets, or for boards with difficult components. But not just for diodes. But the process was nice, and PCBWay support was very supportive!

## Generate with Ergogen, then order
Maybe you want to generate the PCB yourself. Include hotswap socket info in the BOM; add a picture of your family to the silkscreen---maybe a dragon. Or move keys around, of course :grinning:

In that case, you should first get Ergogen up and running locally, have the Ergogen `.yaml` file for the board and footprints ready, etc. See e.g. [the Underset docs](https://github.com/humanplayer2/underset/) for short instructions, or see **FlatFootFox**'s excellent guide [_Let's Design A Keyboard With Ergogen v4_](https://flatfootfox.com/ergogen-introduction/) for a full introduction to Ergogen (see Part 5 especially).

Once you've generated the PCB files and are happy with how the `.kicad_pcb` looks in KiCad 8 PCB Editor, you can 
- either follow the steps in FlatFootFox's [Part 5](https://flatfootfox.com/ergogen-part5-kicad-firmware-assembly/) to generate Gerber files, 
- or you can install the [PCBWay Plugin for KiCad](https://www.pcbway.com/blog/News/PCBWay_Plug_In_for_KiCad_3ea6219c.html). This also generates BOM and position files for PCB with assembly (if encoded in the PCB), and opens and ordering page at PCBWay. Whether you finally intend to order from them or not, it's a very easy way to upload your PCB to a production service where another few clicks will have the PCB send through review which will both check it for you and give you an fixed price, without any commitment to you.

## PCB quality
As I've written on the [PCBWay review site](https://web.archive.org/save/https://pcbshopper.com/pcbway-reviews/), for my first order, where I payed shipping via PayPal:

> As a hobby enthusiast, I have produced three PCBs with PCBWay, using KiCad and the PCBWay plugin. One was with assembly. I found the ordering process using the plugin very easy, as it automatically generates and uploads Gerber and BOM files. Through the PCBWay reviews, I've received quick and guiding feedback both on some unfortunate physical design choices, and on selection of exact components for PCBA. For the orders, I have written back and forth with customer service many times; the communication is quick and clear, which I really appreciate.
>
> The PCBs I have received have been really nice! Sharp cuts, pretty through-holes, good colors, clean silkscreen and all electronics that worked as designed. I've soldered on to them by hand where some socket components have been physically stressed after, and I have not had any issues with pads breaking off. So only thumbs up from me!

## PCBWay criticism
Okay, points of criticism. I have no qualms with the PCBs or the assembly. The minor process issues I've faced are:
- _**Number of designs in panel**_.  
    Underset has really small subboard for the TRRS. With the first round of PCBs, it wasn't noticed and I was only charged for one design in the panel. The second time, the reviewer noticed there were two panels, so the production became more expensive. Is this fair? I looked it up, and it seems like pretty standard practise. But I got lucky the first time! So due to a bias that must have a name, the second time I got annoyed because I had to pay more (not really: sponsored). So I guess that one is kinda on me :grinning_face_with_sweat: (I ended up adding a redundant trace from the subboard to the main board to collapse it to one design in panel). 
- _**PCB issue spotted in production**_.  
    For my first order, the reviewer missed an issue discovered in production. Production then waited for me to accept their suggested change. The suggested change was good, and I'm glad they waited. So this more of an observation that the initial reviews are not necessarily perfect. But they are fast and helpful.
- _**Payment**_.  
    The [Help Center article on Payment Process](https://web.archive.org/web/20260112112439/https://www.pcbway.com/helpcenter/paymentprocess/Which_payment_methods_can_I_use_on_PCBWay_.html) states that you can pay by credit card.
    
    Currently, the only way of paying by credit card is via Payoneer, through personal contact with a PCBWay sales representative. It took me **sixty hours** to finalize my payment. Granted, some of that was because I had to re-request a payment request from PCBWay to Payoneer as the first borked due to wrong card details. Personal contact across unaligned timezones does not speed things up.
    
    When PayPal was an option in October of 2025, I was annoyed some by the fee, and a lot by not being able to pay VAT on the site. Now you can pay VAT. Living in the EU, in Denmark, that's important to me, as I else either have to pay for an expensive shipping company that'll take case of it for me, or risk a large extra fee when using more standard shipping.
    
    I've talked to my contact sponsorship contact about Payoneer, and they tell me that on online payment is planned for the future. They did add the option to pay VAT, so it seems they are focused on improving the ordering procedure :smile:
    
Yeah, so that's about it. Apart from payment cumbersomeness, my ordering processes have been really good, with helpful interactions with customer service, fast reviewing and spot-on PCBs. So: Thanks, PCBWay!
