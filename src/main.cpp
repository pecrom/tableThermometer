#include "DHT.h"
#include  "Arduino.h"
#include "lcd/Lcd.h"
#include "config.h"
#include "sensors/Sensors.h"
#include "Values.h"

Values* obtainedValues;
Lcd* lcd;
Sensors* sensors;

#define DHTPIN 12// what digital pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
//DHT dht(7, DHT22);


void setup() {


  Serial.begin(9600);
  obtainedValues = new Values();
  lcd = new Lcd(*obtainedValues);
  sensors = new Sensors(
    *new DHT(DHT_PIN, DHT22),
    *obtainedValues);
}

void loop() {
sensors->update();

 lcd->update();
 delay(200);
  // Wait a few seconds between measurements.
  /*delay(12000);
  Serial.print("Humidity1: ");
  float h = dht.readHumidity();
  Serial.print("Humidity2: ");
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);*/
}

/*#include "DHT.h"
#include  "Arduino.h"
#include "lcd/Lcd.h"
#include "config.h"
#include "sensors/Sensors.h"
#include "Values.h"

Values* obtainedValues;
Lcd* lcd;
Sensors* sensors;

void setup() {
 digitalWrite(LED_BUILTIN, HIGH);
  obtainedValues = new Values();
  lcd = new Lcd(*obtainedValues);
  sensors = new Sensors(
    *new DHT(DHT_PIN, DHT22),
    *obtainedValues);
}

void loop() {
    sensors->update();
    lcd->update();

}
*/
