#include "DHT.h"
#include  "Arduino.h"
#include "lcd/Lcd.h"
#include "config.h"
#include "sensors/Sensors.h"
#include "Values.h"
#include "avr/interrupt.h"
#include "sensors/Backlight.h"

Values* obtainedValues;
Lcd* lcd;
Sensors* sensors;
Ultrasonic* proximity;
Backlight* backlight;

#define DHT_TYPE DHT22   // DHT 22

void initInterrupt() {
  cli();
  TCCR1A = 0;
  TCCR1B = 0;

  OCR1A = 31249; //two seconds

  TCCR1B |= (1 << WGM12);

  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);

  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void setup() {

  initInterrupt();
  Serial.begin(9600);
  obtainedValues = new Values();
  lcd = new Lcd(*obtainedValues);
  proximity = new Ultrasonic(PROXIMITY_TRIG, PROXIMITY_ECHO);
  backlight = new Backlight(lcd, proximity);
  sensors = new Sensors(
    *new DHT(DHT_PIN, DHT_TYPE),
    *obtainedValues);
}

void loop() {
 backlight->update();
 lcd->update();
 delay(100);
}

ISR(TIMER1_COMPA_vect) {
  //@TODO update lcd only when new values are measured, otherwise keep the "old" ones
  sensors->update();
}
