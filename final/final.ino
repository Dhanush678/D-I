#include <Servo.h>
int ena=8;
int m1a = 9;
int m1b = 10;
int m2a = 11;
int m2b = 12;
int enb=13;
char val;
Servo myservo;
#define servoPin 3
int angle = 0;

void setup() 
{  
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);
pinMode (ena,OUTPUT);
pinMode(enb,OUTPUT);// Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
Serial.begin(9600);
 myservo.attach(servoPin);
}

void loop()
{
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);
  }

  if( val == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
      digitalWrite(ena,255);
      digitalWrite(enb,255);
    }
  else if(val == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH); 
       digitalWrite(ena,255);
      digitalWrite(enb,255);
    }
  
    else if(val == 'L') //Left
    {
   
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
        digitalWrite(ena,255);
      digitalWrite(enb,255);
    }
    else if(val == 'R') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
   
        digitalWrite(ena,255);
      digitalWrite(enb,255);
    }
    
  else if(val == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW); 
        digitalWrite(ena,255);
      digitalWrite(enb,255);
    }
    else if(val=='G'){
        myservo.write(90);
    }
    else if(val=='O')                                                                                           {
        myservo.write(180);
    }
 
}
