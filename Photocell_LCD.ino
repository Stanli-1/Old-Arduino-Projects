//www.elegoo.com
//2016.12.9

#include <LiquidCrystal.h>
int lightPin = 0;
int latchPin = 3;
int clockPin = 2;
int dataPin = 5;

int leds = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  lcd.begin(16, 2);
}

void displayTemp(int light)
{
  lcd.setCursor(0, 0);
  lcd.print("                                          ");
  lcd.setCursor(0, 0);
  if (light <= 1)
  {
    lcd.print("88");
  }
  else if (light > 1 && light <= 2)
  {
    lcd.print("8888");
  }
  else if (light > 2 && light <= 3)
  {
    lcd.print("888888");
  }
  else if (light > 3 && light <= 4)
  {
    lcd.print("88888888");
  }
  else if (light > 4 && light <= 5)
  {
    lcd.print("8888888888");
  }
  else if (light > 5 && light <= 6)
  {
    lcd.print("888888888888");
  }
  else if (light > 6 && light <= 7)
  {
    lcd.print("88888888888888");
  }
  else
  {
    lcd.print("8888888888888888");
  }

  lcd.setCursor(0, 9);
  lcd.print(light);
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
void loop() 
{
  int reading  = analogRead(lightPin);
  int numLEDSLit = reading / 57;  //1023 / 9 / 2
  if (numLEDSLit > 8) numLEDSLit = 8;
  leds = 0;   // no LEDs lit to start
  for (int i = 0; i < numLEDSLit; i++)
  {
    leds = leds + (1 << i);  // sets the i'th bit
  }
  displayTemp(numLEDSLit);
  updateShiftRegister();
  delay(50);
}


