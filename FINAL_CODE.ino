#define trigPin 10
#define echoPin 13
int a=2;
int b=3;
int c=4;
int d=5;
int motorPin1=9;
int motorPin2=11;
char command;
float i=1;
float x,t;
int motorValue1=180,motorValue2=180;
void setup()
{
 pinMode(motorPin1, OUTPUT);
 pinMode(motorPin2, OUTPUT);
 pinMode(a,OUTPUT);
 pinMode(b,OUTPUT);
 pinMode(c,OUTPUT);
 pinMode(d,OUTPUT);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT); 
 Serial.begin(9600);
}

int readPing()
{    
     digitalWrite(trigPin,LOW);
     delayMicroseconds(20);
     digitalWrite(trigPin,HIGH);
     delayMicroseconds(1000);
     digitalWrite(trigPin,LOW);
     t=pulseIn(echoPin,HIGH);
     x=(t/2)*0.0343;
     Serial.println(x);
     return(x);
}
void forward()
{ 
   Serial.println("FORWARD");
   analogWrite(motorPin1, motorValue1); 
   analogWrite(motorPin2, motorValue2); 
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,LOW);
   digitalWrite(d,LOW);
   
}

void left()
{ 
   Serial.println("LEFT");
   analogWrite(motorPin1,100); 
   analogWrite(motorPin2, 200); 
   digitalWrite(a,LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   delay(500);
}
void right()
{ 
   Serial.println("RIGHT");
   analogWrite(motorPin1, 200);
   analogWrite(motorPin2, 100);  
   digitalWrite(a,HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   delay(500);
}

void reverse()
{ 
  Serial.println("BACK");
  analogWrite(motorPin1,  motorValue2 ); 
  analogWrite(motorPin2,  motorValue2); 
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  delay(1000);
}

void ideal()
{
  Serial.println("STOP");
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);  
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
}

void check_move()
{   
   i=1;
   while(i<1.03)
        {
          float check= readPing();
          delay(500);
          
          
            if(check>20)
            {  Serial.println("CHECK STATE TRUE");
               forward();
                i=i+0.01;
            }
           else
           {
            Serial.println("CHECK STATE FALSE");
            ideal();
            delay(3000);
           
            
           }
        }
}

 

void loop() 
{

if(Serial.available() > 0)
 { 
    command = Serial.read(); 
   
    switch(command)
    {
    case 'F':  
      forward();
      
      break;
      
    case 'B':  
       reverse();
      break;
      
    case 'L':  
      left();
      ideal();
      break;
      
    case 'R':
      right();
      ideal();
      break;
       case '5':
       ideal();
       break;
      
    case 'P':
     Serial.println("IN DATA P");
     check_move();
     right();
     check_move();
     Serial.println("TARGET REACHED");
     ideal();
     delay(5000);
     right();
     check_move();
     right();
     check_move();
     right();
     Serial.println("BACK TO HUB");
     ideal();
      break;
      
      case 'Q':
      Serial.println("IN DATA Q");
      check_move();
      check_move();
      right();
      check_move();
      check_move();
      Serial.println("TARGET REACHED");
      ideal();
      delay(5000);
      right();
      check_move();
      check_move();
      right();
      check_move();
      check_move();
      right();
      Serial.println("BACK TO HUB");
      ideal();
      break;
      
      case 'X':
      Serial.println("IN DATA R");
      check_move();
      check_move();
      left();
      check_move();
      Serial.println("TARGET reached ");
      ideal();
      delay(5000);
      left();
      check_move();
      check_move();
      left();
      check_move();
      left();
      Serial.println("BACK TO HUB");
      ideal();
      break;
      
      case 'S':
      Serial.println("IN DATA S");
      check_move();
      left();
      check_move();
      check_move();
      Serial.println("Target reached");
      left();
      check_move();
      left();
      check_move();
      check_move();
      left();
      Serial.println("BACK TO HUB");
      ideal();
      break;
      
      case 'T':
      Serial.println("IN DATA T");
      check_move();
      right();
      check_move();
      check_move();
      Serial.println("TARGET REACHED");
      ideal();
      delay(5000);
      right();
      check_move();
      right();
      check_move();
      check_move();
      right();
      Serial.println("BACK TO HUB");
      ideal();
      break;

       case 'Z':
     Serial.println("IN DATA Z");
     check_move();
     left();
     check_move();
     Serial.println("TARGET REACHED");
     ideal();
     delay(5000);
     left();
     check_move();
     left();
     check_move();
     left();
     Serial.println("BACK TO HUB");
     ideal();
      break;

        case 'Y':
      Serial.println("IN DATA Y");
      check_move();
      check_move();
      right();
      check_move();
      Serial.println("TARGET reached ");
      ideal();
      delay(5000);
      right();
      check_move();
      check_move();
      right();
      check_move();
      right();
      Serial.println("BACK TO HUB");
      ideal();
      break;

        case 'W':
      Serial.println("IN DATA W");
      check_move();
      check_move();
      left();
      check_move();
      check_move();
      Serial.println("TARGET REACHED");
      ideal();
      delay(5000);
      left();
      check_move();
      check_move();
      left();
      check_move();
      check_move();
      left();
      Serial.println("BACK TO HUB");
      ideal();
      break;
    }
 }
}
