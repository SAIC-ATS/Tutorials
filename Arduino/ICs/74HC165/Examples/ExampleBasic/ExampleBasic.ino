// 74HC165
// http://www.sparkfun.com/datasheets/Components/General/sn74hc165.pdf

// Pin connected to CP of 74HC165
const int clockPin = 7; 
// Pin connected to SH/LD of 74HC165
const int latchPin = 8;
// Pin connected to QH of 74HC165
const int dataPin = 9;

void setup(){
  // prepare the serial port
  Serial.begin(9600);

  // set pins as output
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  // set pins as input
  pinMode(dataPin, INPUT);
}

void loop(){
  // Set the latchPin LOW ...
  digitalWrite (latchPin, LOW);
  // ... then wait very briefly for the chipe to read digital inputs
  delayMicroseconds(10);
  // ... then set the latchPin HIGH in preparation for shifting
  digitalWrite (latchPin, HIGH);

  // Shift in 8 bits (1 byte). Choose MSBFIRST 
  // (retrieve the bits of your inByte starting with the most 
  // significant bit first) or LSBFIRST (retrieve the bits of your
  // inByte starting with the least significant bit). 
  byte inByte = shiftIn165(dataPin,clockPin,MSBFIRST);

  Serial.write(inByte); //debugging in serial window of switches 1 through 8)

  // take a breather to prevent serial buffer overflow
  delay (10); 
}

/*
 * Here we define an alternate shiftIn function. The only difference 
 * between this shift in function and the built-in shiftIn function 
 * is that the clock must got LOW before shifting and HIGH after 
 * shifting.  This is the opposite of the built in Arduino shiftIn.
 */
uint8_t shiftIn165(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, LOW);
		if (bitOrder == LSBFIRST)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, HIGH);
	}
	return value;
}

