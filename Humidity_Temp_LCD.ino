// Define DHT values and Crystal
#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPin 8
#define DHTTYPE DHT11
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPin, DHTTYPE);
void setup() {
  // Begin DHT and LCD
  dht.begin(); // Start Sensor
  lcd.begin(16, 2); // LCD screen is 16 with 2 lines
}

void loop() {
  // Read value for Humidity and Temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Change from Celcius to Fahrenheit
  t = t * 9/ 5 + 32;

  // Check if sensor is working
  if (isnan(t) || isnan(h)){
    lcd.setCursor(0, 0);
    lcd.print("Failed to read from DHT");
    }
  // else show the results
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(h);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("f");
    }
}
