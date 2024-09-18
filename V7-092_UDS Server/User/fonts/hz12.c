/*
*********************************************************************************************************
*
*	模块名称 : 汉字点阵字库。有效显示区 高11x宽11, 最右一列留白
*	文件名称 : hz12.c
*	版    本 : V1.0
*	说    明 : 只包含本程序用到汉字字库
*	修改记录 :
*		版本号  日期       作者    说明
*		v1.0    2011-09-08 armfly  ST固件库V3.5.0版本。
*
*	Copyright (C), 2010-2011, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#include "fonts.h"

#ifdef USE_SMALL_FONT
/*
	FLASH中内嵌小字库，只包括本程序用到的汉字点阵
	每行点阵数据，头2字节是汉子的内码，后面32字节是16点阵汉子的字模数据。
*/

unsigned char const g_Hz12[] = {
0xB0,0xB2, 0x04,0x00,0x7F,0xF0,0x40,0x10,0x84,0x20,0x04,0x00,0xFF,0xF0,0x08,0x80,0x10,0x80,// 安 //
           0x19,0x00,0x07,0x00,0x18,0xC0,0xE0,0x20,

0xB1,0xB3, 0x09,0x20,0x79,0xC0,0x09,0x00,0x39,0xF0,0xC0,0x00,0x1F,0xC0,0x10,0x40,0x1F,0xC0,// 背 //
           0x10,0x40,0x1F,0xC0,0x10,0x40,0x10,0xC0,

0xB1,0xEA, 0x20,0x40,0x27,0xE0,0x20,0x00,0xF8,0x20,0x2F,0xF0,0x60,0x80,0xB2,0xC0,0xA4,0xA0,// 标 //
           0x24,0x90,0x28,0x90,0x2A,0x80,0x21,0x00,

0xB2,0xE2, 0x81,0x10,0x5F,0x90,0x11,0x50,0x95,0x50,0x55,0x50,0x35,0x50,0x55,0x50,0xD5,0x50,// 测 //
           0x44,0x50,0x4A,0x10,0x51,0x50,0x60,0x20,

0xB3,0xA7, 0x00,0x20,0x3F,0xF0,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,// 厂 //
           0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,

0xB3,0xCC, 0x1B,0xE0,0xE2,0x20,0x22,0x20,0xFB,0xE0,0x20,0x00,0x67,0xF0,0x70,0x80,0xA8,0x80,// 程 //
           0xA3,0xE0,0x20,0x80,0x20,0xA0,0x2F,0xF0,

0xB3,0xF6, 0x04,0x00,0x24,0x40,0x24,0x40,0x24,0x40,0x3F,0xC0,0x24,0x40,0x04,0x00,0x44,0x20,// 出 //
           0x44,0x20,0x44,0x20,0x7F,0xE0,0x40,0x20,

0xB4,0xA5, 0x20,0x40,0x38,0x40,0x50,0x50,0xFD,0xF0,0x55,0x50,0x7D,0x50,0x55,0xF0,0x7D,0x50,// 触 //
           0x54,0x40,0x54,0x40,0x95,0xF0,0x8C,0x10,

0xB4,0xAB, 0x11,0x00,0x11,0x00,0x27,0xE0,0x21,0x00,0x6F,0xF0,0xA2,0x00,0x24,0x40,0x27,0xE0,// 传 //
           0x20,0x40,0x26,0x80,0x21,0x80,0x20,0xC0,

0xB5,0xF7, 0x40,0x20,0x2F,0xF0,0x29,0x20,0x0B,0xA0,0xC9,0x20,0x4F,0xE0,0x48,0x20,0x5B,0xA0,// 调 //
           0x6A,0xA0,0x4B,0xA0,0x10,0x20,0x20,0x60,

0xB7,0xB5, 0x40,0xE0,0x27,0x00,0x24,0x00,0x07,0xE0,0x04,0x20,0xE6,0x40,0x25,0x40,0x28,0x80,// 返 //
           0x31,0x40,0x26,0x20,0x50,0x00,0x8F,0xF0,

0xB8,0xBB, 0x02,0x00,0x7F,0xF0,0x40,0x10,0xBF,0xC0,0x00,0x00,0x1F,0x80,0x10,0x80,0x3F,0xC0,// 富 //
           0x24,0x40,0x3F,0xC0,0x24,0x40,0x3F,0xC0,

0xB8,0xD0, 0x01,0x40,0x7F,0xF0,0x41,0x00,0x5D,0x20,0x41,0x40,0x5C,0x90,0x55,0x50,0x9E,0x30,// 感 //
           0x04,0x50,0x52,0xA0,0x50,0x90,0x8F,0x80,

0xB9,0xE2, 0x02,0x00,0x22,0x40,0x12,0x40,0x12,0x80,0x02,0x20,0xFF,0xF0,0x09,0x00,0x09,0x00,// 光 //
           0x09,0x10,0x11,0x10,0x21,0x10,0xC0,0xF0,

0xBB,0xD8, 0x00,0x20,0x7F,0xF0,0x40,0x20,0x4F,0x20,0x49,0x20,0x49,0x20,0x49,0x20,0x4F,0x20,// 回 //
           0x40,0x20,0x40,0x20,0x7F,0xE0,0x40,0x20,

0xBB,0xFA, 0x20,0x40,0x23,0xE0,0xFA,0x40,0x22,0x40,0x62,0x40,0x72,0x40,0xAA,0x40,0xA2,0x40,// 机 //
           0x22,0x40,0x22,0x50,0x24,0x50,0x28,0x30,

0xBC,0xFE, 0x10,0x80,0x14,0x80,0x24,0x80,0x27,0xF0,0x68,0x80,0xA0,0x80,0x3F,0xF0,0x20,0x80,// 件 //
           0x20,0x80,0x20,0x80,0x20,0x80,0x20,0x80,

0xBD,0xDA, 0x09,0x00,0x09,0x20,0xFF,0xF0,0x09,0x00,0x00,0x40,0x7F,0xE0,0x04,0x40,0x04,0x40,// 节 //
           0x05,0x40,0x04,0x80,0x04,0x00,0x04,0x00,

0xC0,0xB3, 0x08,0x80,0xFF,0xF0,0x0A,0x80,0x7F,0xE0,0x22,0x40,0x12,0x80,0xFF,0xF0,0x0B,0x00,// 莱 //
           0x12,0x80,0x22,0x40,0xC2,0x30,0x02,0x00,

0xC2,0xBC, 0x3F,0x80,0x00,0x80,0x3F,0x80,0x00,0x80,0xFF,0xF0,0x24,0x40,0x16,0x80,0x0D,0x00,// 录 //
           0x34,0x80,0xC4,0x70,0x14,0x20,0x08,0x00,

0xC3,0xFE, 0x22,0x80,0x2F,0xF0,0x22,0x80,0xF7,0xE0,0x24,0x20,0x37,0xE0,0xE4,0x20,0x27,0xE0,// 摸 //
           0x21,0x00,0x2F,0xF0,0xA2,0x40,0x4C,0x30,

0xC6,0xC1, 0x7F,0xE0,0x40,0x20,0x7F,0xE0,0x48,0x80,0x45,0x00,0x5F,0xE0,0x44,0x80,0x7F,0xF0,// 屏 //
           0x44,0x80,0x44,0x80,0x48,0x80,0x90,0x80,

0xC6,0xF7, 0x79,0xE0,0x49,0x20,0x79,0xE0,0x49,0x20,0x04,0x80,0xFF,0xF0,0x10,0x80,0x20,0x40,// 器 //
           0xFD,0xF0,0x25,0x20,0x3D,0xE0,0x25,0x20,

0xCA,0xD4, 0x40,0x80,0x20,0xB0,0x00,0x80,0x1F,0xF0,0xC0,0x80,0x4F,0x80,0x42,0x80,0x42,0x40,// 试 //
           0x4A,0x50,0x53,0x50,0x6C,0x30,0x00,0x10,

0xCC,0xAB, 0x04,0x00,0x04,0x00,0x04,0x20,0xFF,0xF0,0x04,0x00,0x04,0x00,0x0A,0x00,0x09,0x00,// 太 //
           0x11,0x00,0x14,0x80,0x22,0x70,0xC0,0x20,

0xCD,0xF8, 0x00,0x20,0x7F,0xF0,0x48,0xA0,0x6A,0xA0,0x51,0x20,0x51,0x20,0x6A,0xA0,0x4A,0xA0,// 网 //
           0x44,0x20,0x40,0x20,0x40,0xA0,0x40,0x60,

0xCF,0xA2, 0x04,0x00,0x3F,0xC0,0x20,0x40,0x3F,0xC0,0x20,0x40,0x3F,0xC0,0x20,0x40,0x3F,0xC0,// 息 //
           0x14,0x00,0x52,0x20,0x50,0x50,0x8F,0xC0,

0xD0,0xA3, 0x21,0x00,0x20,0x80,0x27,0xF0,0xF8,0x00,0x22,0x40,0x74,0x20,0xA8,0x40,0xA2,0x80,// 校 //
           0x22,0x80,0x21,0x00,0x22,0xC0,0x2C,0x30,

0xD0,0xC5, 0x12,0x00,0x11,0x20,0x2F,0xF0,0x20,0x00,0x67,0xE0,0xA0,0x00,0x27,0xE0,0x20,0x00,// 信 //
           0x27,0xE0,0x24,0x20,0x27,0xE0,0x24,0x20,

0xD0,0xF2, 0x02,0x20,0x7F,0xF0,0x40,0x00,0x5F,0xE0,0x42,0x80,0x41,0x00,0x5F,0xF0,0x41,0x20,// 序 //
           0x41,0x00,0x41,0x00,0x45,0x00,0x82,0x00,

0xD2,0xD4, 0x00,0x00,0x48,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x40,0x40,0x44,0x40,0x48,0x80,// 以 //
           0x50,0xC0,0x61,0x20,0x46,0x20,0x18,0x00,

0xD2,0xF4, 0x04,0x40,0x7F,0xE0,0x10,0x80,0x09,0x00,0xFF,0xF0,0x00,0x00,0x1F,0xC0,0x10,0x40,// 音 //
           0x1F,0xC0,0x10,0x40,0x1F,0xC0,0x10,0x40,

0xD3,0xB2, 0x00,0x20,0xF7,0xF0,0x20,0x80,0x27,0xE0,0x74,0xA0,0x57,0xE0,0xD4,0xA0,0x57,0xE0,// 硬 //
           0x72,0x80,0x51,0x00,0x42,0x80,0x1C,0x70,

0xD4,0xA4, 0xFB,0xF0,0x09,0x00,0x51,0x00,0x23,0xE0,0xFE,0x20,0x2A,0xA0,0x22,0xA0,0x22,0xA0,// 预 //
           0x22,0xA0,0xA1,0x40,0x52,0x30,0x0C,0x10,

0xD6,0xB5, 0x11,0x20,0x1F,0xF0,0x21,0x00,0x27,0xE0,0x64,0x20,0xA7,0xE0,0x24,0x20,0x27,0xE0,// 值 //
           0x24,0x20,0x27,0xE0,0x24,0x20,0x2F,0xF0,

0xD7,0xB0, 0x11,0x00,0x91,0x40,0x5F,0xF0,0x31,0x00,0xD7,0xE0,0x14,0x00,0xFF,0xF0,0x0A,0x40,// 装 //
           0x32,0x80,0xD1,0x00,0x14,0xC0,0x18,0x30,

0xD7,0xBC, 0x05,0x00,0x84,0x80,0x47,0xF0,0x0C,0x80,0x54,0x80,0x47,0xF0,0xC4,0x80,0x47,0xF0,// 准 //
           0x44,0x80,0x44,0x80,0x47,0xF0,0x04,0x00,

0xD7,0xF8, 0x04,0x00,0x24,0x80,0x24,0x80,0x24,0x80,0x55,0x40,0x4D,0x20,0x86,0x00,0x04,0x00,// 坐 //
           0x7F,0xE0,0x04,0x00,0x04,0x20,0xFF,0xF0,

0xCA,0xD5, 0x11,0x00,0x11,0x00,0x12,0x00,0x53,0xF0,0x54,0x20,0x54,0x20,0x51,0x20,0x51,0x40,// 收 //
           0x71,0x40,0x10,0x80,0x11,0x40,0x16,0x30,

0xB6,0xA8, 0x04,0x00,0x02,0x00,0x7F,0xF0,0x40,0x10,0xBF,0xC0,0x04,0x00,0x24,0x80,0x27,0xC0,// 定 //
           0x24,0x00,0x34,0x00,0x4C,0x00,0x83,0xF0,

0xB7,0xFE, 0x73,0xE0,0x52,0x20,0x52,0x20,0x72,0xC0,0x52,0x00,0x53,0xE0,0x72,0x40,0x53,0x40,// 服 //
           0x52,0x80,0x53,0x40,0xB2,0x30,0x12,0x00,

0xBF,0xE9, 0x21,0x00,0x21,0x00,0x27,0xE0,0xF9,0x20,0x21,0x20,0x21,0x20,0x2F,0xF0,0x21,0x00,// 块 //
           0x3A,0x80,0xC2,0x80,0x04,0x40,0x38,0x30,

0xC4,0xA3, 0x22,0x40,0x2F,0xF0,0x22,0x40,0xF7,0xE0,0x24,0x20,0x77,0xE0,0xAC,0x20,0xA7,0xE0,// 模 //
           0x21,0x00,0x2F,0xF0,0x22,0x40,0x2C,0x30,

0xCE,0xBB, 0x12,0x00,0x11,0x40,0x2F,0xF0,0x20,0x00,0x64,0x40,0xA4,0x40,0x22,0x40,0x22,0x40,// 位 //
           0x22,0x80,0x22,0x80,0x20,0x80,0x2F,0xF0,

0xCE,0xF1, 0x08,0x00,0x0F,0x80,0x10,0x80,0x29,0x00,0x46,0x00,0x19,0x80,0xE4,0x70,0x3F,0x80,// 务 //
           0x08,0x80,0x08,0x80,0x14,0x80,0x63,0x00,

0xB0,0xB4, 0x21,0x00,0x21,0x00,0xF7,0xF0,0x28,0x20,0x21,0x00,0x3F,0xF0,0xE2,0x40,0x24,0x40,// 按 //
           0x22,0x80,0x21,0x80,0xA2,0x60,0x4C,0x20,

0xBC,0xFC, 0x20,0x80,0x2F,0xE0,0x72,0xA0,0x47,0xF0,0xF4,0xA0,0x2F,0xE0,0xF2,0x80,0x2B,0xE0,// 键 //
           0x24,0x80,0x37,0xE0,0x6A,0x80,0x11,0xF0,

0xC4,0xE2, 0x20,0x20,0x25,0x20,0xFC,0xA0,0x24,0xA0,0x24,0x20,0x34,0x20,0x64,0x20,0xA5,0x40,// 拟 //
           0x26,0x60,0x24,0x90,0xA3,0x10,0x4C,0x00,

0xC5,0xCC, 0x04,0x00,0x1F,0xC0,0x14,0x40,0x12,0x40,0xFF,0xF0,0x14,0x40,0x22,0xC0,0x40,0x00,// 盘 //
           0x3F,0xC0,0x29,0x40,0x29,0x40,0xFF,0xF0,

0xA1,0xA2, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 、 //
           0xC0,0x00,0x70,0x00,0x30,0x00,0x00,0x00,

0xBB,0xF2, 0x02,0x80,0x02,0x40,0xFF,0xF0,0x02,0x00,0x7A,0x20,0x49,0x20,0x49,0x40,0x79,0x40,// 或 //
           0x00,0x80,0x3D,0x90,0xC2,0x50,0x0C,0x30,

0xBA,0xCD, 0x0C,0x00,0xF0,0x20,0x11,0xF0,0x11,0x20,0xFF,0x20,0x11,0x20,0x39,0x20,0x55,0x20,// 和 //
           0x91,0xE0,0x11,0x20,0x10,0x00,0x10,0x00,

0xC9,0xE3, 0x27,0xF0,0x22,0x40,0xF3,0xC0,0x22,0x40,0x23,0xC0,0x32,0x40,0xEF,0xF0,0x20,0x40,// 摄 //
           0x2E,0xF0,0x2A,0xA0,0xA4,0x40,0x5B,0xB0,

0xCA,0xBE, 0x00,0x40,0x7F,0xE0,0x00,0x00,0x00,0x20,0xFF,0xF0,0x02,0x00,0x12,0x80,0x12,0x40,// 示 //
           0x22,0x20,0x42,0x10,0x8A,0x10,0x04,0x00,

0xCD,0xA8, 0x0F,0xE0,0x42,0x80,0x21,0x00,0x0F,0xE0,0x09,0x20,0xEF,0xE0,0x29,0x20,0x2F,0xE0,// 通 //
           0x29,0x20,0x29,0x60,0x50,0x00,0x8F,0xF0,

0xCD,0xB7, 0x22,0x00,0x12,0x00,0x0A,0x00,0x42,0x00,0x22,0x00,0x12,0x20,0xFF,0xF0,0x02,0x00,// 头 //
           0x05,0x00,0x08,0x80,0x10,0x40,0xE0,0x20,

0xCF,0xD4, 0x00,0x40,0x3F,0xE0,0x20,0x40,0x3F,0xC0,0x20,0x40,0x3F,0xC0,0x49,0x00,0x29,0x20,// 显 //
           0x29,0x40,0x29,0x80,0x09,0x20,0xFF,0xF0,

0xCF,0xF1, 0x22,0x00,0x27,0xC0,0x28,0x80,0x7F,0xE0,0x69,0x20,0xAF,0xE0,0x24,0x40,0x2A,0x80,// 像 //
           0x25,0xC0,0x2A,0xA0,0x24,0x90,0x29,0x80,

0xA1,0xA3, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,// 。 //
           0x90,0x00,0x90,0x00,0x60,0x00,0x00,0x00,

0xA1,0xB6, 0x00,0x00,0x00,0x90,0x00,0x90,0x01,0x20,0x01,0x20,0x02,0x40,0x02,0x40,0x01,0x20,// 《 //
           0x01,0x20,0x00,0x90,0x00,0x90,0x00,0x00,

0xA1,0xB7, 0x00,0x00,0x90,0x00,0x90,0x00,0x48,0x00,0x48,0x00,0x24,0x00,0x24,0x00,0x48,0x00,// 》 //
           0x48,0x00,0x90,0x00,0x90,0x00,0x00,0x00,

0xA3,0xAC, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,// ， //
           0x18,0x00,0x18,0x00,0x30,0x00,0x00,0x00,

0xB1,0xCC, 0x10,0x80,0xFB,0xE0,0x22,0x20,0xFB,0xE0,0x22,0x20,0xFB,0xE0,0x00,0x00,0xFF,0xF0,// 碧 //
           0x10,0x00,0x3F,0xC0,0x50,0x40,0x9F,0xC0,

0xB3,0xA4, 0x10,0x40,0x10,0x80,0x11,0x00,0x16,0x00,0x18,0x20,0xFF,0xF0,0x14,0x00,0x12,0x00,// 长 //
           0x11,0x00,0x10,0x80,0x1C,0x70,0x10,0x00,

0xB4,0xC7, 0x18,0x80,0x77,0xF0,0x11,0x20,0xFD,0x40,0x10,0x80,0x17,0xF0,0x78,0x80,0x48,0x80,// 辞 //
           0x4F,0xF0,0x78,0x80,0x48,0x80,0x00,0x80,

0xB7,0xAB, 0x20,0x40,0x23,0xE0,0xFA,0x40,0xAA,0x40,0xAA,0x40,0xAB,0x40,0xAA,0xC0,0xBA,0x40,// 帆 //
           0xAA,0x50,0x24,0x50,0x24,0x50,0x28,0x30,

0xB9,0xC2, 0x00,0x60,0xF7,0x80,0x15,0x40,0x25,0x40,0x25,0x40,0x35,0x40,0xE5,0x40,0x25,0x40,// 孤 //
           0x29,0x20,0x29,0x60,0xB1,0xD0,0x40,0x00,

0xB9,0xCA, 0x21,0x00,0x21,0x00,0x29,0x20,0xFD,0xF0,0x22,0x40,0x25,0x40,0x79,0x40,0x48,0x80,// 故 //
           0x48,0x80,0x79,0x40,0x42,0x20,0x0C,0x10,

0xB9,0xE3, 0x04,0x00,0x02,0x20,0x3F,0xF0,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,// 广 //
           0x20,0x00,0x40,0x00,0x40,0x00,0x80,0x00,

0xBA,0xC6, 0x01,0x00,0x45,0x00,0x27,0xE0,0x89,0x00,0x49,0x20,0x3F,0xF0,0x20,0x00,0xCF,0xE0,// 浩 //
           0x48,0x20,0x48,0x20,0x4F,0xE0,0x48,0x20,

0xBA,0xD7, 0x20,0x80,0x21,0xE0,0xFD,0x20,0xA5,0xA0,0x51,0x60,0xFD,0x00,0x51,0xF0,0x7C,0x10,// 鹤 //
           0x51,0xD0,0x7C,0x10,0x50,0x50,0x7C,0x20,

0xBB,0xA8, 0x08,0x80,0x08,0xA0,0xFF,0xF0,0x08,0x80,0x11,0x00,0x11,0x60,0x31,0x80,0x53,0x00,// 花 //
           0x95,0x10,0x11,0x10,0x11,0x10,0x10,0xF0,

0xBB,0xC6, 0x08,0x80,0x7F,0xE0,0x08,0x80,0xFF,0xF0,0x02,0x00,0x3F,0xC0,0x22,0x40,0x3F,0xC0,// 黄 //
           0x22,0x40,0x3F,0xC0,0x08,0x80,0x70,0x60,

0xBC,0xCA, 0x10,0x00,0xFB,0xF0,0x90,0x00,0xA0,0x20,0xCF,0xF0,0xA0,0x80,0x92,0xA0,0xD2,0xA0,// 际 //
           0xA4,0x90,0x88,0x90,0x82,0x80,0x81,0x00,

0xBC,0xFB, 0x00,0x80,0x3F,0xC0,0x20,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,0x24,0x80,// 见 //
           0x0A,0x00,0x0A,0x10,0x12,0x10,0xE1,0xF0,

0xBD,0xAD, 0x40,0x00,0x20,0x40,0x0F,0xF0,0x81,0x00,0x51,0x00,0x11,0x00,0x21,0x00,0x21,0x00,// 江 //
           0xC1,0x00,0x41,0x20,0x5F,0xF0,0x40,0x00,

0xBE,0xA1, 0x3F,0xC0,0x20,0x40,0x20,0x40,0x3F,0xC0,0x22,0x00,0x21,0x00,0x2C,0x80,0x42,0x40,// 尽 //
           0x40,0x30,0x98,0x00,0x06,0x00,0x01,0x00,

0xBF,0xD5, 0x04,0x00,0x02,0x00,0x7F,0xF0,0x80,0x10,0x11,0x80,0x20,0x60,0xC0,0x20,0x3F,0xC0,// 空 //
           0x04,0x00,0x04,0x00,0x04,0x20,0xFF,0xF0,

0xC1,0xEA, 0x01,0x00,0xF7,0xE0,0x91,0x00,0xAF,0xF0,0xC2,0x80,0xA4,0x40,0x9A,0x20,0x97,0xC0,// 陵 //
           0xEA,0x80,0x91,0x00,0x86,0xC0,0x98,0x30,

0xC1,0xF7, 0x01,0x00,0x4F,0xF0,0x21,0x00,0x82,0x40,0x4F,0xE0,0x20,0x20,0x25,0x40,0x25,0x40,// 流 //
           0xC5,0x50,0x45,0x50,0x49,0x50,0x51,0x30,

0xC2,0xA5, 0x21,0x00,0x29,0x20,0x25,0x40,0xFF,0xE0,0x23,0x40,0x75,0x30,0xA2,0x00,0xAF,0xE0,// 楼 //
           0x24,0x80,0x23,0x00,0x26,0xC0,0x38,0x20,

0xC3,0xCF, 0x3F,0xC0,0x01,0x00,0x02,0x00,0xFF,0xF0,0x02,0x00,0x06,0x00,0x00,0x00,0x3F,0xC0,// 孟 //
           0x29,0x40,0x29,0x40,0xFF,0xF0,0x00,0x00,

0xC8,0xBB, 0x21,0x00,0x21,0x40,0x3D,0x20,0x47,0xF0,0x49,0x00,0xA9,0x80,0x12,0x40,0x24,0x20,// 然 //
           0xD8,0x10,0x02,0x40,0x49,0x20,0x89,0x20,

0xC8,0xCB, 0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x06,0x00,0x0A,0x00,0x09,0x00,// 人 //
           0x10,0x80,0x20,0x40,0x40,0x30,0x80,0x20,

0xC8,0xFD, 0x00,0x40,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x80,0x3F,0xC0,0x00,0x00,0x00,0x00,// 三 //
           0x00,0x00,0x00,0x20,0xFF,0xF0,0x00,0x00,

0xCB,0xCD, 0x08,0x40,0x44,0x80,0x21,0x00,0x0F,0xE0,0x01,0x00,0xEF,0xE0,0x21,0x00,0x22,0x80,// 送 //
           0x24,0x60,0x28,0x20,0x50,0x00,0x8F,0xF0,

0xCC,0xEC, 0x00,0x40,0x7F,0xE0,0x04,0x00,0x04,0x00,0xFF,0xF0,0x04,0x00,0x04,0x00,0x06,0x00,// 天 //
           0x09,0x00,0x10,0x80,0x20,0x70,0xC0,0x20,

0xCE,0xA8, 0x02,0x80,0xF2,0x40,0x97,0xF0,0x94,0x80,0x9C,0x80,0x97,0xF0,0x94,0x80,0xF7,0xF0,// 唯 //
           0x84,0x80,0x04,0xA0,0x07,0xF0,0x04,0x00,

0xCE,0xF7, 0x00,0x20,0xFF,0xF0,0x09,0x00,0x7F,0xE0,0x49,0x20,0x49,0x20,0x49,0x20,0x51,0xE0,// 西 //
           0x60,0x20,0x40,0x20,0x7F,0xE0,0x40,0x20,

0xCF,0xC2, 0x00,0x20,0xFF,0xF0,0x04,0x00,0x04,0x00,0x06,0x00,0x05,0x00,0x04,0xC0,0x04,0x40,// 下 //
           0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,

0xD1,0xCC, 0x20,0x00,0x27,0xF0,0x24,0x90,0xA4,0x90,0xB7,0xF0,0xA4,0x90,0x24,0x90,0x25,0x50,// 烟 //
           0x26,0x30,0x54,0x10,0x97,0xF0,0x04,0x10,

0xD1,0xEF, 0x20,0x00,0x27,0xC0,0xF8,0x80,0x21,0x00,0x22,0x20,0x37,0xF0,0x62,0xA0,0xA2,0xA0,// 扬 //
           0x24,0xA0,0x29,0x20,0xA2,0xA0,0x64,0x40,

0xD3,0xB0, 0x7C,0x20,0x44,0x40,0x7C,0x80,0x45,0x00,0xFE,0x20,0x00,0x40,0x7C,0x80,0x45,0x10,// 影 //
           0x7C,0x20,0x50,0x40,0x94,0x80,0x31,0x00,

0xD4,0xB6, 0x00,0x40,0x4F,0xE0,0x20,0x00,0x1F,0xF0,0x04,0x80,0xE4,0x80,0x24,0x80,0x24,0x90,// 远 //
           0x28,0x90,0x20,0x70,0x50,0x00,0x8F,0xF0,

0xD4,0xC2, 0x1F,0xC0,0x10,0x40,0x10,0x40,0x1F,0xC0,0x10,0x40,0x10,0x40,0x1F,0xC0,0x10,0x40,// 月 //
           0x10,0x40,0x20,0x40,0x42,0x40,0x81,0x80,

0xD6,0xAE, 0x04,0x00,0x02,0x00,0x02,0x00,0x7F,0xC0,0x00,0x80,0x01,0x00,0x02,0x00,0x04,0x00,// 之 //
           0x08,0x00,0x30,0x00,0x58,0x00,0x87,0xF0,

0xD6,0xDD, 0x10,0x20,0x12,0x20,0x12,0x20,0x12,0x20,0x5B,0x20,0x56,0xA0,0x92,0xA0,0x12,0x20,// 州 //
           0x12,0x20,0x22,0x20,0x22,0x20,0x40,0x20,

0xBF,0xE2, 0x02,0x00,0x7F,0xF0,0x42,0x00,0x5F,0xF0,0x44,0x00,0x49,0x00,0x5F,0xE0,0x41,0x00,// 库 //
           0x41,0x00,0x7F,0xF0,0x41,0x00,0x81,0x00,

0xD7,0xD6, 0x04,0x00,0x7F,0xF0,0x40,0x10,0x9F,0xA0,0x00,0x80,0x01,0x00,0x02,0x20,0x7F,0xF0,// 字 //
           0x02,0x00,0x02,0x00,0x0A,0x00,0x06,0x00,

0xB5,0xC4, 0x11,0x00,0x21,0x20,0x7B,0xF0,0x4A,0x20,0x4C,0x20,0x48,0x20,0x79,0x20,0x48,0xA0,// 的 //
           0x48,0xA0,0x48,0x20,0x78,0xA0,0x00,0x40,

0xCA,0xC7, 0x1F,0x80,0x10,0x80,0x1F,0x80,0x10,0x80,0x1F,0x80,0x00,0x20,0xFF,0xF0,0x02,0x00,// 是 //
           0x13,0xE0,0x12,0x00,0x2E,0x00,0xC3,0xF0,

0xD6,0xBB, 0x20,0x40,0x3F,0xE0,0x20,0x40,0x20,0x40,0x20,0x40,0x3F,0xC0,0x20,0x40,0x09,0x00,// 只 //
           0x10,0x80,0x20,0x60,0x40,0x20,0x80,0x00,

0xB9,0xDC, 0x21,0x00,0x3D,0xF0,0x52,0x80,0x84,0x00,0x7F,0xF0,0x50,0x90,0x9F,0xA0,0x10,0x80,// 管 //
           0x1F,0xC0,0x10,0x40,0x1F,0xC0,0x10,0x40,

0xC2,0xEB, 0x00,0x40,0xFF,0xE0,0x22,0x40,0x22,0x40,0x72,0x40,0x57,0xF0,0xD0,0x10,0x50,0x10,// 码 //
           0x57,0xD0,0x70,0x10,0x41,0xA0,0x00,0x40,

0xCA,0xFD, 0x94,0x80,0x58,0x80,0xFD,0xF0,0x31,0x20,0x5A,0x20,0x90,0x40,0x21,0x40,0xFD,0x40,// 数 //
           0x48,0x80,0x30,0x80,0x29,0x40,0xC6,0x30,

0xB2,0xA8, 0x41,0x00,0x21,0x00,0x2F,0xE0,0x89,0x20,0x49,0x00,0x2F,0xC0,0x28,0x40,0xCA,0x40,// 波 //
           0x4A,0x80,0x49,0x80,0x52,0x40,0x24,0x30,

0xB4,0xAE, 0x04,0x00,0x04,0x40,0x3F,0xE0,0x24,0x40,0x3F,0xC0,0x04,0x20,0x7F,0xF0,0x44,0x20,// 串 //
           0x7F,0xE0,0x44,0x20,0x04,0x00,0x04,0x00,

0xBF,0xDA, 0x00,0x00,0x00,0x40,0x3F,0xE0,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,0x20,0x40,// 口 //
           0x20,0x40,0x3F,0xC0,0x20,0x40,0x00,0x00,

0xC1,0xF4, 0x18,0x00,0x63,0xE0,0x41,0x20,0x59,0x20,0x6A,0x60,0x44,0x00,0x3F,0xC0,0x24,0x40,// 留 //
           0x3F,0xC0,0x24,0x40,0x3F,0xC0,0x20,0x40,

0xC2,0xE7, 0x22,0x00,0x23,0xE0,0x52,0x40,0x94,0x80,0xE9,0x00,0x42,0xC0,0xF4,0x30,0x8F,0xE0,// 络 //
           0x14,0x20,0xE4,0x20,0x07,0xE0,0x04,0x20,


/* 最后一行必须用0xFF,0xFF结束，这是字库数组结束标志 */
0xFF,0xFF

};

#else
	unsigned char const g_Hz12[] = {0xFF, 0xFF};
#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
