#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;

void setup() {
  Wire.begin();
  dac.begin(0x000);

  // MANUAL write ALL to 0x250...
  dac.manual(LTC2625_WRITE, LTC2625_DAC_ALL, 0x250);
  // ...and MANUAL update ALL (data bytes are don't care)
  dac.manual(LTC2625_POWER_UP, LTC2625_DAC_ALL, 0x0000);

  // MANUAL write+update for channel H:
  dac.manual(LTC2625_WRITE_UPDATE, LTC2625_DAC_H, 0x9AB);

  // MANUAL power down ALL:
  dac.manual(LTC2625_POWER_DOWN, LTC2625_DAC_ALL, 0x0000);
}

void loop() {}