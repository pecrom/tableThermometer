#include "StringUtils.h"
#include "Arduino.h"


const short StringUtils::MULTIPLIER = 10;

void StringUtils::floatToChar(char *storage, float number, int precision) {
  int multiplyBy = 1;

  for (int step=0; step < precision; step++) {
    multiplyBy *= MULTIPLIER;
  }
  int floatToInt = number * multiplyBy;
  char intString[20];
  sprintf(intString, "%d", floatToInt);
  int length = strlen(intString);

  strncpy(storage, intString, length - precision);
  storage[length - precision] = 0;

  char *tmpString = &(intString[length - precision]);
  if (precision > 0) {
      sprintf(storage, "%s.%s", storage, tmpString);
  }

}
