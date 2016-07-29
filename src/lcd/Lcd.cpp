#include "Lcd.h"
#include "config.h"

const char *Lcd::HUMIDITY_LABEL = "Hum: \0";
const char *Lcd::TEMPERATURE_LABEL = "Tmp: \0";
const char *Lcd::CO2_LABEL = "CO2: \0";
const short Lcd::CONTRAST = 60;
const int16_t Lcd::RECT_X = 0;
const int16_t Lcd::RECT_Y = 0;
const int16_t Lcd::RECT_W = 84;
const int16_t Lcd::RECT_H = 48;
const int16_t Lcd::RECT_COLOR = 1;

Lcd::Lcd(Values& vals) {
  this->vals = &vals;
  Serial.print("before initDisplay");
  initDisplay();
}

void Lcd::initDisplay() {
  //short pinCe, short pinRst, short pinDc, short pinDin, short pinSclk
  display = new Lcd5110(LCD_CE, LCD_RST, LCD_DC, LCD_DIN, LCD_SCLK);
  display->lcdInitialise();
}

void Lcd::update(void) {
  //display->lcdClear();
//  display->gotoXY(7, 1);
  display->lcdCharacter('0');
  //prepareUI();
//  showValues();
//  display->display();
}

void Lcd::showValues() {
  //display->setCursor(3, 3);
  //showHumidity();
  /*->setCursor(3, 20);
  showTemperature();
  display->setCursor(3, 37);
  showCo2();*/
}

void Lcd::showHumidity() {
/*  display->print(HUMIDITY_LABEL);
  display->print(vals->getHumidity());
  display->print('%');*/
}

void Lcd::showTemperature() {
/*  display->print(TEMPERATURE_LABEL);
  display->print(vals->getTemperature());
  display->print("'C");*/
}

void Lcd::showCo2() {
/*  display->print(CO2_LABEL);
  display->print(vals->getCo2());
  display->setCursor(display->getCursorX() + 1, display->getCursorY());
  display->print("ppm");*/
}





void Lcd::prepareUI() {
/*  display->clearDisplay();
  display->drawRect(RECT_X, RECT_Y, RECT_W, RECT_H, RECT_COLOR);*/
}
