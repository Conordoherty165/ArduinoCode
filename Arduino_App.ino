#define pin1  8 //pins 8 through to 11 are the pins used on the board for the four pin connections to the stepper motor
#define pin2  9
#define pin3  10
#define pin4  11
#define delaytime 2   //delay time in ms to control the stepper motor delaytime.
// tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
char unChar;
String readString; //We assign the word readString to a string variable
float numberOfSteps = 0;
int serialData = 0;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  Serial.begin(9600); //initialize serial communication
}

void loop() {
  while (Serial.available()) {  //The availability of the serial port is verified through a loop
    delay(3);              
    char c = Serial.read();  // The characters that enter through the port are read
    readString += c;         // accumulate each of the characters in readString
  }
  if (readString.length() > 0) { // It is verified that the variable contains information
    Serial.println(readString.toInt());  // whatever the variable has is sent
    serialData = readString.toInt();
  }
  while (serialData > numberOfSteps) {
    backward();
    delayMicroseconds(40);
    numberOfSteps = numberOfSteps + 1;
  }
  while (serialData < numberOfSteps) {
    forward();
    delayMicroseconds(40);
    numberOfSteps = numberOfSteps - 1;
  }
  if (readString == "SET") {
    numberOfSteps = 0;
    serialData = 0;
  }
  readString = ""; // clear the variable by adding blank value
}
