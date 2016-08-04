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
    static const short HUM_VAL_LEFT_MARGIN;
    char humStr[6];
    char tmpStr[6];
    char co2Str[5];
    short humValueX;
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
