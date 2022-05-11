#include <Arduino.h>
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.printf("Hallo New World");
  
}

void loop() {
  // put your main code here, to run repeatedly:
}