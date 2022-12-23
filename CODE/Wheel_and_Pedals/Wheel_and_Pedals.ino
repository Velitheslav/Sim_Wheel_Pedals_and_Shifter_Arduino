#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 3, 0, true, true,true, false, false, false, false, false, false, false, false);
//, 0, 0, true, true,true, false, false, true, false, true, true, true, true
//hidReportId //joystickType //buttonCount //hatSwitchCount //includeXAxis -> Gas  //includeYAxis -> Brake//includeZAxis -> Clutch//includeRxAxis//includeRyAxis//includeRzAxis //includeRudder //includeThrottle//includeAccelerator//includeBrake //includeSteering
//Constants:

const int potPin = A0; //pin A0 to read analog input
const int potPin2 = A1;
const int potPin3 = A2;
const int but1=2;

//Variables:
int value; //save analog value
int value2;
int value3;
int button1=0;
//bool canBeChanged=true;
int oldState=LOW;

void setup(){
  //Input or output?
  Joystick.begin();
 Serial.begin(9600);
  pinMode(potPin, INPUT); //Optional 
  pinMode(potPin2, INPUT);
  pinMode(potPin3, INPUT);
  pinMode(but1,INPUT);
}

void loop(){
//Joystick.setButton(button1, 0);
 
  Serial.println("****new loop****");
  value = analogRead(potPin);   //Read and save analog value from potentiometer
  value2 = analogRead(potPin2);
  value3 = analogRead(potPin3);
  
    button1 = digitalRead(but1); 
    //Joystick.setButton(but1, 1);   
    Serial.println(but1);
    Serial.println(button1);
    
  


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
/*
  //Joytick.setBuuton();
 

            switch (button1) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                   
                    case 1:
                              Joystick.setButton(button1, 1);
                              Serial.println(button1);
                              break;
                    
                    case 0:
                              Joystick.setButton(button1, 0);
                              Serial.println(button1);
                              break;
            }


//Joystick.setButton(button1, 1);
 */
 /*
  if (button1 == HIGH) {
    //if(oldState==LOW){
      Joystick.setButton(button1, 32);
      Serial.println(button1);
      button1=LOW;
      Joystick.setButton(button1, 0);
      //oldState=HIGH;
    //}
    
  } else  {
    //if(oldState==HIGH){
      Joystick.setButton(button1, 0);
      Serial.println(button1);
      //oldState=LOW;
    //}
   }
   //delay(100);
*/
/*
if(button1==LOW){
  Joystick.setButton(button1, 0);
  
}
else{
  Joystick.setButton(button1, 1);
  delay(5000);
  //Joystick.setButton(button1, 0);
}
Joystick.setButton(button1, 0);
*/
}
