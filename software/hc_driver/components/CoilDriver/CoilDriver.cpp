/**
 * \file CoilDriver.cpp
 * 
 * \brief CoilDriver class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 06-12-2023
 */

#include "CoilDriver.hpp"

CoilDriver::CoilDriver(idf::GPIONum t_SourcePin, idf::I2CNumber t_SenI2CNum, idf::SCL_GPIO t_SenSCL, idf::SDA_GPIO t_SenSDA, idf::Frequency t_SenFreq) :
    m_Source { t_SourcePin },
    m_Sensor { t_SenI2CNum, t_SenSCL, t_SenSDA, t_SenFreq } {
}

CoilDriver::~CoilDriver()
{
}

void CoilDriver::SetSource(uint32_t t_Value) {
    m_Source.SetValue(t_Value);
}

uint32_t CoilDriver::ReadCurrent() {
    return m_Sensor.Read();
}