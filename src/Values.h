#ifndef VALUES_H
#define  VALUES_H

class Values {
  private:
    float humidity;
    float temperature;
    short co2;

    void assignIfDifferent(float &oldValue, float newValue);

  public:
    Values(void);
    void setHumidity(float);
    void setTemperature(float);
    void setCo2(short);
    float getHumidity(void);
    float getTemperature(void);
    short getCo2(void);
};

#endif
