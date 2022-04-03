#ifndef __PICTURE_H
#define __PICTURE_H




//16位BMP 40X40 QQ图像取模数据
//Image2LCD取模选项设置
//水平扫描
//16位
//40X40
//不包含图像头数据
//自左至右
//自顶至底
//低位在前

//13 x 30
const unsigned char gImage_T[780] = { /* 0X00,0X10,0X0D,0X00,0X1E,0X00,0X01,0X1B, */
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XA4,0XF0,0XC4,0XE8,0XC4,0XE8,0XC4,0XF0,0XC8,0XE1,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X98,0XFD,
0XB7,0XFD,0XBE,0XF7,0XBE,0XF7,0XBE,0XFF,0XC4,0XE8,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X76,0XF5,0X38,0XFE,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XA4,0XF0,0XBE,0XF7,0X5E,0XFF,0X5D,0XFF,0X7D,0XF7,0XBF,0XF7,0XBE,0XF7,
0XBE,0XF7,0X75,0XF5,0X38,0XFE,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XA4,0XF0,0XBD,0XEF,
0X5C,0XFF,0X3C,0XFF,0X3C,0XFF,0X9F,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X38,0XFE,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XA4,0XF0,0XDD,0XEF,0XDF,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X38,0XFE,0XBE,0XF7,0XBE,0XF7,0XBF,0XF7,
0XA4,0XF0,0X9E,0XFF,0X31,0XFC,0X32,0XF4,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0X75,0XF5,0X39,0XFE,0XBE,0XF7,0XBF,0XF7,0XBE,0XF7,0XA4,0XF0,0XBE,0XF7,0XBF,0XFF,
0XDE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X58,0XFE,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0XA5,0XF0,0X9E,0XF7,0X47,0XE9,0X87,0XE9,0XBF,0XF7,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XE4,0XE8,0XE4,0XE8,0XE5,0XE8,0XA4,0XF0,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,
0X3B,0XFE,0XC4,0XE8,0XC4,0XE8,0XE4,0XE8,0XA4,0XF0,0XBD,0XEF,0XC4,0XE8,0XE4,0XE8,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XE4,0XE8,
0XC5,0XE8,0XA4,0XF0,0XBD,0XF7,0XBF,0XFF,0XBE,0XFF,0XBF,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XE4,0XE8,0XA4,0XF0,0XBE,0XEF,
0XC5,0XE8,0XE4,0XE8,0XE4,0XE8,0X9F,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,
0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XBE,0XF7,0XBE,0XFF,0XBE,0XFF,0X9E,0XFF,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,
0XA4,0XE8,0X9D,0XF7,0XCC,0XEA,0XCB,0XE2,0XBE,0XF7,0XBF,0XF7,0XBE,0XF7,0XBE,0XF7,
0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0X9D,0XF7,0X9D,0XF7,
0X9E,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,
0XC4,0XE8,0XC4,0XE8,0XA4,0XE8,0XBE,0XF7,0XB7,0XFD,0XB7,0XFD,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,
0XBE,0XF7,0XBE,0XF7,0XBD,0XF7,0XBF,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,
0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XBE,0XF7,0X9E,0XF7,0XBE,0XEF,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,
0XC4,0XE8,0XA4,0XE8,0XBE,0XEF,0X37,0XF6,0XF8,0XF5,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0X75,0XFD,0X3A,0XFE,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0X9E,0XF7,
0XBE,0XFF,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X75,0XF5,0X3A,0XFE,
0XE4,0XE8,0XC4,0XE8,0XE4,0XE8,0XC4,0XE8,0XBE,0XF7,0X8B,0XEA,0X8B,0XF2,0X6B,0XEA,
0X9E,0XF7,0XBE,0XF7,0XDE,0XEF,0X06,0XE9,0X58,0XFE,0XE5,0XE0,0XC4,0XE8,0XC4,0XE8,
0XC4,0XE8,0XF5,0XEC,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X0E,0XEB,
0X31,0XF4,0XE5,0XE0,0XE4,0XE8,0XC4,0XE8,0XE4,0XE8,0X34,0XF5,0X04,0XD9,0X9E,0XF7,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XE4,0XE0,0X31,0XF4,0XE5,0XE8,0XC4,0XE8,
0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0X7C,0XF6,0X0C,0XDB,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XC4,0XE8,0XE5,0XE8,0XE4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,
0XDD,0XF7,0X05,0XE9,0XBE,0XFF,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XE4,0XE8,0X46,0XE1,
0XE4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,0X9E,0XF7,0XE5,0XE8,0X9E,0XFF,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XC5,0XF0,0X1C,0XF7,0XC4,0XE8,0XC4,0XE8,0XC4,0XE8,
0XC4,0XE8,0XC4,0XE8,0X8F,0XEB,0XF7,0XFD,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0X19,0XEF,0XE4,0XE0,0X96,0XFD,0XC4,0XE8,0XC4,0XE8,0XE4,0XE8,0X9C,0XF7,0XC5,0XE8,
0X7E,0XFF,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0X94,0XEC,0XE3,0XF0,
0X92,0XF4,0XD9,0XFE,0X47,0XF1,0XE4,0XE0,0X9E,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,
0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XB4,0XF4,0XCE,0XEA,0XB9,0XFE,
0X9E,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,0XBE,0XF7,};


