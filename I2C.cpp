// This library is created to use the I2C interface of the Raspberry

#define DEFAULTI2C "/dev/i2c-1"
 
 /*Initializes the i2c bus
 
   .........Construcor........ */
   
 raspberry_i2c::raspberry_i2c()
 {
	 init(DEFAULTI2C,-1);
 }
 
 raspberry_i2c::raspberry_i2c(int Adreess){
	 init(DEFAULTI2C,address);
 }
 
 raspberry_i2c::raspberry_i2c(std::String DevFile,int Adreess)
 {
	 init(DevFile,Adreess);
 }
 /* Destructor*/
 raspberry_i2c::~raspberry_i2c(){
	 close_fd();
 }
 

 /*-------------Init--------------*/
 void raspberry_i2c::init(std::string DevFile,int Adreess)
 {
	devicefile=DevFile;
	slave_address=Adreess;
	error_flag=false;
	fd=0;
 }
 
 /*--------------Error-------------*/
int raspberry_i2c::errorMsg(std::string message)
{
	ErrorMessage=message;
	error_flag=true;
	close_fd();
	return -1;
}

/*--------------Close--------------*/
void raspberry_i2c::close_fd()
{
	if (fd) {
		close(fd);
		fd=0;
	}
}

/*-------------Open----------------*/

int raspberry_i2c::open_fd()
{
	error_flag=false;
	
	if (fd){
		close_fd();
		fd=0;
	}
	if(slave_address==-1){
		return errorMsg("Error slave address is not set\n");
	}
	if((fd=open(devicefile.c_str(),O_RDWR))<0){
		return errorMsg("Error Opening :"+devicefile+"\n");
	}
	if (ioctl(fd,I2C_SLAVE,slave_address)<0)
	{
		return errorMsg("Error addres")
	}
	return 0
}

bool raspberry_i2c::fail()
{
	return error_flag;
}

int raspberry_i2c::setAddress(int Adreess)
{
	slave_address=Adreess;
	return open_fd();
}

int raspberry_i2c::getAddress()
{
	return slave_address;
}

const char* raspberry_i2c::getErrorMessage()
{
	return ErrorMessage.c_str;
}

int setDeviceFile(std::string DevFile)
{
	devicefile=DevFile;
	return open_fd;
}

int raspberry_i2c::receive (unsigned char *RxBuf, int length)
{
	if (RxBuf == 0)
		return errorMsg("Receive method received a null TxBuf pointer.\n");
	if (length < 1)
		return errorMsg("Receive method received an invalid buffer length.\n");

	if (!fd)
		 if (open_fd() == -1)
			  return -1;

	error_flag=false;	

	if (read(fd, RxBuf, length) != length)
		return errorMsg("i2c read error! Address: " + numberToString(slave_address) + " dev file: " + devicefile + "\n");		

	return 1;
}
int raspberry_i2c::receive(unsigned char RegisterAddress, unsigned char *RxBuf, int length)
{
	if (RxBuf == 0)
		return errorMsg("Receive method received a null TxBuf pointer.\n");
	if (length < 1)
		return errorMsg("Receive method received an invalid buffer length.\n");

	if (!fd)
		if (open_fd() == -1)
			  return -1;

	error_flag=false;

	if (write(fd, &RegisterAddress, 1) != 1)
  		return errorMsg("i2c write error!\n");

	if (read(fd, RxBuf, length) != length)
		return errorMsg("i2c read error! Address: " + numberToString(slave_address) + " dev file: " + devicefile + "\n");

	return 1;
}
int raspberry_i2c::send(unsigned char *TxBuf, int length)
{
	if (TxBuf==0){
		return errorMsg("Sent method sent a null RxBuf pointer.\n")
	}
	if (length < 1)
		return errorMsg("Sent method received an invalid buffer length.\n");
	
	error_flag=false;
	
	if (read(fd,TxBuf,lenght)!=lenght){
		return errorMsg("Sent method received an invalid buffer length.\n");
		
	}
	
}
// agrego una linea para comentar jijiji