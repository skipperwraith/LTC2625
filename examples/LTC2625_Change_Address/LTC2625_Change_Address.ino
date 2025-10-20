#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;  // defaults to 0x10

void setup() {
  Wire.begin();
  Serial.begin(115200);

  if (!dac.isConnected()) {
    Serial.println(F("DAC @0x10 not reachable"));
    while (1) {}
  }

  // Example: your board might be strapped to 0x12
  if (dac.setAddress(0x12)) {
    Serial.print(F("New address set: 0x"));
    Serial.println(dac.getAddress(), HEX);
  } else {
    Serial.println(F("Address 0x12 not reachable"));
  }

  // Continue normal operation…
  dac.begin(0x000);
  dac.write_n_update(LTC2625_DAC_A, 0x555);
}

void loop() {}