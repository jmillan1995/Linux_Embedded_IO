#include <Wire.h>
#include <iostream>
#include <Arduino.h>
#include <cstdint>
#ifndef _MCP23017_h
#define _Adafruit_MCP23017_H_


namespace MCP23017
{
	
	namespace Registers
	{
		/*
		Registers of MCP23017 PORTA
		*/
		constexpr std::uint8_t MCP23017_IODIRA   =0x00U;
		constexpr std::uint8_t MCP23017_IPOLA    =0x02U;
		constexpr std::uint8_t MCP23017_GPINTENA =0x04U;
		constexpr std::uint8_t MCP23017_DEFVALA  =0x06U;
		constexpr std::uint8_t MCP23017_INTCONA  =0x08U;
		constexpr std::uint8_t MCP23017_IOCONA   =0x0AU;
		constexpr std::uint8_t MCP23017_GPPUA    =0x0CU;
		constexpr std::uint8_t MCP23017_INTFA    =0x0EU;
		constexpr std::uint8_t MCP23017_INTCAPA  =0x10U;
		constexpr std::uint8_t MCP23017_GPIOA    =0x12U;
		constexpr std::uint8_t MCP23017_OLATA    =0x14U;
		/*
		Registers of MCP23017 PORTB
		*/
		constexpr std::uint8_t MCP23017_IODIRB   =0x01U;
		constexpr std::uint8_t MCP23017_IPOLB    =0x03U;
		constexpr std::uint8_t MCP23017_GPINTENB =0x05U;
		constexpr std::uint8_t MCP23017_DEFVALB  =0x07U;
		constexpr std::uint8_t MCP23017_INTCONB  =0x09U;
		constexpr std::uint8_t MCP23017_IOCONB   =0x0BU;
		constexpr std::uint8_t MCP23017_GPPUB    =0x0DU;
		constexpr std::uint8_t MCP23017_INTFB    =0x0FU;
		constexpr std::uint8_t MCP23017_INTCAPB  =0x11U;
		constexpr std::uint8_t MCP23017_GPIOB    =0x13U;
		constexpr std::uint8_t MCP23017_OLATB    =0x15U;

		constexpr std::uint8_t MCP23017_INT_ERR   =255;
	}
	namespace Port
	{
		namespace PortBits
		{
			constexpr std::uint8_t pin0          =1U;
			constexpr std::uint8_t pin1          =1U<<1U;
			constexpr std::uint8_t pin2          =1U<<2U;
			constexpr std::uint8_t pin3          =1U<<3U;
			constexpr std::uint8_t pin4			 =1U<<4U;
			constexpr std::uint8_t pin5          =1U<<5U;
			constexpr std::uint8_t pin6          =1U<<6U;
			constexpr std::uint8_t pin7			 =1U<<7U;
		} 
		}
		namespace IO
		{
			constexpr std:uint8_t I              =1U;
			constexpr std:uint8_t                =0U;
		}
	}
}

template <typename Size>
class MCP23017_Expander:
{
	                                 
	public:
	MCP23017_Expander(std::uint8_t _Address=0x20U);
	std::uint8_t write_register(std::uint8_t RegAdd,std::uint8_t value);                   //write 8 bits to the register of the MCP23017
	std::uint8_t read_register(std::uint8_t RegAdd);                                        //read 8 bit of the register
	void setupInterrupts(std::uint8_t mirroring,std::uint8_t open, std::uint8_t polarity);
    void setupInterruptPin(uint8_t p, uint8_t mode);
	void mode();
	void write();
	/*not implemented yet 
	void read_field();
	void write_field();
	*/
	~MCP23017_Expander();
	
	private:
	const std::uint8_t Address;                                          //Address of I2c device   
    const bit_size;
	
}
#endif