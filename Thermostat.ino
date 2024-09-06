// Thermostat
#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int adc,T,SetPoint; 

void setup(){ 
  pinMode(10,HIGH);  
  lcd.begin(16, 2); 
  lcd.print("   Thermostat   ");
  lcd.setCursor(0, 1);
  lcd.print("    ARDUINO     ");
  delay(2000);
  lcd.clear();
  lcd.print("SP=");
  lcd.print(SP);
  lcd.setCursor(0, 1);
  lcd.print("Stat=");
  SetPoint=50;  
}

void loop(){
  adc = analogRead(0);    
  T=(adc*5)/10;  
  lcd.setCursor(7, 0);
  lcd.print("T=");  
  lcd.print(T);
  if(T<SetPoint){
      lcd.setCursor(5,1);
      lcd.print("Heater ON ");
      digitalWrite(10,HIGH);
  }
  else{
      lcd.setCursor(5,1);
      lcd.print("Heater OFF");
      digitalWrite(10,LOW);
  }
  delay(1000);  
}

