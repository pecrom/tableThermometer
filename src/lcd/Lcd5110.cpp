#include "Lcd5110.h"

const short Lcd5110::LCD_X = 84;
const short Lcd5110::LCD_Y = 48;
const short Lcd5110::LCD_D = HIGH;
const short Lcd5110::LCD_C = LOW;
const short Lcd5110::LCD_CMD = 0;

const char Lcd5110::INDEX_MAP[] = "CHOTmpu%'.0123456789:";
const byte Lcd5110::ASCII[][5] =
{
{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x00, 0x07, 0x05, 0x07, 0x00} // 60 '
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :

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

int Lcd5110::findCharIndex(char charToFind) {
  char *foundChar = strchr(INDEX_MAP, charToFind);
  int foundIndex = -1;
  if (foundChar != NULL) {
    foundIndex = foundChar - INDEX_MAP;
  }

  return foundIndex;
}

void Lcd5110::lcdCharacter(char charToWrite) {
  lcdWrite(LCD_D, 0x00);
  int charIndex = findCharIndex(charToWrite);
  for (int index = 0; index < 5; index++)
  {
    lcdWrite(LCD_D, ASCII[charIndex][index]);
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

void Lcd5110::lcdString(const char* stringToWrite) {
  while (*stringToWrite)
  {
    lcdCharacter(*stringToWrite++);
  }
}

void Lcd5110::gotoXY(int x, int y)  {
  lcdWrite( 0, 0x80 | x); // Column.
  lcdWrite( 0, 0x40 | y); // Row.
}

void Lcd5110::drawBox() {
  int j;
  for(j = 0; j < 84; j++) // top
  {
    gotoXY(j, 0);
    lcdWrite(1, 0x01);
  }

  for(j = 0; j < 84; j++) //Bottom
  {
    gotoXY(j, 5);
    lcdWrite(1, 0x80);
  }

  for(j = 0; j < 6; j++) // Right
  {
    gotoXY(83, j);
    lcdWrite(1, 0xff);
  }

  for(j = 0; j < 6; j++) // Left
  {
    gotoXY(0, j);
    lcdWrite(1, 0xff);
  }
}
