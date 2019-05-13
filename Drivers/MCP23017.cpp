MCP23017_Expander::MCP23017_Expander(std::uint8_t _Address): Address(_Address)
{
	
	
	
}

std::uint8_t write_register(std::uint8_t RegAdd,std::uint8_t value)
{
	int n_bytes;
	Wire.beginTransmission(Address);
	Wire.write(RegAdd);
	n_bytes=Wire.write(value);
	Write.endTransmission();
	return n_bytes;
}

std::uint8_t read_register(std::uint8_t RegAdd);{
	
	Write.beginTransmission(Address);
	Wire.write(RegAdd);
	
}