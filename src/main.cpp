#include <Arduino.h>
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(7);
}

void loop() {
  M5.update();
  M5.Lcd.setCursor(140, 100);
  if(M5.BtnA.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("A!");
    delay(1000);
  }
  if(M5.BtnB.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("B!");
    delay(1000);
  }
  if(M5.BtnC.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("C!");
    delay(1000);
  } 
}
