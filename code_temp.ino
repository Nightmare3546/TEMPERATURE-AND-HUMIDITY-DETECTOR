#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 7  
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);


LiquidCrystal_I2C lcd(0x3F, 16, 2);


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
  
  delay(1000);
}


void loop() {
 float temp=dht.readTemperature();
  float tempf=dht.readTemperature(true);
  float humidity=dht.readHumidity();
  Serial.println("Temperature : ");
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Temp : ");
  lcd.print(tempf);
  lcd.print(" F");
  delay(10000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(5000);
  lcd.clear();
}