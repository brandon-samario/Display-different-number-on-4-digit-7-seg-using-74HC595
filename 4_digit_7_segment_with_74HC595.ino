/*This code is for controlling a 4-digit 7-segment display using an Arduino board.
Defines the pin assignments for the latch, clock pulse, data, and the 4 pins that control the digits of the display. 
It also defines an array of byte values that correspond to the segment patterns for each digit 0-9.
In the setup function, the pin modes are set to output for all of the pins.
In the loop function, set the pins for each digit of the display in turn, using the digitalWrite function to turn on or off each of the four pins that control the digits. 
Sends the segment pattern for the current digit using the shiftOut function. 
The latch pin is toggled to update the display and a delay is added before moving on to the next digit.
The result is a 4-digit display that cycles through numbers with a delay of 5ms between each number. 
*/

const int latch = 4; //pin to update
const int cp = 5; //shift pin
const int data = 3; //pin to pass the information
const int dPins[4] = {11, 10, 9, 8}; //pins that control the digits

const byte digits[10] = { //determine which pins to be on or off to display numbers from 0-9
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B0000111,  // 7
  B01111111, // 8
  B01101111, // 9
};

void setup() {
  pinMode(latch, OUTPUT); //latch pin is set as output
  pinMode(cp, OUTPUT); //cp pin is set as output
  pinMode(data, OUTPUT); //data pin is set as output
  pinMode(11, OUTPUT); //digital pin 11 is set as output
  pinMode(10, OUTPUT); //digital pin 10 set as output
  pinMode(9, OUTPUT); //digital pin 9 is set as output
  pinMode(8, OUTPUT); //digital pin 8 is set as output 
}

void loop() {
  //digit 4
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(latch, LOW);
  shiftOut(data, cp, MSBFIRST, digits[6]); //number to display in digit 4
  digitalWrite(latch, HIGH);

  delay(5); //delay 5ms

  //digit 3
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cp, MSBFIRST, digits[5]); //number to display in digit 3
  digitalWrite(latch, HIGH);
  
  delay(5); //delay 5ms

  //digit 2
  digitalWrite(11, HIGH); 
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cp, MSBFIRST, digits[4]); //number to display in digit 2
  digitalWrite(latch, HIGH);
  
  delay(5); //delay 5ms

  //digit 1
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cp, MSBFIRST, digits[3]); //number to display in digit 1
  digitalWrite(latch, HIGH);
  
  delay(5); //delay 5ms

}
