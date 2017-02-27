# Creating masked circuit boards for SMD parts

This tutorial will show how to mill a board on the [Othermill](http://othermachine.co) and use light-sensitive solder mask to mask everything but the pads.  This is especially useful for surface-mount (SMD) designs where we want to use solder paste.  The mask keeps the paste where we want it so we have good connections and less chance of solder bridges.
### Materials
- FR1 (PCB material)
- Dynamask (photo-sensitive dry film resist)
- Developer/Fixer (Soda Ash)
- Scotch tape
- Transparency film

### Equipment
- Othermill
- Printer
- Laminator
- Non-metal container
- Old toothbrush or other soft-bristle brush

### Skills
- Designing PCBs in Fritzing, Eagle, or other PCB design software.
- [Milling boards on the Othermill.](https://github.com/SAIC-ATS/Tutorials/tree/master/ioLab/CircuitBoardOthermill)

## Milling the board
To start,  import your board design (either .brd or GERBER) into Otherplan and position it so there will be a generous border around your board.  Make note of the position of the board; you are going to need it later!  Because you are going to be adding a solder mask, you need to alter some of the settings before milling:
- Deselect "Holes" and "Outline" so you are only cutting the traces.
- Change the milling tool to "30&deg; Engraving Tool".
- In the *Advanced Settings*, change the *Trace Depth* to **0.07mm**.  Change the *Trace Clearance* to **0.0mm**.
This is to reduce the amount of material removed and keep as much surface area as possible for the solder mask to stick to.

Press "Start Milling" and wait patiently.

## Preparing to expose the solder mask
The tutorial from here on out generally follows [this video](https://www.youtube.com/watch?v=B0Syj4awcc8) from [Rembrandt Electronics](http://www.rembrandtelectronics.com/).

This tutorial uses dry film solder mask, known as Dynamask.  This is a photo-sensitive material that comes in sheets or rolls with protective plastic on both sides.  Because it is photo-sensitive, you need to create a transparency that will keep light off of the pads and allows light to get through to the rest of the board.  To do this, open up your PCB design editor (I will be using)

Print Transparency (Stop layers)
Cut Dynamask to size (larger than final board size)
Peel off matte protective layer
Lay down masking film
Run through laminator 5x
Rinse under cold water
Peel off shiny masking film
Align transparency to pads
Press firmly to stick transparency to masking film
Expose masking film
Wait one hour in dark for polymerization
Remove transparency
Soak in fixer bath; scrub away unexposed mask
Rinse board with clean water
Expose board again to UV for 30-60 minutes
Put back in Othermill and mill holes and Outline with correct endmill.
