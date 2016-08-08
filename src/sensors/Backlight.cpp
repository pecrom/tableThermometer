#include "sensors/Backlight.h"

const short Backlight::TRIGGER_DISTANCE = 15;

Backlight::Backlight(Lcd *display, Ultrasonic *proximity) {
  this->display = display;
  this->proximity = proximity;
}

void Backlight::update() {
  if (proximity->Ranging(CM) < TRIGGER_DISTANCE) {
    display->setLightOn(true);
  } else {
    display->setLightOn(false);
  }
}
