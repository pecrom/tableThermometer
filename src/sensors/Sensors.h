
#ifndef SENSORS_H
#define  SENSORS_H


#include "DHT.h"
#include "Values.h"


class Sensors {
  private:
    DHT* dhtSensor;
    Values* vals;
    void updateDht22();
    void updateMq135();
  public:
    Sensors(DHT& dhtSensor, Values& vals);
    void update();

};


#endif
