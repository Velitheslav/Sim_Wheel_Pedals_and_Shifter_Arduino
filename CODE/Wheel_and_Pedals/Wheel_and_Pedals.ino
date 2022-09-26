#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 0, 0, true, true,true, false, false, false, false, false, false, false, false);
//, 0, 0, true, true,true, false, false, true, false, true, true, true, true
//hidReportId //joystickType //buttonCount //hatSwitchCount //includeXAxis -> Gas  //includeYAxis -> Brake//includeZAxis -> Clutch//includeRxAxis//includeRyAxis//includeRzAxis //includeRudder //includeThrottle//includeAccelerator//includeBrake //includeSteering
//Constants:

const int potPin = A0; //pin A0 to read analog input
const int potPin2 = A1;
const int potPin3 = A2;

//Variables:
int value; //save analog value
int value2;
int value3;

void setup(){
  //Input or output?
  Joystick.begin();
 Serial.begin(9600);
  pinMode(potPin, INPUT); //Optional 
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);
}

void loop(){
  Serial.println("****new loop****");
  value = analogRead(potPin);   //Read and save analog value from potentiometer
  value2 = analogRead(potPin2);
  value3 = analogRead(potPin3);
  //value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  //analogWrite(ledPin, value); //Send PWM value to led
   Serial.println("gas: ");
  Serial.println(value);
  Serial.println("brake: ");
  Serial.println( value2);
  Serial.println("steering"); 
  Serial.println( value3/2);



Joystick.setXAxis(value/2);//.setThrottle
Joystick.setYAxis(value2/2);

Joystick.setZAxis(value3);
}
