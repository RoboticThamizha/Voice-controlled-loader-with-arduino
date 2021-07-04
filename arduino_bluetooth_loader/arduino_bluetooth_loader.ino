//Coded by Robotic Thamizha YouTube Channel
#include <Servo.h> //define servo library

String voice;


const int LMF = A0;//define left motor forward pin(in 1) in motordrive
const int LMB = A1;//define left motor backward pin(in 2) in motordrive
const int RMF = A2;//define right motor forward pin(in 3) in motordrive
const int RMB = A3;//define right motor backward pin(in 4) in motordrive

Servo mylh1;


void setup()
{
  Serial.print(9600);//Start Serial communication
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  mylh1.attach(8);
  mylh1.write(90);   
}

void loop()
{
  if (Serial.available())
  {
  String voice = Serial.readString();
  Serial.println(voice);

   if (voice == "move forward"){
     forward_loader();
    }
   if (voice == "move back"){
     back_loader();
    }
    if (voice == "turn right"){
     right_loader();
    }
    if (voice == "turn left"){
     left_loader();
    }
    if (voice == "arm up"){
     arm_up();
    }
    if (voice == "arm down"){
     arm_down();
    }
    
   }
}

void forward_loader()
{
  digitalWrite(LMF, HIGH);   
    digitalWrite(RMF, HIGH);  
                                             
    digitalWrite(LMB, LOW);   
    digitalWrite(RMB, LOW);  
                                            
     delay(3000);                         
                                             
     digitalWrite(LMF, LOW);    
    digitalWrite(RMF, LOW);   
  
     digitalWrite(LMB, LOW);
     digitalWrite(RMB, LOW);
}

void back_loader()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, HIGH);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);

  delay(3000);

  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW); 
}

void right_loader()
{
  digitalWrite(LMB, LOW);
  digitalWrite(RMF, LOW);
  
  delay(1500);
  
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
 
   digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void left_loader()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);

  delay(1500);
  
  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);
  
  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);

   digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void arm_up()
{
  mylh1.write(180);
  delay(500);
}

void arm_down()
{
  mylh1.write(90);
  delay(500);
}
