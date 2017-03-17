# Creating a PCB from an Image

Sometimes, you just want to get to making a PCB without having to go to all the trouble of actually *designing* it.  Sometimes you stumble across a sweet electronics project, but instead of editable design files, there is only a black and white image for photo etching.  There are several ways to get around this problem, but one of the fastest for us here in the ioLab is to use [Fab Modules](www.fabmodules.org) to turn the image into toolpaths for the Othermill.

>Fab Modules is a browser-based CAM system, which allows to generate toolpaths for and control lasercutters, CNC-mills and waterjets commonly found in [fablabs](https://www.fablabs.io/).
>
>--Fab Modules Github

## 1. Openining the Image
First, go to the [Fab Modules website](www.fabmodules.org).  When you first arrive, it will be mostly empty, white space.

<!-- fabmodules.org -->
![alt text][1]

Click on `Select Input Format`. For this tutorial, we will be using ".png"

<!-- input menu -->
![alt text][2]

<!-- input complete -->
![alt text][3]

There is our board.  This is the [fabispkey](http://fab.cba.mit.edu/content/projects/fabispkey/index.html) by [Andy Baradagjy](http://bardagjy.com/).  

Now we need to select our output format.  Click `Select Output Format` and select "Othermill (.nc)"

<!-- output menu -->
![alt text][4]

Now we need to select our process.  For this tutorial, I'm going to use the `PCB traces (1/64)` process because I am cutting the traces into the copper on my board.

<!-- process menu -->
![alt text][5]
## 2. A Look at the Settings

On the right hand side, there are several settings to modify that will affect both how the image gets processed into toolpaths, as well as how the toolpaths get made. Let's look at those in more detail before we move on to the next step.

<!-- process details -->
![alt text][7]

### Input
- **DPI:** This refers to the **d**ots **p**er **i**nch of your image file.  If your DPI is 100 and your image is 300 pixels wide, that means your image is 3 inches wide.  This field should auto-populate and there's usually not a reason to change it.
- **Invert Image:** When cutting a PCB from an image, Fab Modules removes material from the black portions of the image.  So, you want your pads and traces to be white.  If your image uses black for pads and traces, use this button to invert the image.

### Output
- **Cut speed:** How quickly the cutter will move through your material along the x and y axis; otherwise known as the *feed rate*.
- **Plunge speed:** How quickly the cutter will move through your material along the z axis.
- **Jog speed:** How quickly the machine will move when it is *not* cutting.
- **Jog height:** The height the cutter will move to when not cutting.  This is measured from the origin and should be high enough to avoid your material and any workholding you may be using.
- **Spindle speed (RPM):** The speed the tool will be turning.
- **Tool:** This setting is for machines with an automatic tool changer, which the Othermill does not have.
- **Coolant:** Toggles coolant on/off.  Again, not a feature on the Othermill.

### Process
- `calculate`: Generates tool paths based on your output and process settings.
- `save`: Downloads the generated tool paths as a text file.
- `send`: If you have set up Fab Modules to run machines remotely, this will send the generated tool paths to those machines.
- **Send command:** Used with the remote Fab Modules.
- **Server:** Used with the remote Fab Modules.
- **Cut depth (mm):** How deep the tool will cut in millimeters.
- **Tool diameter (mm):** Diameter of tool in millimeters.
- **Number of offsets:** Dictates how many concentric passes will be used to remove the black part of your image.  (i.e.: `1` will just cut once around, `4` will cut 4 concentric passes).  A value of `-1` will remove *all* the black areas of your image.

<!-- Place image here of offsets -->
![alt text][6]

- **Offset overlap:** Percentage of tool diameter that overlaps on each offset.
- **Path error (pixels):** This value is used in calculating the tool paths based on the pixels.  The lower this number is, the tighter the tool paths will align to the image.
- **Image threshold (0-1):** This represents the point at which the program decides which pixels are "white" and which ones are "black." Must be a value between 0 and 1.
- **Sort path:** Optimizes sorting of tool paths for efficiency.
- **Sort merge diameter multiple:** Don't know, need to consult the Fab Modules documentation.
- **Sort order weight:** Don't know, need to consult the Fab Modules documentation.
- **Sort sequence weight:** Don't know, need to consult the Fab Modules documentation.

## 3. Settings for Cutting Traces
We want to make sure our image has white pads and traces and that the output and process settings are appropriate for what we are doing (cutting PCB traces).  The defaults usually produce good results, so I'm going to leave most of them alone.  The things I am going to change are:

- Cut Depth: 0.1 mm.
- Tool diameter: 0.33 mm.  I'm fudging my tool diameter a bit to get this to cut right.  I do not always recommend this because the machine is removing more material in real life than it thinks it is in the software.
- Number of offsets: -1. This is to remove all the copper, which is important for the USB connector on the left of the board.
- Path error: 0.1. This will create tool paths that are more faithful to the image.

Press `calculate` and wait for the tool paths to be generated.  

<!-- image of tool paths -->
![alt text][8]

Check to make sure the tool paths match the image.  Unfortunately, there is not an easy way to compare them, but you could have the image open in another browser tab or something similar.  Once we are satisfied the board will cut as planned, we can click `save` and a text file ending in `.nc` will be downloaded immediately.  

<!-- image of downloaded file -->
![alt text][9]

Now that we have our g-code file, we can upload it to the Othermill and cut our board.

## Drilling Holes and Cutting Out the Board
This method does not drill holes or cut out the board.  Each operation (traces, holes, outline) needs a separate black & white image.  For alignment purposes, it is also important that the images are identical in height, width, and DPI.  Otherwise, the cuts will not line up and may ruin your board.

To cut holes, the .png image must have black circles that match the location and diameter of the holes (remember, the software wants to cut out the black part of the image).
To cut out the board, you must have an image with a white shape for your board surrounded by a black border, as seen in the image below:

<!-- image of board cutout menu -->
![alt text][10]

Cutting the holes and outline are relatively the same as cutting the traces.  Follow steps 1-3 above with the following changes:

- Select the `PCB outline (1/32)` process
- Change specific process details **_EDIT HERE!!_**
- Calculate and save your tool paths as before.

<!-- image of board cutout toolpaths -->
![alt text][11]

## Go to the mill!
Now we are ready to take the `.nc` files we have generated for the traces and holes/outline and upload them to Otherplan as we would with any other g-code file.  *Note: If you change the position of one file, you need to change the position of all files so they line up.*

This concludes the tutorial.

[1]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/FabModules001.png?raw=true "fabmodules.org"
[2]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/InputMenu.png?raw=true "input menu"
[3]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/InputComplete.png?raw=true "input complete!"
[4]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/OutputMenu.png?raw=true "output menu"
[5]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/ProcessMenu.png?raw=true "process menu"
[6]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/Offsets.png?raw=true "examples of offsets"
[7]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/ProcessDetails.png?raw=true "fabmodules.org"
[8]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/TracesToolpaths.png?raw=true "fabmodules.org"
[9]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/Download.png?raw=true "fabmodules.org"
[10]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/OutlineMenu.png?raw=true "outline menu"
[11]: https://github.com/SAIC-ATS/Tutorials/blob/master/ioLab/PCBfromImage/assets/OutlineToolpaths.png?raw=true "outline toolpaths"
