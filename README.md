# LTC2625 Arduino Library

Arduino library for the LTC2625 – an 8-channel, 12-bit I²C Digital-to-Analog Converter (DAC) from Analog Devices / Linear Technology.

---

## Features
- Supports all LTC2625 commands:
  - Write (load input register)
  - Update (Power-Up) (transfer to DAC register)
  - Write + Update (n) (single transaction per channel)
  - Write (n) + Update ALL
  - Power-Down (per channel or ALL)
- Handles ALL channels or individual channels.
- Masked array write for multiple channels.
- Type-safe array interface for 8 channels.
- Compatible with any Arduino board supporting Wire (I²C).

---

## Installation

Arduino IDE:
- Library Manager: Search for LTC2625.
- Manual: Download ZIP and use Sketch → Include Library → Add .ZIP Library.
---

## Quick Usage Example
Initialize the Wire library, create an LTC2625 object, call begin() to set all channels to zero, then use write_n_update() to set a channel to mid-scale. For example, set channel A to 0x800 after initialization.

---

## API Overview

Constructor:
LTC2625(uint8_t deviceAddress = 0x10, TwoWire* wire = &Wire)

Core Methods:
- begin(uint16_t value = 0x000)
- isConnected()
- setAddress(uint8_t deviceAddress)
- getAddress() const
- write(uint8_t channel, uint16_t value)
- update(uint8_t channel)
- write_one_n_update_all(uint8_t channel, uint16_t value)
- write_n_update(uint8_t channel, uint16_t value)
- power_down(uint8_t channel)
- manual(uint8_t cmd, uint8_t channel, uint16_t value)

Array Methods:
- write_array(uint16_t (&array)[8], uint8_t mask = 0xFF)
- write_array(uint16_t (&array)[8])

---

## Channel Constants
LTC2625_DAC_A ... LTC2625_DAC_H (0x00 ... 0x07)
LTC2625_DAC_ALL (0x0F)

---

## I²C Addresses
- Default: 0x10 (CA2..CA0 = GND)
- Broadcast: 0x73 (updates all LTC2625 devices on the bus)

---

## License
MIT License. See LICENSE for details.
