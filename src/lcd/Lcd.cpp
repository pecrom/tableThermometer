#include "Lcd.h"
#include "config.h"
#include "utils/StringUtils.h"

const char *Lcd::HUMIDITY_LABEL = "Hum:\0";
const char *Lcd::TEMPERATURE_LABEL = "Tmp:\0";
const char *Lcd::CO2_LABEL = "CO2:\0";
const short Lcd::HUM_VAL_LEFT_MARGIN = 33;

Lcd::Lcd(Values& vals) {
  this->vals = &vals;
  humValueX = strlen(HUMIDITY_LABEL) + 1;
  Serial.print("humValueX: ");
  Serial.print(humValueX);
  Serial.print('\n');
  initDisplay();
  prepareUI();
}

void Lcd::initDisplay() {
  //pinCe, pinRst, pinDc, pinDin, pinSclk
  display = new Lcd5110(LCD_CE, LCD_RST, LCD_DC, LCD_DIN, LCD_SCLK);
  display->lcdInitialise();
}

void Lcd::update(void) {
  showValues();
}

void Lcd::showValues() {
  showHumidity();
  showTemperature();
  showCo2();
  /*->setCursor(3, 20);
  showTemperature();
  display->setCursor(3, 37);
  showCo2();*/
}

void Lcd::showHumidity() {
  StringUtils::floatToChar(humStr, vals->getHumidity(), 1);
  display->gotoXY(HUM_VAL_LEFT_MARGIN, 1);
  display->lcdString(humStr);
  display->lcdCharacter('%');
}

void Lcd::showTemperature() {
  StringUtils::floatToChar(tmpStr, vals->getTemperature(), 1);
  display->gotoXY(HUM_VAL_LEFT_MARGIN, 2);
  display->lcdString(tmpStr);
  display->lcdString("'C");
}

void Lcd::showCo2() {
  StringUtils::floatToChar(co2Str, vals->getCo2(), 0);
  display->gotoXY(HUM_VAL_LEFT_MARGIN, 3);
  display->lcdString(co2Str);
  display->lcdString("ppm");
/*  display->print(CO2_LABEL);
  display->print(vals->getCo2());
  display->setCursor(display->getCursorX() + 1, display->getCursorY());
  display->print("ppm");*/
}

void Lcd::prepareUI() {
  display->lcdClear();
  display->drawBox();
  display->gotoXY(3, 1);
  display->lcdString(HUMIDITY_LABEL);
  display->gotoXY(3, 2);
  display->lcdString(TEMPERATURE_LABEL);
  display->gotoXY(3, 3);
  display->lcdString(CO2_LABEL);

}
