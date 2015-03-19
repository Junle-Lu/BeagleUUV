//============================================================================
// Name        : IMUTest.cpp
// Author      : Junle
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MPU9250.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <stropts.h>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	MPU9250 test;
	double mag_data[3] = {0};

	double mpu_data[7] = {7};
	double pitch= 0;
	double roll = 0;
	double yaw = 0;

	cout<<"magnetometer sampling"<<endl;

	/*while (1)
	{
		//test.get_actual_mpu_data(mpu_data,&pitch, &roll);
		test.get_actual_mag_data(mag_data, &yaw);

		usleep(125000);

		cout<<yaw<<endl;
	}*/


	while (1)
	{
		test.get_actual_mpu_data(mpu_data, &pitch, &roll);
		test.get_actual_mag_data(mag_data, &yaw);

		usleep(130000);

		cout<<fixed<<"Pitch: "<<setprecision(2)<<pitch<<"     Roll: "<<setprecision(2)<<roll<<"     yaw: " <<setprecision(2)<<yaw<<endl;
	}
	/*ofstream myfile;
	myfile.open ("magnetometer.txt");
	myfile<<"Time		x		y		z"<<endl;*/

	/*for (int i = 0; i <240; i ++)
	{
		test.get_actual_mag_data(test_data);
		usleep(125000);
		myfile<<fixed<<time<<"		"<<setprecision(4)<<test_data[0]<<"		"<<setprecision(4)<<test_data[1]<<"		"<<setprecision(4)<<test_data[2]<<endl;
		time = time + 125./1000.;//in second

	}*/

/*
	//read for 30 second,for 100 Hz sample rate
	for (int i = 0; i <3000; i ++)
	{
		test.get_actual_mpu_data(mpu_data);
		usleep(10000);
		myfile<<fixed<<time<<"		"<<setprecision(4)<<mpu_data[3]<<"		"<<setprecision(4)<<mpu_data[4]<<"		"<<setprecision(4)<<mpu_data[5]<<endl;
		time = time + 10./1000.;//in second

	}
*/
	return 0;
}
