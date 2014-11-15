import processing.serial.*;

Serial myPort;

PFont font;

int numButtons = 8;
Button[] inButtons  = new Button[numButtons];
Button[] outButtons = new Button[numButtons];
int byteIn = 0;

int currentX = 0;
int boxOffset = 25;
int boxWidth = 50;
int boxHeight = 50;

void setup() {
  size(700, 175);
  background(0);
  println(Serial.list());  

  myPort = new Serial(this, Serial.list()[4], 9600);


  currentX = boxOffset;

  for (int i = 0; i < numButtons; i++) {
    inButtons[i] = new Button("IN", currentX, boxOffset, boxWidth, boxHeight);
    outButtons[i] = new Button("OUT", currentX, boxOffset*2+boxHeight, boxWidth, boxHeight);

    currentX += (boxWidth + boxOffset);
  }

  font = createFont("", 14);
  textFont(font);
}

void draw() {
  background(0);

  int byteOut = 0;
  for (int i = 0; i < numButtons; i++) {
    outButtons[i].draw();
    if (outButtons[i].value == true) {
      byteOut |= (1 << (7 - i));
    }
  }

  fill(255);
  stroke(255);
  textAlign(LEFT,CENTER);
  text("=  " + byteOut, currentX-10, boxOffset*2 + boxHeight + boxHeight / 2);


  // send the byte
  myPort.write(byteOut);

  while (myPort.available () > 0) {
    byteIn = myPort.read();
  }

  for (int i = 0; i < numButtons; i++) {
    boolean bit = ((byteIn >> 7-i) & 1) > 0;
    inButtons[i].value = bit;
    inButtons[i].draw();
  }
  
  fill(255);
  stroke(255);
  textAlign(LEFT,CENTER);
  text("=  " + byteIn, currentX-10, boxOffset + boxHeight / 2);
  
}


void mousePressed() {
  for (int i = 0; i < numButtons; i++) {
    outButtons[i].mousePressed();
  }
}

