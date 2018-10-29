/*
 * rgb_display_custom.cpp
 * Driver for DIGITAL I2C HUMIDITY AND TEMPERATURE SENSOR
 *  
 * Copyright (c) 2018 Seeed Technology Co., Ltd.
 * Website    : www.seeed.cc
 * Author     : downey
 * Create Time: sep. 2018
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "seeed_led_matrix.h"


#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
#define SERIAL SerialUSB
#else
#define SERIAL Serial
#endif

SeeedLedMatrix g_matrix;

uint8_t g_custom_picture[8][8] = {{0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
                                 {0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
                                 {0x01,0x03,0x07,0x00,0x00,0x00,0x00,0x00},
                                 {0x01,0x03,0x07,0x0f,0x00,0x00,0x00,0x00},
                                 {0x01,0x03,0x07,0x0f,0x1f,0x00,0x00,0x00},
                                 {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x00,0x00},
                                 {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0x00},
                                 {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff},
                                 };
														 

#define DISPLAY_COLOR 254
														 
void setup()
{
	uint8_t version[VERSION_LEN]={0};
	Wire.begin();
	SERIAL.begin(115200);
	delay(10);
	g_matrix.begin();
	if(g_matrix.readVersion(version))
	{
		SERIAL.println("Init failed,please check wiring,or check the IIC adress.");
	}
	SERIAL.print("version = ");
	SERIAL.println((char*)version);
	
}



void loop()
{
	uint8_t picture[8]={0};
	memset(picture,0,8);
	delay(2000);
	
	/*
		Display content：picture array above
		Display time-limit :  0
		Repeat:               Forever
		Display color :       DISPLAY_COLOR
	*/
	g_matrix.dispCustomPicture(picture,0,DISP_FOREVER,DISPLAY_COLOR);
	
	
	memset(picture,0xff,8);
	delay(2000);
	g_matrix.dispCustomPicture(picture,0,DISP_FOREVER,DISPLAY_COLOR);
	
}




