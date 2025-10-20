#include "LTC2625.h"

LTC2625::LTC2625(uint8_t deviceAddress, TwoWire *wire)
: _address {deviceAddress}, _wire {wire}
{}

bool LTC2625::begin(uint16_t value)
{
    if (! isConnected()) return false;
	LTC2625::write(value, 0x0F);
	LTC2625::update(0x0F);
	if (value == 0x00) LTC2625::power_down(0x0F);
	return true;
}

bool LTC2625::isConnected()
{
	_wire->beginTransmission(_address);
	return ( _wire->endTransmission() == 0);
}

bool LTC2625::setAddress(const uint8_t deviceAddress)
{
	_address = deviceAddress;
	return isConnected();
}

bool LTC2625::write(const uint8_t channel, const uint16_t value)
{
	LTC2625::data_packer(LTC2625_WRITE, channel, value);
	return LTC2625::transmit();
}

bool LTC2625::update(const uint8_t channel)
{
	LTC2625::data_packer(LTC2625_POWER_UP, channel, 0x0000);
	return LTC2625::transmit();
}

bool LTC2625::write_one_n_update_all(const uint8_t channel, const uint16_t value)
{
	LTC2625::data_packer(LTC2625_MISC, channel, value);
	return LTC2625::transmit();
}

bool LTC2625::write_n_update(const uint8_t channel, const uint16_t value)
{
	LTC2625::data_packer(LTC2625_WRITE_UPDATE, channel, value);
	return LTC2625::transmit();
}

bool LTC2625::power_down(const uint8_t channel)
{
	LTC2625::data_packer(LTC2625_POWER_DOWN, channel, 0x0000);
	return LTC2625::transmit();
}

bool LTC2625::manual(const uint8_t cmd, const uint8_t channel, const uint16_t value)
{
    LTC2625::data_packer(cmd, channel, value);
	return LTC2625::transmit();
}

inline void LTC2625::data_packer(uint8_t cmd, uint8_t channel, uint16_t value)
{
    _dataOut = value & 0x0FFF;						// nur 12 Bit
    _data[0] = (cmd & 0xF0) | (channel & 0x0F);		// CCCC AAAA
    _data[1] = (_dataOut >> 4) & 0xFF;				// D11..D4
    _data[2] = (_dataOut << 4) & 0xF0;				// D3..D0
}

bool LTC2625::transmit()
{
	_wire->beginTransmission(_address);
	_wire->write(_data, 3);
	return (_wire->endTransmission() == 0);
}

bool LTC2625::write_array(uint16_t (&array)[8], const uint8_t mask)
{
		return LTC2625::write_array_mask(array, mask);
}

bool LTC2625::write_array(uint16_t (&array)[8])
{
    return LTC2625::write_array(array, 0xFF);
}

inline bool LTC2625::write_array_mask(uint16_t (&array)[8], const uint8_t mask)
{
	uint8_t j = 0;
    for (uint8_t k = 0x01; k !=0; k <<= 1){
		if ((mask & k) == k){
			if (! LTC2625::write_array_one(array, j)) return false;
		}
		j++;
	}
	return true;
}

inline bool LTC2625::write_array_one(uint16_t (&array)[8], const uint8_t channel)
{
    return LTC2625::write(array[channel], channel);
}
