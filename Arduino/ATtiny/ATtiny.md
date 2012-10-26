

![ATTiny85 on a penny](assets/images/attiny.jpg)

Programming the ATtiny with Arduino
==================================
What's an ATtiny, and why would I need one?
-------------------------------------------

An ATtiny is a microcontroller, similar to the ATMega microcontroller at the heart of the Arduino board. You can write programs for ATtinies using the Arduino language and programming environment, and they can do many of the same things as the ATMega. The difference is that ATtinies are smaller, cheaper, and more power-efficient than the Arduino's microcontroller. If any of these things are important to your project, consider an ATtiny!

Use an Arduino to program the ATtiny
------------------------------------
Uploading a program to an ATtiny is slightly different than uploading to an Arduino: the Arduino has a lot of extra hardware and software on the board that lets you plug it in directly to your computer. The ATtiny, stripped down as it is, doesn't have any of this stuff. But a spare Arduino and a few simple parts can do everything we need.

To connect this little chip to your computer and program it, you'll need the following hardware:

* Arduino Uno
* 10uf capacitor
* breadboard (a small one will work fine)
* 6 jumper wires

Software Setup
--------------

Before we start wiring things up, we'll need to program the Arduino hardware to act like a microcontroller programmer. Connect your Arduino, open the ArduinoISP sketch (it's in the Arduino Examples folder), and upload it to the Arduino.

![Examples>ArduinoISP](assets/images/ArduinoISP.png)

Next, we'll need to update the Arduino app with ATTiny "core" files. 

1. Find your Arduino folder (on a Mac, it's in the Documents folder)
2. Create a folder called "hardware" in the Arduino folder
3. Download [this zip file containing the ATTiny core files](https://github.com/damellis/attiny/zipball/Arduino1).
4. Unzip the contents (this should be a folder named "attiny") into the "hardware" folder you just created.
5. Restart the Arduino app.

In the Tools > Board menu, you should see a number of new entries:
![Tools>Board](assets/images/Board.png)

Select the ATtiny85 (internal 8 MHz clock) board. That's it for the software side -- on to the hardware!

Hardware Setup
--------------
First, make sure to unplug your Arduino. It's safest to hook this stuff up with the power off.
____________
(more here, fritzing diagram)
________________________
Here's the final assembly:

![Final assembly](assets/images/together.jpg)



	




