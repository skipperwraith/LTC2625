#include <Wire.h>
#include "LTC2625.h"

LTC2625 dac;  // startet mit 0x10

void setup() {
  Wire.begin();
  Serial.begin(115200);

  if (!dac.isConnected()) {
    Serial.println(F("DAC @0x10 nicht erreichbar"));
    while (1) {}
  }

  // Wenn dein Hardware‑Board z. B. auf 0x12 gejumpert ist:
  if (dac.setAddress(0x12)) {
    Serial.print(F("Neue Adresse gesetzt: 0x"));
    Serial.println(dac.getAddress(), HEX);
  } else {
    Serial.println(F("Adresse 0x12 nicht erreichbar"));
  }

  // Normal weiterarbeiten …
  dac.begin(0x000);
  dac.write_n_update(LTC2625_DAC_A, 0x555);
}

void loop() {}
``