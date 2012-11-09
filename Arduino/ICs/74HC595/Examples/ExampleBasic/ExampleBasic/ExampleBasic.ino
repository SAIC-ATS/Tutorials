// Pin connected to ST_CP of 74HC595
const byte latchPin = 8;
// Pin connected to SH_CP of 74HC595
const byte clockPin = 12;
// Pin connected to DS of 74HC595
const byte dataPin = 11;

// our outptut byte
byte outByte = 0;

void setup() {
  // set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  
  for (byte i = 0; i < 256; i++) {
    outByte = 0;
    bitSet(outByte,i); // same as outByte <<= i;
    
    // Set the latchPin to LOW so that you the outputs don't change
    // while you are sending the bits in.  This is something like
    // closing the curtain while you make a costume change ...
    digitalWrite(latchPin, LOW);
    // send the bits in as a whole byte.  Choose MSBFIRST 
    // (send in the bits of your outByte starting with the most 
    // significant bit first) or LSBFIRST (send in the bits of your
    // outByte starting with the least significant bit).
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  
    // Set the latchPin to HIGH so that the outputs will be presented.
    // This is something like opening the curtain when you are finished
    // with your costume change ...
    digitalWrite(latchPin, HIGH);
    // delay for a little bit
    delay(200);
  }
}

