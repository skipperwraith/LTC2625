#pragma once
//
//    FILE: LTC2625.h
//  AUTHOR: PTE
//    DATE: 15-oct-2025
// VERSION: 0.0.1
// PURPOSE: Arduino library for LTC2625 - 8 channel I2C DAC

#include <Arduino.h>
#include <Wire.h>

#define LTC2625_LIB_VERSION           (F("0.0.1"))

#ifndef LTC2625_INITIAL_VALUE
#define LTC2625_INITIAL_VALUE   0x00
#endif

//I²C Address
#ifndef LTC2625_DEFAULT_ADDRESS
#define LTC2625_DEFAULT_ADDRESS 0x10
#endif
#define LTC2625_BROADCAST_ADDRESS   0x73

//Command
#define LTC2625_WRITE           0x00
#define LTC2625_POWER_UP        0x10
#define LTC2625_MISC            0x20
#define LTC2625_WRITE_UPDATE    0x30
#define LTC2625_POWER_DOWN      0x40

//Address
#define LTC2625_DAC_A           0x00
#define LTC2625_DAC_B           0x01
#define LTC2625_DAC_C           0x02
#define LTC2625_DAC_D           0x03
#define LTC2625_DAC_E           0x04
#define LTC2625_DAC_F           0x05
#define LTC2625_DAC_G           0x06
#define LTC2625_DAC_H           0x07
#define LTC2625_DAC_ALL         0x0F

class LTC2625
{
public:
    LTC2625(const uint8_t deviceAddress = LTC2625_DEFAULT_ADDRESS, TwoWire *wire = &Wire);

    bool    begin(uint16_t value = LTC2625_INITIAL_VALUE);
    bool    isConnected();

    bool    setAddress(const uint8_t deviceAddress);
    uint8_t getAddress() const { return _address; }

    //0x00
    bool    write(const uint8_t channel, const uint16_t value);

    //0x10
    bool    update(const uint8_t channel);

    //0x20
    bool    write_one_n_update_all(const uint8_t channel, const uint16_t value);

    //0x30
    bool    write_n_update(const uint8_t channel, const uint16_t value);

    //0x40
    bool    power_down(const uint8_t channel);

    //manual
    bool    manual(const uint8_t cmd, const uint8_t channel, const uint16_t value);

    //extra func
    bool    write_array(uint16_t (&array)[8], const uint8_t mask = 0xFF);
    bool    write_array(uint16_t (&array)[8]);

private:
    uint8_t _address;

    uint8_t _data[3];
    uint16_t _array[8];
    uint16_t _dataOut {0x0FFF};

    void    data_packer(uint8_t cmd, uint8_t channel, uint16_t value);
    bool    write_array_one(uint16_t (&array)[8], const uint8_t channel);
    bool    write_array_mask(uint16_t (&array)[8], const uint8_t mask = 0xFF);
    bool    transmit();

    TwoWire*  _wire;
};

// -- END OF FILE -- 