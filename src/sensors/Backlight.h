#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include "Ultrasonic.h"
#include "lcd/Lcd.h"

class Backlight {
  private:
    static const short TRIGGER_DISTANCE;
    Lcd *display;
    Ultrasonic *proximity;

  public:
    Backlight(Lcd*, Ultrasonic*);
    void update();
};

#endif
