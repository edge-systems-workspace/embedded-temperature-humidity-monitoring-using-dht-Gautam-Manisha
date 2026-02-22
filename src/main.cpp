#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author YOUR_NAME
 * @date YYYY-MM-DD
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */

#include <DHT.h>
#define DHTPIN 2 //
#define DHTTYPE DHT11 //SENSOR TYPE
DHT dht(DHTPIN, DHTTYPE);

// TODO 1:
// Define the DHT data pin (Use digital pin 2)

// TODO 2:
// Define the DHT sensor type (DHT11)

// TODO 3:
// Create a DHT object using the defined pin and sensor type

void setup() {

    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 initialized");
    // write your initialization code here
}

void loop() {

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.print(" | ");
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.println(" °C ");
    delay(2000);
}
