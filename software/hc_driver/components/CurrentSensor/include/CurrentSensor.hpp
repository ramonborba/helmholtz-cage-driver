/**
 * \file CurrentSensor.hpp
 * 
 * \brief CurrentSensor class header
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#ifndef _CURRENT_SENSOR_HPP_
#define _CURRENT_SENSOR_HPP_

#include <cstdint>

#include "i2c_cxx.hpp"

class CurrentSensor
{
public:
    CurrentSensor(idf::I2CAddress t_addr);
    ~CurrentSensor();

    uint32_t Read();
private:
    static idf::I2CMaster m_i2c;
    idf::I2CAddress m_addr;
};

#endif /* _CURRENT_SENSOR_HPP_ */
