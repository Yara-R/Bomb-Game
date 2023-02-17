#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
char cmd;
char resposta;
void setup() {
  Serial.begin(9600);
  lcd.init();
  pinMode(13, OUTPUT);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
}

void loop() {
  lcd.clear();
  cmd = Serial.read();
  if (cmd == 's') {
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Fire in the Hole!!");
    for (int i=60;i>=0;i--){
      cmd=Serial.read();
      lcd.setCursor(0, 1);
      lcd.print(i);
      //lcd.scrollDisplayLeft();
      delay(1000);
      lcd.clear();
      if (i==0 || digitalRead(6)==HIGH || digitalRead(5)==HIGH ){
        lcd.clear();
        lcd.setBacklight(HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Booomb!!");
        lcd.setCursor(0, 1);
        lcd.print("Too bad, you're dead... =X");
        digitalWrite(13, HIGH);
        delay(2000);
      }
      if (i==30){
        lcd.setCursor(0, 0);
        lcd.print("Hurry!!");
      }
      if (digitalRead(7)==HIGH){
        lcd.clear();
        lcd.setBacklight(HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Well done!!");
        delay(40000);
        i=-1;     
      }
      if (i==25){
        lcd.clear();
      }   
    }
  }   
}
