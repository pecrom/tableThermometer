#include "Values.h"
#include "Arduino.h"

Values::Values() {
  humidity = 99.9;
  temperature = 32.5;
  co2 = 1028;
}

void Values::setHumidity(float humidity) {
  assignIfDifferent(this->humidity, humidity);
}

void Values::setTemperature(float temperature) {
  assignIfDifferent(this->temperature, temperature);
}

void Values::setCo2(short co2) {
  if (this->co2 != co2) {
    this->co2 = co2;
  }
}

short Values::getCo2() {
  return co2;
}

float Values::getHumidity() {
  return humidity;
}

float Values::getTemperature() {
  return temperature;
}

void Values::assignIfDifferent(float &oldValue, float newValue) {
  if (!isnan(newValue) && oldValue != newValue) {
    oldValue = newValue;
  }
}
