#include <SoftwareSerial.h>

int Pin1 = 10;//IN1 is connected to 10 
int Pin2 = 11;//IN2 is connected to 11  
int Pin3 = 12;//IN3 is connected to 12  
int Pin4 = 13;//IN4 is connected to 13 
int switchCW  =2;//define input pin for CW push button
int switchCCW =4;//define input pin for CCW push button

int pole1[] = {0,0,0,0, 0,1,1,1, 0};//pole1, 8 step values
int pole2[] = {0,0,0,1, 1,1,0,0, 0};//pole2, 8 step values
int pole3[] = {0,1,1,1, 0,0,0,0, 0};//pole3, 8 step values
int pole4[] = {1,1,0,0, 0,0,0,1, 0};//pole4, 8 step values

int dirStatus = 3;// stores direction status 3= stop (do not change)

void setup() {
  //define pins for step motor
  pinMode(Pin1, OUTPUT); // in1
  pinMode(Pin2, OUTPUT); // in2
  pinMode(Pin3, OUTPUT); // in3
  pinMode(Pin4, OUTPUT); // in4

  pinMode(switchCW, INPUT);
  pinMode(switchStop, INPUT);
  pinMode(switchCCW, INPUT);
}
int times = 0;
void loop() {
  // put your main code here, to run repeatedly:

  if(times%2 == 0)
  {
    driveStepper(4096, true);
  }

  if(times%2 == 1)
  {
    driveStepper(4096, false);
  }
  delay(1000);
  times++;
}


void driveStepper(int steps, bool ClockWise)
{
  int c;
  if(ClockWise == true)
  {
    c = 0;

    for(int i=0; i<steps; i++)
    {
      digitalWrite(Pin1, pole1[c]);  
      digitalWrite(Pin2, pole2[c]); 
      digitalWrite(Pin3, pole3[c]); 
      digitalWrite(Pin4, pole4[c]);

      c++;
      if(c>7)
        c = 0;
      delay(1);
    }
  }

  if(ClockWise == false)
  {
      c = 7;

      for(int i=0; i<steps; i++)
    {
      digitalWrite(Pin1, pole1[c]);  
      digitalWrite(Pin2, pole2[c]); 
      digitalWrite(Pin3, pole3[c]); 
      digitalWrite(Pin4, pole4[c]);

      c--;
      if(c<0)
        c = 7;
      delay(1);
    }
  }
}