#include "Sensors.h"
#include "Arduino.h"



Sensors::Sensors(DHT& dhtSensor, Values& vals) {
  this->dhtSensor = &dhtSensor;
  this->vals = &vals;
  this->dhtSensor->begin();
}

void Sensors::update() {
  updateDht22();
  updateMq135();
}

void Sensors::updateMq135() {

}

void Sensors::updateDht22() {
  delay(6000);
  Serial.print(dhtSensor->readHumidity());
  if (!isnan(dhtSensor->readHumidity())){

    vals->setHumidity(dhtSensor->readHumidity());
    vals->setTemperature(dhtSensor->readTemperature());
  }
}
