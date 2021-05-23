
#include <Servo.h>

Servo thumb, fingers;

int analogpin = 3;
int val = 0;
boolean r;
  void setup()
  {
    fingers.attach(9);  //Attach the servo for the four fingers to pin9
    thumb.attach(8);   // Attach the servo for the thumb to pin 8
pinMode(13, OUTPUT);
pinMode(A0, INPUT);
    Serial.begin(9600);  // this is for serial moniter to see the muscle sensor value you're getting
  }
  void loop()
{ 
   val = analogRead(A0);
   Serial.println(val);
  if( val < 150) //if you flex and the sensor value is greater than 550 then close servos--adjust this value to your muscle sensor value
  {
   Serial.println("Rileks");
    thumb.write(180);
    fingers.write(0); 
  }
else{
     Serial.println("Kontraksi");
    thumb.write(0);
    fingers.write(180); 
  }
}
