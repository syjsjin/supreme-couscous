#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("DHTxx test!");
dht.begin();  
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
float h = dht.readHumidity();
float t = dht.readTemperature();
// Check if any reads failed and exit early (to try again).
if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
}

Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.println();
} 

