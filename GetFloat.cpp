#include "pch.h"
#include <math.h>
#include <iostream>


void getfloat()
{
	float fresult;
	unsigned short int iresult;
	char rec[4] = { 0x80,0x00,0xc3,0xb5 };
	char *modebus[4];

	modebus[0] = ((char*)(&fresult)) + 1;
	modebus[1] = ((char*)(&fresult)) + 0;
	modebus[2] = ((char*)(&fresult)) + 3;
	modebus[3] = ((char*)(&fresult)) + 2;

	*modebus[0] = rec[0];
	*modebus[1] = rec[1];
	*modebus[2] = rec[2];
	*modebus[3] = rec[3];
	printf("输出浮点数： %f\r\n", fresult);

	modebus[0] = ((char*)(&iresult)) + 1;
	modebus[1] = ((char*)(&iresult)) + 0;
	*modebus[0] = rec[0];
	*modebus[1] = rec[1];
	printf("输出整数： %d\r\n", iresult);
}

float getfloat(unsigned char A, unsigned char B, unsigned char C, unsigned char D)
{
	float fresult;
	unsigned short int iresult;
	//char rec[4] = { 0x80,0x00,0xc3,0xb5 };
	char rec[4] = { A,B,C,D };
	char *modebus[4];

	modebus[0] = ((char*)(&fresult)) + 1;
	modebus[1] = ((char*)(&fresult)) + 0;
	modebus[2] = ((char*)(&fresult)) + 3;
	modebus[3] = ((char*)(&fresult)) + 2;

	*modebus[0] = rec[0];
	*modebus[1] = rec[1];
	*modebus[2] = rec[2];
	*modebus[3] = rec[3];
	return fresult;

	/*printf("输出浮点数： %f\r\n", fresult);

	modebus[0] = ((char*)(&iresult)) + 1;
	modebus[1] = ((char*)(&iresult)) + 0;
	*modebus[0] = rec[0];
	*modebus[1] = rec[1];
	printf("输出整数： %d\r\n", iresult);*/
}
int main()
{
	
    std::cout << getfloat(0x80, 0x00, 0xc3, 0xb5);
}
