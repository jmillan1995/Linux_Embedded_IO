// This library is created to use the I2C interface of the Raspberry
#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <errno.h>
#include <iostream>

class raspberry_i2c {
	bool error_flag;
	int slave_address;
	std::string devicefile;
	std::string ErrorMessage;
    int fd;								//File device is defined by linux kernel
    int errorMsg(std::string message);
    int open_fd();
    void close_fd();
	void init(std::string DeviceFile, int Address);

	public:
	raspberry_i2c();
	raspberry_i2c(int Address);
	raspberry_i2c(std::string DeviceFile, int Address);
	~raspberry_i2c();
	bool fail();
	int setAddress(int Address);
	int getAddress();
	const char *getErrorMessage();
	int setDevicefile(std::string filename);
	int receive(unsigned char *RxBuf, int length);
	int receive(unsigned char RegisterAddress, unsigned char *RxBuf, int length);
	int send(unsigned char *TxBuf, int length);
	int send(unsigned char RegisterAddress, unsigned char *TxBuf, int length);
	int send(unsigned char value);
};