#ifndef Lcd5110_H
#define  Lcd5110_H

#include "Arduino.h"

class Lcd5110 {
  private:
    short PIN_CE;
    short PIN_RST;
    short PIN_DC;
    short PIN_DIN;
    short PIN_SCLK;
    static const short LCD_D;
    static const short LCD_C;
    static const short LCD_X;
    static const short LCD_Y;
    static const short LCD_CMD;
    static const byte ASCII[][5];
    void lcdWrite(byte, byte);

  public:
    Lcd5110(short, short, short, short, short);
    void lcdClear();
    void lcdCharacter(char);
    void lcdInitialise(void);
    void lcdString(char*);
    void gotoXY(int, int);

};

#endif
