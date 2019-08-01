 
#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 90;     // stand horizontal servo

Servo vertical;   // vertical servo
int servov =0;     // stand vertical servo

// LDR pin connections
//  name  = analogpin;

void setup()
{
  Serial.begin(9600);
  // servo connections
  // name.attach(pin);
  horizontal.attach(10);
  vertical.attach(9);
  pinMode(A0,INPUT);
   pinMode(A1,INPUT);
    pinMode(A2,INPUT);
     pinMode(A3,INPUT);
}

void loop()
{
  int lt = analogRead(A0); // top left
  int rt = analogRead(A3); // top right
  int ld = analogRead(A1); // down left
  int rd = analogRead(A2); // down rigt
//Serial.println(lt);
//Serial.println(rt);
//Serial.println(ld);
//Serial.println(rd);
//delay(2000); 

  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt
//Serial.println(dvert);
//Serial.println(dhoriz);
    if (avt > avd&& dvert>112)
    {
      servov = ++servov;
      if (servov > 60)//60
      {
        servov = 60;
      }
   delay(10);
    }
    else if (avt < avd&&(-1*dvert>112))
    {
      servov = --servov;
      if (servov < 0)
      {
        servov = 0;
      }
       delay(10);
     
    }
    vertical.write(servov);
  

  
    if (avl > avr&&dhoriz>61)
    {
      servoh = --servoh;
      if (servoh < 0)
      {
        servoh = 0;
      }
      delay(10); 
    }
    else if (avl < avr&&(-1*dhoriz>61))
    {
      servoh = ++servoh;
      if (servoh > 180)//180
      {
        servoh = 180;
      }
       delay(10);
    }
    else if (avl = avr)
    {
      // nothing
       
    }
    horizontal.write(servoh);
  
 
}
