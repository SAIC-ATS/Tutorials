# CircuitBoardTutorial
This tutorial describes how to create your very own printed circuit board (PCB) using the tools in Art & Technology Studies ioLab at the [School of the Art Institute of Chicago](http://www.saic.edu).  Here's what we will cover in this tut:

1. Using [fritzing](http://www.fritzing.org) to design the PCB for your project and export gerber files to be milled.
2. Importing the gerber files into the Othermill's control software, Otherplan.
3. Setting up the [Othermill](https://othermachine.co/) with a PCB blank and running a mill job.
4. Finishing your PCB and preparing to put it into use.

For this tutorial, let's assume that you already have [downloaded](http://fritzing.org/download) Fritzing and [Otherplan](https://othermachine.co/otherplan/), you have designed your PCB, you have some electronics experience and that you're proficient at breadboarding a circuit, soldering, and checking continuity with a multimeter.  I will be touching briefly on the example design, but there are many more in-depth tutorials over at http://fritzing.org/learning/.

Ok, let's get started!!

## 1. Using Fritzing to design the PCB.
If you're ready to design and fabricate a PCB, that usually means that you have already worked out your circuit on a breadboard.  You may even have soldered up one or two of said circuit on a protoboard. A dedicated PCB can save you space and keep you from having to solder a million jumpers all over your protoboard.  For this tutorial, we're going to use a modified version of the [555 Timer LED Flasher](http://fritzing.org/projects/555-timer-led-flasher) from Fritzing's projects page.  The astable 555 circuit is a oldy and a goody and it will show some of the features of that can make a PCB more desirable than a protoboard.  [Here](https://github.com/noahcoleman/CircuitBoardTutorial/blob/master/555%20Timer%20IC.fzz) is the Fritzing file we'll be using.

So, we're going to open that up in Frizting, which should look a little something like this:
![alt text][1]
We are so done with breadboarding, though.  Let's move on to the PCB tab.  To get there you want to click on the button that says "PCB" up at the top of the page.  Alternatively, you can press ⌘4 to get there.

![alt text][2]

Ok, so now we have the pcb view up, and you can see that I have all my components placed and the traces properly routed.  Just as a side note, the big empty space on the right is going to be for the potentiometer.  Once I've got everything finalized, I want to do a quick design rules check (⇧⌘D) to make sure none of the traces cross or come too close to one another--this becomes more important with more complex boards.

![alt text][3]

Once we've passed the DRC and we're ready to export, click on the button near bottom of the screen labeled "Export for PCB." Select "Extended Gerber (RSX274X)"  You can also export by going to *File-->Export-->For Production-->Extended Gerber (RSX274X)*. Specify the folder you'd like to export to. *Hint: This action exports several files all at once, so I recommend creating a new folder for each project.  Just exporting it to your desktop or wherever will become a mess real fast. 
![alt text][4]

## 3. Preparing the file for milling in Otherplan
Open Otherplan and connect the Othermill to your computer with a USB cable.  Home the machine.
The material we are using in this tutorial is single-sided FR-1.  Measure the size of your blank and input it into the appropriate boxes. It is important when measuring the thickness of the board to include the layer of double-sided tape used to adhere the board to the mill.  If you don't include this, you may cut into the spoilboard.
In Otherplan, make sure that your material is aligned to the bracket.  This is handy for single sided boards and essential for double-sided boards where the bracket provides the registration for the flip milling.

Click "Open Files..." and navigate to the folder you exported the Gerber files to.  Select the file that ends in ".gtl" and press "Open." The window that opens will ask you to choose which Gerber files to associate with the bottom, outline, and holes of your board.  Usually you won't have to change these, but you are able to if needed.

Your design should show up on the material in Otherplan.  You can change the location of the design by changing the values under "Placement."  Make sure that your design is offset from the material edge by a few millimeters so that the endmill does not cut into the bracket.
![alt text][5]

Specify which endmills you will be using for your job.  For this design, we will be using the 1/32" flat mill and the 30 DEGREE engraving bit.  Any areas highlighted in red will not be cut unless you use a smaller bit.

Note on double sided boards: When cutting the first side, you only want to cut the traces.  Wait to cut the holes and outline when you do the other side.  You can select/deselect what features are cut by clicking the buttons labeled *Traces, Holes,* and *Outlines*.

## 4. Preparing the circuit board blank and mill
In order to mill a circuit board, our pcb blank needs to be affixed to the mill's bed so it won't move around while the job is running.  A few strips of double-sided tape will do the trick here.  Make sure there are no folds or crinkles in the tape and that the tape is not overlapping itself.  We want the board to be as level as possible for milling and even a double thickness of tape can throw things off. It should look something like this:
![alt text][10]

Next, we need to put the bit into the mill. Make sure the shank of the bit (the round part) is completely in the collet. This helps the bit to be more secure while it is cutting.
![alt text][11]

When you have imported your design and chosen all the parameters, begin milling the board by clicking "Start Milling." There will also be an estimate of the time it will take to mill your board.  Otherplan will inform you when and how to change endmills.

## 5. Finishing
Once we have cut the traces and cut out the board, it is time to put it into use!!!  Use a scraper to get the PCB off the bed of the mill and remove all double-sided tape and dust from both the spoilboard and your PCB.  Don't forget to vacuum out the Othermill so it is clean for the next person! 

At this point, inspect the board for any potential problems.  the edges of the traces should be smooth.  If there are any burrs, they can be gently sanded away or cut away with a utility knife.  Check each of the pads and connections for continuity.  Make sure the traces that should be electrically connected are and make sure things that shouldn't be electrically connected aren't.  Check the large empty areas of copper left on your board in addition to the traces.  If you have a connection where there shouldn't be one, inspecting the board under a magnifying glass or microscope can help.  Sometimes small bits of copper get stuck in the troughs and connect two adjacent pieces of copper.

If you have been handling your PCB a lot, you may want to give it a wipe down with some alcohol or acetone to take finger oils off of the copper. These oils can make soldering difficult and corrode the copper in the long run.  Handle the board with gloves or by the edges after you do this.

You are now ready to solder in your components!

This concludes the tutorial.  





[1]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/BreadboardView.jpg "Breadboard view."
[2]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/PCBView.jpg "PCB View."
[3]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/PCBViewDRC.jpg "Design Rules Check (very important!)."
[4]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/ExportPDF.jpg "Export PDF."
[5]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/JumpDrive.JPG "This is the jump drive you should use."
[6]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/start_fab_sh.png "start_fab.sh"
[7]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/png2rml.png ".img as input, .rml as output"
[8]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/loadPngMakePath.png "load .png, make path."
[9]: https://raw.githubusercontent.com/noahcoleman/CircuitBoardTutorial/master/images/millTracesChangeSettings.png "Mill traces, finesse settings"
[10]:picture of double sided tape on pcb
[11]:putting bit in collet
[12]:up and down buttons/tip touching pcb
[13]:
[14]:
[15]:
[16]:



