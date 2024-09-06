# Thermostat with LCD and Heater Control

## Description

This project implements a simple thermostat using an Arduino. It reads the temperature from an analog sensor, displays the current temperature and set point on a 16x2 LCD, and controls a heater based on the set point. The heater turns on if the temperature is below the set point and turns off once it exceeds the threshold.

## Components

- Arduino Uno
- 16x2 LCD Display
- Temperature sensor (analog input)
- Relay module or transistor to control the heater
- Heater (simulated by an LED or actual heater for practical use)
- Jumper wires
- Breadboard

## Libraries Required

- **LiquidCrystal.h**: For handling the 16x2 LCD display.

## Wiring Diagram

| Component          | Arduino Pin |
| ------------------ | ----------- |
| LCD RS             | 2           |
| LCD Enable         | 3           |
| LCD D4             | 4           |
| LCD D5             | 5           |
| LCD D6             | 6           |
| LCD D7             | 7           |
| Temperature Sensor | A0          |
| Heater (Relay/LED) | 10          |

## Code

```cpp
#include <LiquidCrystal.h>

// Initialize the LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int adc, T, SetPoint;

void setup(){
  pinMode(10, OUTPUT);  // Pin 10 controls the heater
  lcd.begin(16, 2);     // Initialize LCD (16 columns, 2 rows)

  lcd.print("   Thermostat   ");
  lcd.setCursor(0, 1);
  lcd.print("    ARDUINO     ");
  delay(2000);

  lcd.clear();
  lcd.print("SP=");
  SetPoint = 50;         // Set the desired temperature (Set Point)
  lcd.print(SetPoint);
  lcd.setCursor(0, 1);
  lcd.print("Stat=");
}

void loop(){
  adc = analogRead(0);    // Read analog value from the temperature sensor
  T = (adc * 5) / 10;     // Convert ADC reading to temperature

  lcd.setCursor(7, 0);
  lcd.print("T=");
  lcd.print(T);

  // Check if the current temperature is below the set point
  if(T < SetPoint){
      lcd.setCursor(5, 1);
      lcd.print("Heater ON ");
      digitalWrite(10, HIGH);  // Turn on the heater
  } else {
      lcd.setCursor(5, 1);
      lcd.print("Heater OFF");
      digitalWrite(10, LOW);   // Turn off the heater
  }

  delay(1000);  // Update the display and control every second
}
```

## How It Works

1. Temperature Reading: The analog temperature sensor connected to pin A0 provides a raw analog value, which is converted into a temperature (T).
2. Set Point: The target temperature (set point) is hardcoded to 50°C, but this can be adjusted in the code.
3. LCD Display: The current temperature and set point are shown on a 16x2 LCD.
4. Heater Control: The thermostat compares the current temperature (T) to the set point. If the temperature is lower, the heater is turned on (via pin 10). If the temperature exceeds the set point, the heater is turned off.
5. Delay: The loop runs every second to update the temperature reading and control the heater.

## Usage

1. Connect the components according to the wiring diagram.
2. Upload the code to your Arduino.
3. Monitor the LCD display for the current temperature (T) and the heater status.
4. The heater will turn on and off based on whether the temperature is below or above the set point.

## Applications

- Simple thermostat for home heating systems.
- Educational projects demonstrating control systems and temperature monitoring.
