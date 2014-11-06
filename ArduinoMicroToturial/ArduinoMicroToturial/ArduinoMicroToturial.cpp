/*
 * ArduinoMicroToturial.cpp
 *
 * Created: 10/30/2014 11:50:07 AM
 *  Author: ofir
 */ 
#define DEVICE (0x53) //ADXL345 device address
#define TO_READ (6)   //num of bytes we are going to read each time (two bytes for each axis)
#define ARDUINO 106
#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include <ButtonInt.h>
//#include <ADXL345.h>
#include <Stream.h>
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

void setup();
void loop();

int val;
int blt_serial_in = 11; //D11
int blt_serial_out = 10; //D10
int blt_key = 9; //D9
int INT6_pin = 7; 
boolean int6_flag =false;
SoftwareSerial BltSerial(blt_serial_in,blt_serial_out); // RX, TX  MCU side
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//float rollValue;
//float tiltValue;
//void ADXL345Read();
//void writeTo(int device, byte address, byte val);
//void readFrom(int device, byte address, int num, byte buff[]);
///////////////////////////////////////////////////////////////////////////////////////

//---------------- Functions
//Writes val to address register on device
//void writeTo(int device, byte address, byte val) {
	//Wire.beginTransmission(device); //start transmission to device
	//Wire.write(address);        // send register address
	//Wire.write(val);        // send value to write
	//Wire.endTransmission(); //end transmission
//}
//
////reads num bytes starting from address register on device in to buff array
//void readFrom(int device, byte address, int num, byte buff[]) {
	//Wire.beginTransmission(device); //start transmission to device
	//Wire.write(address);        //sends address to read from
	//Wire.endTransmission(); //end transmission
	//
	//Wire.beginTransmission(device); //start transmission to device
	//Wire.requestFrom(device, num);    // request 6 bytes from device
	//
	//int i = 0;
	//while(Wire.available())    //device may send less than requested (abnormal)
	//{
		//buff[i] = Wire.read(); // receive a byte
		//i++;
	//}
	//Wire.endTransmission(); //end transmission
//}
//
//void ADXL345Read(){
	  //// join i2c bus (address optional for master)      
	  ////Turning on the ADXL345
	  //float tilt;		//store tilt angle
	  //float roll;		//strore roll angle
	  //byte buff[TO_READ] ;  //6 bytes buffer for saving data read from the device
	  //int regAddress = 0x32;    //first axis-acceleration-data register on the ADXL345
	  //int x, y, z;
	  //float xg,yg,zg;	//These variables will be used to hold the x,y and z axis accelerometer values in G's values.
	  //float mag;		//store the magnitued of xg,yg,zg
	  //writeTo(DEVICE, 0x2D, 0);
	  //writeTo(DEVICE, 0x2D, 16);
	  //writeTo(DEVICE, 0x2D, 8);
	  //readFrom(DEVICE, regAddress, TO_READ, buff); //read the acceleration data from the ADXL345
	  //
	  ///*each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
	   //thus we are converting both bytes in to one int
	   //*/
	  //x = (((int)buff[1]) << 8) | buff[0];  
  	  //y = (((int)buff[3])<< 8) | buff[2];
      //z = (((int)buff[5]) << 8) | buff[4];
	    //
	  ///*
	   //Convert the accelerometer value to G's.
	   //With 10 bits measuring over a +/-4g range we can find how to convert by using the equation:
	   //Gs = Measurement Value * (G-range/(2^10)) or Gs = Measurement Value * (8/1024)
	  //*/
	  //xg = x * 0.0078; 
	  //yg = y * 0.0078;
	  //zg = z * 0.0078;
	    //
	  //mag=sqrt(pow(xg,2)+pow(yg,2)+pow(zg,2));
	  //tilt=acos(zg/mag)*(180/PI);
	  //
	  ////calculating the roll angle , rotaion angle around Vector X
	  //roll = atan2(yg,sqrt(pow(xg,2)+pow(zg,2)));
	  //roll=roll*(180/PI);
//
    ////  return ADXL345Values;
	   //BltSerial.println(roll,DEC);
	   //BltSerial.println(tilt,DEC);
      ////rollValue =roll;
	  ////tiltValue=tilt;
//}



ISR(INT6_vect)
{
	int6_flag=true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup(){
	pinMode(A5, OUTPUT);
	pinMode(A4, OUTPUT);
	pinMode(blt_key,OUTPUT);
	pinMode(blt_serial_out,OUTPUT);
	pinMode(blt_serial_in,INPUT);
	digitalWrite(blt_key,LOW);
	Serial.begin(9600);
	BltSerial.begin(9600);  
  //  Wire.begin();   
	ButtonIntFunc();
}

boolean cont =false;
void loop()	{
	
	
	digitalWrite(A4, HIGH);
	digitalWrite(A5, HIGH);
	delay(1000);
	digitalWrite(A4, LOW);
	digitalWrite(A5, LOW);
	delay(1000);
	//if (cont==false)
	delay(10000);
    BltSerial.print("aaaaaa:bbbbb:cccc");
		//cont=true;
	//if (int6_flag==true)
	//{
		//for (int i=0;i<10;i++)
		//{
			//val = analogRead(A0);
			//BltSerial.println(val,DEC);
		 //	ADXL345Read();
		   //BltSerial.println(rollValue,DEC);
	////		BltSerial.println(tiltValue,DEC);		
		//}
	//}
}







