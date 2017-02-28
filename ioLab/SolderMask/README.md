# Creating masked circuit boards for SMD parts

HEADLINE IMAGE

This tutorial will show how to mill a board on the [Othermill](http://othermachine.co) and use light-sensitive solder mask to mask everything but the pads.  This is especially useful for surface-mount (SMD) designs where we want to use solder paste.  The mask keeps the solder where we want it so we have good connections and less chance of solder bridges.
#### Materials
- FR1 (PCB material)
- Double-sided tape
- Alcohol or acetone
- Dynamask (photo-sensitive dry film resist)
- Developer/Fixer (Soda Ash)
- Scotch tape
- Transparency film
- Paper towels

#### Equipment
- Othermill
- Printer
- Scissors or utility knife
- Laminator
- UV light source (when in doubt, you can use the :sunny:)
- Non-metal container large enough to hold your board.
- Old toothbrush or other soft-bristle brush

#### Skills
- Designing PCBs in Fritzing, Eagle, or other PCB design software.
- [Milling boards on the Othermill.](https://github.com/SAIC-ATS/Tutorials/tree/master/ioLab/CircuitBoardOthermill)

PHOTO OF MATERIALS AND EQUIPMENT

## Milling the board
To start,  import your board design into Otherplan and position it so there will be a generous border around your board.  Make note of the position of the board; you are going to need it later!  Because you are going to be adding a solder mask, you need to alter some of the settings before milling:
- Deselect `Holes` and `Outline` so you are only cutting the traces.
- Change the milling tool to `30° Engraving Tool`.
- In the *Advanced Settings*, change the *Trace Depth* to `0.07mm`.  Change the *Trace Clearance* to `0.0mm`.
This is to reduce the amount of material removed and keep as much surface area as possible for the solder mask to stick to.

![alt text][1] <!-- Otherplan settings -->

Press "Start Milling" and wait patiently.

## Preparing to expose the solder mask
The tutorial from here on out generally follows [this video](https://www.youtube.com/watch?v=B0Syj4awcc8) from [Rembrandt Electronics](http://www.rembrandtelectronics.com/).

This tutorial uses dry film solder mask, known as Dynamask.  This is a photo-sensitive material that comes in sheets or rolls with protective plastic on both sides.  Note that one side has a shiny finish and the other a matte finish.  Because it is photo-sensitive, you need to create a transparency that will keep light off of the pads and allows light to get through to the rest of the board.  I will show how to do this on Eagle.

### Print transparency
1. With your board file open, open the layers settings (shown by the purple arrow in the image below).
2. Hide all of the layers except for `tStop` and `Dimension`.

  ![alt text][3] <!-- Layers settings -->
3. Go to `File>Print`. In the print dialog box, make sure the `Black` and `Solid` boxes are checked under Options.  Also, the scale factor should be set to `1`.

  ![alt text][4] <!-- Print Settings -->
4. Make sure the transparency film is loaded properly in your printer and press print.

Once you have your transparency, you are ready to move on to the next step.

![alt text][5] <!-- Transparency -->

### Prep board for exposure
1. Clean off any milling dust and wipe your board down with alcohol or acetone so the board is clean of dust, oils, and debris.
2. Cut Dynamask to size.  This should be smaller than your piece of FR1, but larger than the final board size).
![alt text][9]<!-- Cut Dynamask -->
3. Peel off matte protective layer.  The video linked above has a pretty slick way of doing this with the Scotch tape.
4. Lay down the masking film on the board, being careful not to introduce any bubbles.
5. Run your board+masking film through the laminator five times.  Make sure you put it through the same orientation each time to help squeeze out any bubbles.
![alt text][6]<!-- GIF OF BOARD GOING THRU LAMINATOR -->
6. Immediately rinse your board under some cold water. This will help the masking film to adhere strongly to your board. Dry your board with a paper towel before moving on to the next step.
7. Peel off the shiny masking film.  This is a deviation from the order of operations in the video above.  The tacky surface of the masking film holds the transparency in place nicely for the exposure.  
8. Carefully align your transparency to the pads on your board.  You may want to cut down the transparency to be closer to the size of your board to make this easier.  Once it is aligned, press down firmly to adhere the transparency to the board.

![alt text][7]<!-- IMAGE OF TRANSPARENCY ON MASKING FILM -->

### Expose masking film
Exposure times will vary based on what UV source you are using.  We tested using a nail polish curing lamp for two minutes.  It's not a bad idea to plan some testing into your timetable and materials budget.

1. Expose your masked board to UV light for 45sec-2min.  
2. Place exposed board into a dark place (to stop exposure) for one hour.  This allows the masking material to polymerize.

  ![alt text][8]<!-- IMAGE OF UV BATH -->

### Washing, drying, and post-curing
1. Mix fixer and warm water (~45°C) according to instructions.  This should be done no more than 10 minutes before your board is ready. (i.e., at the 50 minute mark).
2. Let board soak in the bath for a minute or two and then gently begin scrubbing with the toothbrush.  The areas of the mask that were covered by the transparency should begin to wash away and you should see the copper clearly.
![alt text][10]<!-- Washing the board -->
3. Once all the unexposed parts of the mask have been removed and your pads are all clear, rinse the board in running water and allow it to dry.  Be careful not to touch the solder mask, it will still be tacky.
![alt text][11]<!-- All clean! -->
4. Place the dry board back into your UV light source for 30-60 minutes. This will harden the solder mask into a very durable surface.

### Cut holes and outline
*I told you you would need to remember the position of your board design in Otherplan!*
1. Put your board back into the Othermill, paying attention to place it as close to the original position as possible.
2. In Otherplan, deselect  `Traces` and select `Holes` and `Outline`.  Change the milling tool to `1/32in Flat End Mill` and add smaller flat end mills if needed.
3. Press "Start Milling" and wait patiently.

![alt text][2] <!-- Otherplan Cutout-->

You're done! You should have a great looking board that is ready for soldering by hand or with solder paste.
![alt text][12] <!-- Finished Board -->

[1]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/OthermillSettings.png?raw=true "Othermill settings."
[2]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/HolesCutout.png?raw=true "Holes and Cutout."
[3]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/LayerSettings.png?raw=true "Show/Hide Layers."
[4]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/PrintSettings.png?raw=true
[5]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/Transparency01.jpg?raw=true "Transparency cut to size."
[6]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/Laminator.gif?raw=true "Board going through laminator"
[7]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/MaskWithTransparency.jpg?raw=true  "Transparency adhered to masking film"
[8]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/UVExposure.jpg?raw=true "Exposing the film with UV lamps."
[9]:https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/SolderMask/assets/CutMask.jpg?raw=true "text"
[10]: link "Washing the board"
[11]: link "All clean!"
[12]: link "Finished board, drilled and cut!"
[13]: link "text"
