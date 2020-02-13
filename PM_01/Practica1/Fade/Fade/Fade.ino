#include <Keyboard.h>

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
char ch;
bool charIni = false;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue;
  
  if(Serial.available()> 0) {
    int sr = Serial.read();
    if(sr == 97 or sr == 98)
      ch = sr;
  }
      
     
  switch(ch){
     case 'a':
        sensorValue = analogRead(A0)*10;
  
        if(sensorValue >= 12)
          brightness = 255;
        else
          brightness = 0;
        break;
        
     case 'b':
     default:
        double aux;      
        sensorValue = analogRead(A9);
        
        aux = (double)sensorValue / (double)1023 * (double)255;
        brightness = (int) aux;
  }
 
  analogWrite(led, brightness);
  Serial.println(ch);

  delay(1);
}
