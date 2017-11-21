# Flexible PCB
Milling a flexible PCB is similar to milling a regular PCB, but requires much more precision.  I tried this more than a year ago, and was successful with a small PCB.  This is what I remember from the process.
<!-- (Noah Coleman, Nov. 12, 2017) -->

## Material
Adafruit sells flexible polymide [here](https://www.adafruit.com/product/1894).  It can also be found on [Amazon](https://www.amazon.com/Pyralux-Laminate-Flexible-Circuits-Shielding/dp/B076C1JW3S/ref=sr_1_1_sspa?ie=UTF8&qid=1511295016&sr=8-1-spons&keywords=copper+kapton&psc=1) and other places.  The Adafruit stuff has a 32um copper layer backed with 25um(1mil) polymide layer.  You read that right, the copper we're going to mill away is thicker than the substrate it is attached to.  If you get the stuff from Amazon, it likely has a thicker polymide layer, meaning that it will be _much_ easier to mill without going all the way through (it's still pretty finicky, though).

## Prepping the Material
Because the material is so flexible, it's impossible to get it to lay flat with tape, so we can't just tape it to the spoil board like we would a chunk of FR-1.  The way that has worked best for me (so far) is to use Elmer's glue stick to adhere the Pyralux _firmly_ to a piece of sacrificial material, and then tape that material to the spoilboard just as with the FR-1.  When I did it, I used a piece of 1/4" thick acrylic, but any similarly rigid material would work.  Cut the sacrificial board and Pyralux to size (4" x 5") and adhere them together.  Measure the thickness of this copper-clad sandwich with calipers and write that figure down--you'll need it later.
```
   ______________
  /             /
 /             //    Pyralux
/_____________//
/#############/_     Elmer's glue
  /            //
 /            //     Sacrificial Material
[============]/_    
 /_/ /_/ /_/   /|    Tape
 /            //
||||||||||||||/      Othermill Spoilboard
```
Once the measurements are taken, adhere the sacrificial material to the spoil board with tape just as with a regular FR-1 blank.

_**Note:**_ Because we are dealing with very tight tolerances, it may be beneficial to [face](https://www.youtube.com/watch?v=HW4EN2LYG6E) the top of your sacrificial material _before_ gluing the Pyralux to it.  This will ensure that the top of the material is parallel with the mill and give you a nice, flat surface to glue to.

## Prepping the File
In Otherplan, put the thickness of the flexible PCB film into the z (thickness) measurement for the material.  Then put the thickness of the sacrificial board in the z measurement for material positioning.  This will allow you to cut through the PCB material without going too far into the board beneath.
Alternatively, if you are using the Bantam Tools software, you can use the material thickness probing feature to get a precise measurement of your material.  Put the thickness of the Pyralux in the z (thickness) material measurement, as above.  The probing will determine how high the material is off of the bed.  This is done electronically, so you must [create an electrical connection](https://support.bantamtools.com/hc/en-us/articles/115001829134-Installing-and-Using-the-PCB-Probing-System) between the spoil board and the top of your copper-clad.  Once this is done, In the BitBreaker menu, select "Probe Material Thickness..."  The bit will probe your material and Bantam Tools will ask you if you want to keep the measurement.  

_**CAUTION:** If you just put the thickness of your PCB sandwich as the thickness of the material, you will damage the bit (and probably your PCB) when you go to mill the holes and outline.  Otherplan/Bantam Tools uses the material thickness to create the hole and outline tool paths.  This means that when it tries to cut the holes and outline, it will by default try to cut completely through the PCB sandwich, including your sacrificial material!  If you go this route (don't), do not cut holes or outlines._

## Cutting the Flexible PCB
Once the material is set up, you just need to tweak a few settings and you're ready to go.  When your file is loaded, go to the _Advanced Settings_ section at the bottom of your file settings window.  Change the _Trace Depth_ to `0.04mm`.  You may also want to change the trace clearance to remove more than the minimum amount of copper.  This will make soldering easier as well as reduce the likelihood of accidental shorts as the circuit is flexed.  

When I was experimenting with this, I wound up running the cut several times, lowering the toolpaths by `0.01mm` or `0.02mm` at a time until I had _just_ cut through the copper.

## Removal
Use a scraper to get the cut PCB off of the sacrificial board.  The Elmer's glue will come off with some water or isopropyl alcohol.

## Final Thoughts
- Precision is key!  There is very little margin of error (the copper is thicker than the substrate, I mean, come on!) so measurements should be as accurate as possible.
- Along the same lines as the above, there should be no bubbles, motes of dust, or other variations in the height of the Pyralux.
- The sacrificial material may need to be faced to ensure it is flat and parallel to the mill.
- Flexible PCBs work best for surface-mount (SMD) parts.  Through holes components will work, but where the pins go through the polymide is a huge mechanical strain point.
- This is a very advanced technique (read: plan for failure), but it is very satisfying when it finally works! Good luck!!
