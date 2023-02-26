/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/

//Initializing some variables for 'blink'
int led = 13;

// the setup routine runs once when you press reset:
void setup() { //runs once
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

   // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  
//  delay(1);        // delay in between reads for stability
  float convert = 0.5*(585/1.871 + 128/0.414); //bits per volt, taking two readings
//  Serial.println(sensorValue/convert);
  Serial.println(); //To help with readability
  

  float m = -900.0/3.3; //slope, bits per volt
  //input 3.3V -> 100 bits
  //input 0V -> 1000 bits
  float b = 1000; //volts, y-intercept
  float y = 0.5*(m*sensorValue/convert + b);
  //Taking half of y to account for blink being both on and off
  Serial.println(y);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(y);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(y);               // wait for a second
  
  
}