//25 x 30
const unsigned char gImage_SPO2[1500] = { /* 0X00,0X10,0X19,0X00,0X1E,0X00,0X01,0X1B, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDE,0XFF,0XBF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XB3,0XEC,
0X27,0XE2,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9E,0XFF,
0X65,0XF1,0X65,0XE9,0X55,0XF5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE8,0XE9,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X7E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XD2,0XEC,0X45,0XF1,0X65,0XF1,0X65,0XF1,0X45,0XF1,0X69,0XE2,0XDF,0XFF,0XFF,0XFF,
0XDF,0XFF,0X9E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X9C,0XFF,0X46,0XE9,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X66,0XE9,0X92,0XEC,0XFF,0XFF,
0XFF,0XFF,0X10,0XEC,0X27,0XE2,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X8A,0XE2,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X45,0XF1,0XA7,0XF1,0XDE,0XFF,
0XFF,0XFF,0X7D,0XFF,0X65,0XF1,0X65,0XF1,0XB6,0XF5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X59,0XF6,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X35,0XED,
0XFF,0XFF,0XFF,0XFF,0X29,0XEA,0X65,0XF1,0X45,0XF1,0XA6,0XE9,0XDF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XDF,0XFF,0XE7,0XE9,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X46,0XF1,
0XDF,0XFF,0XFF,0XFF,0X99,0XF6,0X65,0XF1,0X65,0XF1,0X45,0XF1,0X66,0XF1,0XB3,0XF4,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XD7,0XF5,0X64,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0XEB,0XEA,0XFF,0XFF,0XFF,0XFF,0X4A,0XEA,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X66,0XF1,
0X86,0XE9,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XA5,0XE1,0X45,0XF1,0X45,0XF1,0X65,0XF1,0X45,0XF1,
0X65,0XE9,0X7E,0XFF,0XFF,0XFF,0XDE,0XFF,0X45,0XF1,0X65,0XF1,0X45,0XF1,0X65,0XF1,
0X65,0XF1,0X45,0XF1,0X38,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X15,0XED,0X45,0XF1,0X45,0XF1,0X65,0XF1,0X65,0XF1,
0X45,0XF1,0X45,0XF1,0XBE,0XFF,0XFF,0XFF,0XF8,0XF5,0X45,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X6E,0XEB,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XA7,0XE9,0X45,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X45,0XF1,0X65,0XE9,0X7E,0XFF,0XFF,0XFF,0X1B,0XFF,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X45,0XF1,0X12,0XED,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XFE,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X4D,0XEB,0XFF,0XFF,0XFF,0XFF,0X08,0XEA,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XE9,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0C,0XEB,0X45,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0XBE,0XFF,0XFF,0XFF,
0X9D,0XFF,0X6A,0XEA,0X65,0XF1,0X65,0XF1,0X07,0XE2,0XFB,0XFE,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X86,0XE9,0X45,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X0C,0XEB,
0XFE,0XFF,0XFF,0XFF,0XFF,0XFF,0X9E,0XFF,0X9D,0XF7,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X44,0XE9,
0X45,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X45,0XE9,0X0B,0XEB,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X45,0XF1,0X45,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X85,0XE9,0X52,0XEC,0XDA,0XFE,0X7C,0XFF,0X59,0XF6,
0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X09,0XEA,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X45,0XE9,0X45,0XF1,0X65,0XF1,
0X65,0XE9,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X54,0XED,0X45,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X89,0XEA,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDE,0XFF,0X85,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X7A,0XF6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X95,0XF5,0X66,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X45,0XF1,0X65,0XF1,0XCA,0XE2,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0F,0XE4,
0X45,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X08,0XEA,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X96,0XF5,0X45,0XE9,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,0X65,0XF1,
0X65,0XF1,0X65,0XF1,0X8E,0XEB,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XD2,0XEC,0X48,0XEA,0XA6,0XE9,0X86,0XE9,
0XE8,0XE9,0XAE,0XEB,0X7E,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XDF,0XFF,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF7,0XDF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

//30 x 23
const unsigned char gImage_HR[1380] = { /* 0X00,0X10,0X1E,0X00,0X17,0X00,0X01,0X1B, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X14,0XD5,0XC1,0XB8,
0XA1,0XB0,0XDE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X92,0XE4,0XA2,0XC8,0XA3,0XB8,0XDE,0XEF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XA2,0XC0,0X82,0XC0,0XA2,0XB8,
0XA2,0XB8,0X56,0XEE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0XC0,
0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XA2,0XC0,0X1C,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0XB8,
0XA2,0XB8,0X82,0XC0,0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0XE3,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X86,0XC9,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XBE,0XFF,
0XFF,0XFF,0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XA2,0XB8,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFE,0XFF,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0XA3,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X67,0XC1,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XC3,0XB8,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC1,0XB0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0XBF,0XFF,0X82,0XC0,0XA2,0XB8,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC2,0XB8,0XA2,0XB8,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X75,0XE5,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0XDA,0XFD,0XFF,0XFF,0X82,0XC8,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0XFF,0XFF,0XBF,0XFF,0X51,0XD4,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0XA3,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X07,0XC1,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XA2,0XB0,0XFF,0XFF,
0XC3,0XB8,0XFF,0XFF,0X82,0XC0,0XA2,0XC0,0XFF,0XFF,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0XC8,0XA2,0XB8,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XDF,0XFF,0X91,0XE4,0XA2,0XC0,0XFF,0XFF,
0XA2,0XC0,0XFF,0XF7,0XFF,0XFF,0XDE,0XF7,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0XBE,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0XFF,0XFF,0XA2,0XC0,0X82,0XC0,0XFF,0XFF,0XA2,0XC0,0XFF,0XFF,
0XA2,0XB8,0XFF,0XFF,0X83,0XC0,0X81,0XC0,0XA1,0XC0,0X82,0XC0,0XA1,0XC0,0XA1,0XC0,
0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XDF,0XFF,0XDF,0XFF,0XDF,0XFF,0XDF,0XFF,
0XFF,0XFF,0XA2,0XC0,0XA2,0XC0,0XBE,0XFF,0XFF,0XEF,0XDF,0XFF,0XA2,0XB8,0XBD,0XF7,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X28,0XC9,0X25,0XC1,0X25,0XC1,0X45,0XC1,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0XA2,0XB0,0XFF,0XFF,0X81,0XB8,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0XDF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X81,0XB0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0XDE,0XFF,0XA2,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XDF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X82,0XC8,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XA2,0XC0,0X82,0XB8,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XA2,0XB0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XB8,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XF7,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X61,0XC0,0X82,0XC0,0X82,0XC0,
0X82,0XC0,0X82,0XC0,0X82,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X61,0XC0,0X82,0XC0,0X82,0XC0,0X82,0XC0,
0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE2,0XB0,0X82,0XC0,0XFF,0XEF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,};



//6x10
const unsigned char gImage_bt[120] = { /* 0X00,0X10,0X06,0X00,0X0A,0X00,0X01,0X1B, */
0XBE,0XF7,0X13,0X3B,0XF2,0X09,0XF2,0X09,0X13,0X3B,0XBE,0XF7,0X5A,0X95,0XF2,0X09,
0XF2,0X09,0XF2,0X09,0XF2,0X09,0X5A,0X95,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XFF,0XFF,
0XF2,0X09,0XF2,0X09,0XF2,0X09,0XFF,0XFF,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XF2,0X09,
0XF2,0X09,0XF2,0X09,0XFF,0XFF,0XBF,0XFF,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XF2,0X09,
0XFE,0XFF,0XFF,0XFF,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XFF,0XFF,0XF2,0X09,0XF2,0X09,
0XFF,0XFF,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XFF,0XFF,0XF2,0X09,0XF2,0X09,
0X12,0X12,0XF2,0X09,0XF2,0X09,0XF2,0X09,0XF2,0X09,0X12,0X12,0XBE,0XF7,0XF2,0X09,
0XF2,0X09,0XF2,0X09,0XF2,0X09,0XBE,0XF7,};


#endif /*__PICTURE_H*/
