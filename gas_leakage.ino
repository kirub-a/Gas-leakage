#include<Servo.h>
Servo servo;

int gas = 0;
int m1a=5;
int m1b=6;

void setup() 
{
pinMode(2 ,INPUT); //gas sensor analog output pin is connceted to arduino pin 2.
servo.attach(9); //servo orange wire is connceted to pin 9.
Serial.begin(9600);
}

void loop() 
{
  servo.write(0); //default positions
  digitalWrite(5,LOW); 
  digitalWrite(6,HIGH);
  gas=analogRead(2);
  Serial.println(gas);
  if(gas>600) //"600" is the reference value.
  {
    servo.write(90); //gas knob is closed.
    delay(2000);
    digitalWrite(5,HIGH); //window is opned.
    digitalWrite(6,LOW);
    delay(1000);
  }
  delay(100);
}
