#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  Wire.setClock(400000);
  dac.begin(0x000);

  // Alle auf 0x200 vorbereiten, dann alle übernehmen
  dac.write(LTC2625_DAC_ALL, 0x200);
  dac.update(LTC2625_DAC_ALL);
}

void loop() {}