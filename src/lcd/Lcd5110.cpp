#include "Lcd5110.h"

const short Lcd5110::LCD_X = 84;
const short Lcd5110::LCD_Y = 48;
const short Lcd5110::LCD_D = HIGH;
const short Lcd5110::LCD_C = LOW;
const short Lcd5110::LCD_CMD = 0;

const byte Lcd5110::ASCII[][5] =
{
{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
};

Lcd5110::Lcd5110(short pinCe, short pinRst, short pinDc, short pinDin, short pinSclk) {
  this->PIN_CE = pinCe;
  this->PIN_RST = pinRst;
  this->PIN_DC = pinDc;
  this->PIN_DIN = pinDin;
  this->PIN_SCLK = pinSclk;
}

void Lcd5110::lcdClear() {
  for (int index = 0; index < LCD_X * LCD_Y / 8; index++)
  {
    lcdWrite(LCD_D, 0x00);
  }
}

void Lcd5110::lcdCharacter(char charToWrite) {

  lcdWrite(LCD_D, 0x00);
  for (int index = 0; index < 5; index++)
  {
    lcdWrite(LCD_D, ASCII[0][index]);
  }
  lcdWrite(LCD_D, 0x00);
}

void Lcd5110::lcdWrite(byte dc, byte data) {
  digitalWrite(PIN_DC, dc);
  digitalWrite(PIN_CE, LOW);
  shiftOut(PIN_DIN, PIN_SCLK, MSBFIRST, data);
  digitalWrite(PIN_CE, HIGH);
}

void Lcd5110::lcdInitialise() {
  pinMode(PIN_CE, OUTPUT);
  pinMode(PIN_RST, OUTPUT);
  pinMode(PIN_DC, OUTPUT);
  pinMode(PIN_DIN, OUTPUT);
  pinMode(PIN_SCLK, OUTPUT);

  digitalWrite(PIN_RST, LOW);
  digitalWrite(PIN_RST, HIGH);

  lcdWrite(LCD_CMD, 0x21); // LCD Extended Commands.
  lcdWrite(LCD_CMD, 0xBf); // Set LCD Vop (Contrast). //B1
  lcdWrite(LCD_CMD, 0x04); // Set Temp coefficent. //0x04
  lcdWrite(LCD_CMD, 0x14); // LCD bias mode 1:48. //0x13
  lcdWrite(LCD_CMD, 0x0C); // LCD in normal mode. 0x0d for inverse
  lcdWrite(LCD_C, 0x20);
  lcdWrite(LCD_C, 0x0C);
}

void Lcd5110::lcdString(char* stringToWrite) {
  while (*stringToWrite)
  {
    lcdCharacter(*stringToWrite++);
  }
}

void Lcd5110::gotoXY(int x, int y)  {
  lcdWrite( 0, 0x80 | x); // Column.
  lcdWrite( 0, 0x40 | y); // Row.
}
