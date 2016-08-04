#include "DHT.h"
#include  "Arduino.h"
#include "lcd/Lcd.h"
#include "config.h"
#include "sensors/Sensors.h"
#include "Values.h"
#include "avr/interrupt.h"

Values* obtainedValues;
Lcd* lcd;
Sensors* sensors;

#define DHTPIN 12// what digital pin we're connected to

#define DHTTYPE DHT22   // DHT 22

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
  sensors = new Sensors(
    *new DHT(DHT_PIN, DHT22),
    *obtainedValues);
}

void loop() {
 lcd->update();
 delay(100);
}

ISR(TIMER1_COMPA_vect) {
  sensors->update();
}
