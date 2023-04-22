int Pin1 = 10;//IN1 is connected to 10 
int Pin2 = 11;//IN2 is connected to 11  
int Pin3 = 12;//IN3 is connected to 12  
int Pin4 = 13;//IN4 is connected to 13

int switchON  =2;//define input pin for CW push button
int switchOFF =4;//define input pin for CCW push button

int pole1[] = {0,0,0,0, 0,1,1,1, 0};//pole1, 8 step values
int pole2[] = {0,0,0,1, 1,1,0,0, 0};//pole2, 8 step values
int pole3[] = {0,1,1,1, 0,0,0,0, 0};//pole3, 8 step values
int pole4[] = {1,1,0,0, 0,0,0,1, 0};//pole4, 8 step values

void setup() {
  //define pins for step motor
  pinMode(Pin1, OUTPUT); // in1
  pinMode(Pin2, OUTPUT); // in2
  pinMode(Pin3, OUTPUT); // in3
  pinMode(Pin4, OUTPUT); // in4

  pinMode(switchON, INPUT);
  pinMode(switchOFF, INPUT);

  Serial.begin(9600);
}

bool turnedON = false;
bool turnedOFF = false;

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(Pin1, pole1[8]);  
  digitalWrite(Pin2, pole2[8]); 
  digitalWrite(Pin3, pole3[8]); 
  digitalWrite(Pin4, pole4[8]);
  //Serial.println("Started");
  if(turnedON == false && digitalRead(switchON) == HIGH)
  {
    Serial.println("ON");
    driveStepper(1028, true);
    turnedON = true;
  }

  if(turnedOFF == false && digitalRead(switchOFF) == HIGH)
  {
    Serial.println("OFF");
    driveStepper(1028, false);
    turnedOFF = true;
  }
}


void driveStepper(int steps, bool ClockWise)
{
  int c;
  if(ClockWise == false)
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

  if(ClockWise == true)
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