#ifndef LCD_H
#define  LCD_H

#include "Values.h"
#include "config.h"
#include "Lcd5110.h"

class Lcd {
  private:
    Lcd5110* display;
    Values* vals;
    static const char *HUMIDITY_LABEL;
    static const char *TEMPERATURE_LABEL;
    static const char *CO2_LABEL;
    static const short CONTRAST;
    static const int16_t RECT_X;
    static const int16_t RECT_Y;
    static const int16_t RECT_W;
    static const int16_t RECT_H;
    static const int16_t RECT_COLOR;
    void initDisplay();
    void prepareUI();
    void showValues();
    void showHumidity();
    void showTemperature();
    void showCo2();

  public:
    Lcd(Values& vals);
    void update(void);
};

#endif
