#include <Servo.h>

// C++ code
//

Servo servo1;

int motorControl = 7;
int motorSwitch = 11;
int servoControl = 2;
int potRead = A0;
int ledControl = 5;
long int ms100;

void setup()
{
  pinMode(motorControl, OUTPUT);
  pinMode(motorSwitch, INPUT_PULLUP);
  pinMode(ledControl, OUTPUT);
  servo1.attach(servoControl);  
  Serial.begin(9600);
  ms100 = millis();
}

void loop()
{
  
  // Control Motor On / Off
  bool val = digitalRead(motorSwitch);
  if (val) {
    digitalWrite(ledControl, HIGH); // OFF
  	digitalWrite(motorControl, LOW);  
  }
  else {
    digitalWrite(ledControl, LOW); // ON
    digitalWrite(motorControl, HIGH);
  }
  
  // Control Servo Position (every 100ms)
  if (millis() - ms100 > 200) {
    int arm = analogRead(potRead);
    arm = map(arm, 0, 1023, 0, 255); 
    servo1.write(arm); 
    Serial.println(arm);
    ms100 = millis();
  }


}



