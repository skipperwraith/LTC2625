#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;  // starts with normal address (0x10)

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // Temporarily switch to broadcast:
  if (dac.setAddress(LTC2625_I2C_BROADCAST)) {
    // All LTC26x5 on the bus: set ALL outputs to 0x700 immediately
    dac.write_n_update(LTC2625_DAC_ALL, 0x700);

    // Switch back to the dedicated device address
    dac.setAddress(0x10);
  }
}

void loop() {}