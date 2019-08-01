#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 90;     // stand horizontal servo

Servo vertical;   // vertical servo
int servov =50;    
Servo v,h;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  // servo connections
  // name.attach(pin);
  h.attach(10);
  v.attach(9);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
 h.write(servoh);
 v.write(servov);

 int maxv=0,maxh=0,j;
  
for(j=0;j<300;j++)
{
 
  int lt = analogRead(A0); // top left
  int rt = analogRead(A3); // top right
  int ld = analogRead(A1); // down left
  int rd = analogRead(A2);
  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;//
Serial.print("vert=");
Serial.println(dvert);
Serial.print("horit=");
Serial.println(dhoriz);
  if(dvert>0||(-1*dvert>0))
  {
    if(dvert<0)
    dvert=(-1*dvert);
    if(dvert>maxv)
    maxv=dvert;
  }
  Serial.print("maxv");
  Serial.println(maxv);
    if(dhoriz>0||(-1*dhoriz>0))
  {
    if(dhoriz<0)
    dhoriz=(-1*dhoriz);
    if(dhoriz>maxh)
    maxh=dhoriz;
  }
 Serial.print("maxh");
 Serial.println(maxh);
}
Serial.print("final maxh=");
Serial.println(maxh);
Serial.print("final maxv=");
Serial.println(maxv);
}



void loop()
{
 
 
}
