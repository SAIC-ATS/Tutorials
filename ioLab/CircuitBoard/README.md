# CircuitBoardTutorial
This tutorial describes how to create your very own printed circuit board (PCB) using the tools in Art & Technology Studies ioLab at the [School of the Art Institute of Chicago](http://www.saic.edu).  Here's what we will cover in this tut:

1. Using [fritzing](http://www.fritzing.org) to design the PCB for your project.
2. Exporting and preparing that design for the circuit board mill using the MIT CBE's [Fab Modules](http://kokompe.cba.mit.edu/).s
3. Setting up the mill and running a mill job.
4. Finishing your PCB and preparing to put it into use.

For this tutorial, let's assume that you already have [downloaded](http://fritzing.org/download) Fritzing, you have designed your PCB, you have some electronics experience and that you're proficient at breadboarding a circuit, soldering, and checking continuity with a multimeter.  I will be touching briefly on the example design, but there are many more in-depth tutorials over at http://fritzing.org/learning/.

Ok, let's get started!!

## 1. Using Fritzing to design the PCB.
If you're ready to design and fabricate a PCB, that usually means that you have already worked out your circuit on a breadboard.  You may even have soldered up one or two of said circuit on a protoboard. A dedicated PCB can save you space and keep you from having to solder a million jumpers all over your protoboard.  For this tutorial, we're going to use a modified version of the [555 Timer LED Flasher](http://fritzing.org/projects/555-timer-led-flasher) from Fritzing's projects page.  The astable 555 circuit is a oldy and a goody and it will show some of the features of that can make a PCB more desirable than a protoboard.  [Here](https://github.com/noahcoleman/CircuitBoardTutorial/blob/master/555%20Timer%20IC.fzz) is the Fritzing file we'll be using.

So, we're going to open that up in Frizting, which should look a little something like this:
![alt text][1]
We are so done with breadboarding, though.  Let's move on to the PCB page.  To get there you want to click on the button that says "PCB" up at the top of the page.  Alternatively, you can press ⌘4 to get there.

IMAGE OF FRITZING-- pcb view
![alt text][2]
Ok, so now we have the pcb view up, and you can see that I have all my components placed and the traces properly routed.  Just as a side note, the big empty space on the right is going to be for the potentiometer.  Once I've got everything finalized, I want to do a quick design rules check to make sure I haven't crossed any traces--this becomes more important with more complex boards.
![alt text][3]

## 2. Exporting and preparing file for MIT CBA Fab Modules
To export, click on the button at the bottom labeled "Export for PCB." IMAGE I like to use the PDF, but you can use the SVG if you prefer.  Specify the folder you'd like to export to. *Hint: This action exports several files all at once, so I recommend creating a new folder for each project.  Just exporting it to your desktop or wherever will become a mess real fast.
![alt text][4]

Next, let's navigate to the folder we just exported the PDFs to. There will be 16 or so files there.  We are only interested in the one that ends with "..._etch_copper_bottom_mirror." We want to mill out the copper bottom layer, and we want it mirrored so that the circuit will look as it did in Fritzing when we solder it all up.  

Fab Modules uses .png images as input for creating the circuitboard.  Open your ..._etch_copper_bottom_mirror.pdf in Preview and go to **File>>Export**.  Select .png as your file output.  The easiest way to get this new png to the roland is by putting it on the special *Roland Thumb Drive* located on the Roland cart (it is formatted specifically for the Raspberry Pi).  Here's what it looks like for the visual folks: 
![alt text][5]

## 3. Preparing the file for milling on Roland Modela
Now we head over to the Roland cart and the Raspberry Pi.  Plug the jump drive into the hub located near the back of the cart and double-click the `start_fab.sh` icon on the desktop, then click *Execute*.
![alt text][6]

Once that comes up, we need to select our input type as well as the output type.  For what we're doing, we want **image (.png)** as the input and **Roland Modela (.rml)** as the output. Click the button on the right that says "make_png_rml"
![alt text][7]

This opens up the program that will send the PCB design to the mill for cutting.

Once that's open, click the *load .png* button to the left of the window.  Select the .png file you put on the jump drive.  Next, click the *make .path* button near the bottom of the window.  You should wind up with something like this: 
![alt text][8]

That looks a little messy, so we're going to change some settings so we can better see what is going on.  At the bottom of the window, just underneath where your paths are, open the dropdown menu that says *view type*.  Select *segments*. There, that's better.  Now, we want to mill traces on a PCB, so go to the dropdown menu that says *defaults* at the top center of the window. Select *mill traces (0.010)*
![alt text][9]

The way this software decides how to create the paths for the mill (which is not typical of most CAM programs) is by looking for where black and white meet.  Think of it almost like an image trace in Adobe Illustrator.  We can change certain settings to affect how the software interprets the border between white and black and how it creates the toolpaths.
- **diameter (mm)** refers to the diameter of the milling bit in millimeters.  We can leave that one for now.
- **overlap** refers to how much each path will overlap the one preceding.  We can also leave that one alone.
- **intensity** adjusts the threshold between white and black where the program draws the path.
- **offsets**. 1 means it will create one path, 2+ will create additional concentric paths around the original. 
- **error (pixels)** affects how "fine" the paths are.  Larger numbers mean chunkier curves, smaller numbers with smooth those curves out. *I like to use **0.01**.*
- **z (mm)** is the depth the machine will go as it is cutting the path.  The default is usually sufficient.

Once the settings are good to go, press *make .path*.  Wait a few moments (the RPi is thinking) and pretty soon you should see blue lines that closely resemble your B&W PNG.  Check to make sure all the pads and traces are isolated.  Most issues can be fixed by changing the **intensity** and **error (pixels)** settings.  Everything look good? Great!

Let's move on to the settings on the far right of the window.
- **speed (mm/s):** The speed the bit will move through the material. 4 mm/s is a safe speed for both etching traces and cutting out the board.
- **jog (mm):** The height the bit will lift for travel






[1]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/BreadboardView.jpg "Breadboard view."
[2]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/PCBView.jpg "PCB View."
[3]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/PCBViewDRC.jpg "Design Rules Check (very important!)."
[4]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/ExportPDF.jpg "Export PDF."
[5]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/JumpDrive.JPG "This is the jump drive you should use."
[6]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/start_fab_sh.png "start_fab.sh"
[7]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/png2rml.png ".img as input, .rml as output"
[8]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/loadPngMakePath.png "load .png, make path."
[9]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/millTracesChangeSettings.png "Mill traces, finesse settings"
[10]:
[11]:
[12]:
[13]:



