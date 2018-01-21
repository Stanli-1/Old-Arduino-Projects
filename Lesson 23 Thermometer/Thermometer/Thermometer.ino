//www.elegoo.com
//2016.12.9

#include <LiquidCrystal.h>
int tempPin = 0;
int lightPin = 0;
int latchPin = 2;
int clockPin = 3;
int dataPin = 4;
int leds = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  lcd.begin(16, 2);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void displayTemp(float tempF)
{
  lcd.setCursor(0, 0);
  lcd.print("Amount Of Light         ");
  lcd.setCursor(0, 9);
  // Display Temperature in C
  //lcd.print(tempC);
  // Display Temperature in F
  lcd.print(tempF);
}

void loop()
{
  int reading  = analogRead(lightPin);
  int numLEDSLit = reading / 57;  //1023 / 9 / 2
  if (numLEDSLit > 8) numLEDSLit = 8;
  displayTemp(999);
  delay(500);
  updateShiftRegister();
}
