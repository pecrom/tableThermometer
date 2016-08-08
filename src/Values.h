#ifndef VALUES_H
#define  VALUES_H

class Values {
  private:
    static const bool CHANGED;
    static const bool NOT_CHANGED;
    float humidity;
    float temperature;
    short co2;

    bool assignIfDifferent(float &oldValue, float newValue);

  public:
    Values(void);
    bool setHumidity(float);
    bool setTemperature(float);
    bool setCo2(short);
    float getHumidity(void);
    float getTemperature(void);
    short getCo2(void);
};

#endif
