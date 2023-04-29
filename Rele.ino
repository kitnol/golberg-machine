#define PIN_RELAY 5

const int buttonPin = 2;  // the number of the pushbutton pin
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(buttonPin, INPUT); //defening button as input
  pinMode(PIN_RELAY, OUTPUT); //defining relay as output
  digitalWrite(PIN_RELAY, HIGH); //off relay
  Serial.begin(9600);
}

bool turnedon = false;

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && turnedon == false) {
    turnedon = true;
    digitalWrite(PIN_RELAY, LOW);
    delay(5000);
    digitalWrite(PIN_RELAY, HIGH);
  }
}