#include "Values.h"
#include "Arduino.h"

const bool Values::CHANGED = true;
const bool Values::NOT_CHANGED = false;

Values::Values() {
  humidity = 99.9;
  temperature = 32.5;
  co2 = 1028;
}

bool Values::setHumidity(float humidity) {
  return assignIfDifferent(this->humidity, humidity);
}

bool Values::setTemperature(float temperature) {
  return assignIfDifferent(this->temperature, temperature);
}

bool Values::setCo2(short co2) {
  if (this->co2 != co2) {
    this->co2 = co2;
    return CHANGED;
  }
  return NOT_CHANGED;
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

bool Values::assignIfDifferent(float &oldValue, float newValue) {
  if (!isnan(newValue) && oldValue != newValue) {
    oldValue = newValue;
    return CHANGED;
  }

  return NOT_CHANGED;
}
