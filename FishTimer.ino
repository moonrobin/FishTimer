#include <Event.h>
#include <Timer.h>

const int buttonPin = 10; 
const int waterLedPin = 12;
const int foodLedPin =  11;     
Timer t;

int buttonState = 0;         

void setup() {
  pinMode(waterLedPin, OUTPUT);   
  pinMode(foodLedPin, OUTPUT);    
  pinMode(buttonPin, INPUT);  
  digitalWrite(waterLedPin, HIGH);
  digitalWrite(foodLedPin, HIGH);  
}

void loop(){
  
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {     
    delay(1000);
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH) {
      digitalWrite(waterLedPin, LOW);
      delay(1000);
      t.after(604800000, waterOn);
    }
    
    else {
      digitalWrite(foodLedPin, LOW);
      t.after(86400000, foodOn);
    } 
  }
  t.update();
}

void foodOn(){
  digitalWrite(foodLedPin, HIGH);
}

void waterOn(){
  digitalWrite(waterLedPin, HIGH);
}


