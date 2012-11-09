// 74HC595
// http://www.sparkfun.com/datasheets/IC/SN74HC595.pdf

// Pin connected to SRCLK of 74HC595
const byte latchPin = 11;
// Pin connected to RCLK of 74HC595
const byte clockPin = 12;
// Pin connected to SER of 74HC595
const byte dataPin = 10;

// our outptut byte
byte outByte = 0;

void setup() {
  // set pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  while(Serial.available() > 0) {
     outByte = Serial.read(); 
  }
  
  
  // Set the latchPin to LOW so that you the outputs don't change
  // while you are sending the bits in.  This is something like
  // closing the curtain while you make a costume change ...
  digitalWrite(latchPin, LOW);
  // Send the bits in as a whole byte.  Choose MSBFIRST 
  // (send in the bits of your outByte starting with the most 
  // significant bit first) or LSBFIRST (send in the bits of your
  // outByte starting with the least significant bit).
  shiftOut(dataPin, clockPin, MSBFIRST, outByte);  
  // Set the latchPin to HIGH so that the outputs will be presented.
  // This is something like opening the curtain when you are finished
  // with your costume change ...
  digitalWrite(latchPin, HIGH);
  // delay for a little bit
  delay(50);

}


