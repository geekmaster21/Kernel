/*
 * =================================================================
 *
 *
 *	Description:  samsung display panel driver file
 *
 *	Author: cj1225.jang
 *	Company:  Samsung Electronics
 *
 * ================================================================
 */
/*
<one line to give the program's name and a brief idea of what it does.>
Copyright (C) 2020, Samsung Electronics. All rights reserved.

*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
*/
#ifndef _SAMSUNG_DSI_MDNIE_S6E3FC3_AMS667YM01_
#define _SAMSUNG_DSI_MDNIE_S6E3FC3_AMS667YM01_

#include "ss_dsi_mdnie_lite_common.h"

#define MDNIE_COLOR_BLINDE_CMD_OFFSET 2

#define ADDRESS_SCR_WHITE_RED   0x14
#define ADDRESS_SCR_WHITE_GREEN 0x15
#define ADDRESS_SCR_WHITE_BLUE  0x16

#define MDNIE_STEP1_INDEX 4
#define MDNIE_STEP2_INDEX 5
#define MDNIE_STEP3_INDEX 6

static char level_0_key_on[] = {
	0x9F,
	0xA5, 0xA5
};

static char level_0_key_off[] = {
	0x9F,
	0x5a, 0x5a
};

static char level_1_key_on[] = {
	0xF0,
	0x5A, 0x5A
};

static char level_1_key_off[] = {
	0xF0,
	0xA5, 0xA5
};

static char multi_cmd_on[] = {
	0x72,
	0x2C, 0x21
};

static char multi_cmd_off[] = {
	0x72,
	0x2C, 0x01
};

static char multi_cmd_dummy[] = {
	0x0A,
	0x00
};

static char adjust_ldu_data_1[] = {
	0xff, 0xff, 0xff,
	0xfd, 0xfd, 0xff,
	0xfb, 0xfb, 0xff,
	0xf9, 0xf8, 0xff,
	0xf6, 0xf6, 0xff,
	0xf4, 0xf4, 0xff,
};

static char adjust_ldu_data_2[] = {
	0xff, 0xfc, 0xf6,
	0xfd, 0xfa, 0xf6,
	0xfb, 0xf7, 0xf6,
	0xf9, 0xf5, 0xf6,
	0xf4, 0xf0, 0xf6,
	0xf2, 0xee, 0xf6,
};

static char *adjust_ldu_data[MAX_MODE] = {
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_2,
	adjust_ldu_data_1,
	adjust_ldu_data_1,
};

static char night_mode_data[] = {
	0xff, 0x00, 0x00, 0x00, 0xf9, 0x00, 0x00, 0x00, 0xee, 0x00, 0xf9, 0xee, 0xff, 0x00, 0xee, 0xff, 0xf9, 0x00, 0xff, 0xf9, 0xee, 0xff, 0x00, 0x00, /* 6500K */
	0xff, 0x00, 0x00, 0x00, 0xf7, 0x00, 0x00, 0x00, 0xe6, 0x00, 0xf7, 0xe6, 0xff, 0x00, 0xe6, 0xff, 0xf7, 0x00, 0xff, 0xf7, 0xe6, 0xff, 0x00, 0x00, /* 6300K */
	0xff, 0x00, 0x00, 0x00, 0xf3, 0x00, 0x00, 0x00, 0xde, 0x00, 0xf3, 0xde, 0xff, 0x00, 0xde, 0xff, 0xf3, 0x00, 0xff, 0xf3, 0xde, 0xff, 0x00, 0x00, /* 6100K */
	0xff, 0x00, 0x00, 0x00, 0xef, 0x00, 0x00, 0x00, 0xd6, 0x00, 0xef, 0xd6, 0xff, 0x00, 0xd6, 0xff, 0xef, 0x00, 0xff, 0xef, 0xd6, 0xff, 0x00, 0x00, /* 5900K */
	0xff, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0xcd, 0x00, 0xec, 0xcd, 0xff, 0x00, 0xcd, 0xff, 0xec, 0x00, 0xff, 0xec, 0xcd, 0xff, 0x00, 0x00, /* 5700K */
	0xff, 0x00, 0x00, 0x00, 0xe8, 0x00, 0x00, 0x00, 0xc5, 0x00, 0xe8, 0xc5, 0xff, 0x00, 0xc5, 0xff, 0xe8, 0x00, 0xff, 0xe8, 0xc5, 0xff, 0x00, 0x00, /* 5500K */
	0xff, 0x00, 0x00, 0x00, 0xdd, 0x00, 0x00, 0x00, 0xaa, 0x00, 0xdd, 0xaa, 0xff, 0x00, 0xaa, 0xff, 0xdd, 0x00, 0xff, 0xdd, 0xaa, 0xff, 0x00, 0x00, /* 4900K */
	0xff, 0x00, 0x00, 0x00, 0xcd, 0x00, 0x00, 0x00, 0x87, 0x00, 0xcd, 0x87, 0xff, 0x00, 0x87, 0xff, 0xcd, 0x00, 0xff, 0xcd, 0x87, 0xff, 0x00, 0x00, /* 4300K */
	0xff, 0x00, 0x00, 0x00, 0xb9, 0x00, 0x00, 0x00, 0x62, 0x00, 0xb9, 0x62, 0xff, 0x00, 0x62, 0xff, 0xb9, 0x00, 0xff, 0xb9, 0x62, 0xff, 0x00, 0x00, /* 3700K */
	0xff, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, 0x42, 0x00, 0xa4, 0x42, 0xff, 0x00, 0x42, 0xff, 0xa4, 0x00, 0xff, 0xa4, 0x42, 0xff, 0x00, 0x00, /* 3100K */
	0xff, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x78, 0x1a, 0xff, 0x00, 0x1a, 0xff, 0x78, 0x00, 0xff, 0x78, 0x1a, 0xff, 0x00, 0x00, /* 2300K */
	0xc6, 0x00, 0x00, 0x10, 0xf9, 0x00, 0x06, 0x06, 0xcb, 0x19, 0xf0, 0xd9, 0xe2, 0x00, 0xcd, 0xea, 0xda, 0x02, 0xff, 0xf9, 0xee, 0xff, 0x00, 0x00, /* 6500K */
	0xc6, 0x00, 0x00, 0x10, 0xf7, 0x00, 0x06, 0x06, 0xc5, 0x19, 0xee, 0xd1, 0xe2, 0x00, 0xc6, 0xea, 0xd8, 0x02, 0xff, 0xf7, 0xe6, 0xff, 0x00, 0x00, /* 6300K */
	0xc6, 0x00, 0x00, 0x10, 0xf3, 0x00, 0x06, 0x06, 0xbe, 0x19, 0xea, 0xca, 0xe2, 0x00, 0xc0, 0xea, 0xd5, 0x02, 0xff, 0xf3, 0xde, 0xff, 0x00, 0x00, /* 6100K */
	0xc6, 0x00, 0x00, 0x10, 0xef, 0x00, 0x06, 0x06, 0xb7, 0x19, 0xe7, 0xc3, 0xe2, 0x00, 0xb9, 0xea, 0xd1, 0x02, 0xff, 0xef, 0xd6, 0xff, 0x00, 0x00, /* 5900K */
	0xc6, 0x00, 0x00, 0x10, 0xec, 0x00, 0x06, 0x06, 0xaf, 0x19, 0xe4, 0xbb, 0xe2, 0x00, 0xb1, 0xea, 0xce, 0x02, 0xff, 0xec, 0xcd, 0xff, 0x00, 0x00, /* 5700K */
	0xc6, 0x00, 0x00, 0x10, 0xe8, 0x00, 0x06, 0x05, 0xa8, 0x19, 0xe0, 0xb3, 0xe2, 0x00, 0xaa, 0xea, 0xcb, 0x02, 0xff, 0xe8, 0xc5, 0xff, 0x00, 0x00, /* 5500K */
	0xc6, 0x00, 0x00, 0x10, 0xdd, 0x00, 0x06, 0x05, 0x91, 0x19, 0xd5, 0x9b, 0xe2, 0x00, 0x93, 0xea, 0xc1, 0x01, 0xff, 0xdd, 0xaa, 0xff, 0x00, 0x00, /* 4900K */
	0xc6, 0x00, 0x00, 0x10, 0xcd, 0x00, 0x06, 0x05, 0x73, 0x19, 0xc6, 0x7b, 0xe2, 0x00, 0x74, 0xea, 0xb3, 0x01, 0xff, 0xcd, 0x87, 0xff, 0x00, 0x00, /* 4300K */
	0xc6, 0x00, 0x00, 0x10, 0xb9, 0x00, 0x06, 0x04, 0x54, 0x19, 0xb2, 0x59, 0xe2, 0x00, 0x55, 0xea, 0xa2, 0x01, 0xff, 0xb9, 0x62, 0xff, 0x00, 0x00, /* 3700K */
	0xc6, 0x00, 0x00, 0x10, 0xa4, 0x00, 0x06, 0x04, 0x38, 0x19, 0x9e, 0x3c, 0xe2, 0x00, 0x39, 0xea, 0x8f, 0x01, 0xff, 0xa4, 0x42, 0xff, 0x00, 0x00, /* 3100K */
	0xc6, 0x00, 0x00, 0x10, 0x78, 0x00, 0x06, 0x03, 0x16, 0x19, 0x74, 0x18, 0xe2, 0x00, 0x16, 0xea, 0x69, 0x00, 0xff, 0x78, 0x1a, 0xff, 0x00, 0x00, /* 2300K */
};

static char DSI0_BYPASS_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x00, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_BYPASS_MDNIE_2[] = {
	0x62, // CRC
	0x01, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_BYPASS_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_BYPASS_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_COLOR_BLIND_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_COLOR_BLIND_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_COLOR_BLIND_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_COLOR_BLIND_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_NIGHT_MODE_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_NIGHT_MODE_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_NIGHT_MODE_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_NIGHT_MODE_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HBM_CE_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x02, // ACE on/off
	0x1f, // ACE gain
	0x02, // ORE on/off
	0x70, // ORE level
};

static char DSI0_HBM_CE_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HBM_CE_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HBM_CE_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HBM_CE_D65_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x02, // ACE on/off
	0x1f, // ACE gain
	0x02, // ORE on/off
	0x70, // ORE level
};

static char DSI0_HBM_CE_D65_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HBM_CE_D65_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HBM_CE_D65_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_RGB_SENSOR_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_RGB_SENSOR_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_RGB_SENSOR_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_RGB_SENSOR_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_SCREEN_CURTAIN_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_SCREEN_CURTAIN_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0x00, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0x00, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0x00, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0x00, // crc_lut_mode1_cg
	0x00, // crc_lut_mode1_cb
	0x00, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0x00, // crc_lut_mode1_mb
	0x00, // crc_lut_mode1_yr
	0x00, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0x00, // crc_lut_mode1_wr
	0x00, // crc_lut_mode1_wg
	0x00, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_SCREEN_CURTAIN_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_SCREEN_CURTAIN_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x60, // crc_lut_mode1_rg
	0x13, // crc_lut_mode1_rb
	0x66, // crc_lut_mode1_gr
	0xf9, // crc_lut_mode1_gg
	0x13, // crc_lut_mode1_gb
	0x66, // crc_lut_mode1_br
	0x60, // crc_lut_mode1_bg
	0xac, // crc_lut_mode1_bb
	0x66, // crc_lut_mode1_cr
	0xf9, // crc_lut_mode1_cg
	0xac, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x60, // crc_lut_mode1_mg
	0xac, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xf9, // crc_lut_mode1_yg
	0x13, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xf9, // crc_lut_mode1_wg
	0xac, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_LIGHT_NOTIFICATION_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HDR_VIDEO_1_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_HDR_VIDEO_1_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xc6, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x10, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x06, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xda, // crc_lut_mode1_bb
	0x19, // crc_lut_mode1_cr
	0xf6, // crc_lut_mode1_cg
	0xe8, // crc_lut_mode1_cb
	0xe2, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xdc, // crc_lut_mode1_mb
	0xea, // crc_lut_mode1_yr
	0xdf, // crc_lut_mode1_yg
	0x02, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HDR_VIDEO_1_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HDR_VIDEO_1_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HDR_VIDEO_2_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_HDR_VIDEO_2_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xc6, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x10, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x06, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xda, // crc_lut_mode1_bb
	0x19, // crc_lut_mode1_cr
	0xf6, // crc_lut_mode1_cg
	0xe8, // crc_lut_mode1_cb
	0xe2, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xdc, // crc_lut_mode1_mb
	0xea, // crc_lut_mode1_yr
	0xdf, // crc_lut_mode1_yg
	0x02, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HDR_VIDEO_2_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HDR_VIDEO_2_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HDR_VIDEO_3_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_HDR_VIDEO_3_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xc6, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x10, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x06, // crc_lut_mode1_br
	0x06, // crc_lut_mode1_bg
	0xda, // crc_lut_mode1_bb
	0x19, // crc_lut_mode1_cr
	0xf6, // crc_lut_mode1_cg
	0xe8, // crc_lut_mode1_cb
	0xe2, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xdc, // crc_lut_mode1_mb
	0xea, // crc_lut_mode1_yr
	0xdf, // crc_lut_mode1_yg
	0x02, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HDR_VIDEO_3_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HDR_VIDEO_3_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_UI_DYNAMIC_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_UI_DYNAMIC_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xb8, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x12, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x08, // crc_lut_mode1_br
	0x0a, // crc_lut_mode1_bg
	0xc8, // crc_lut_mode1_bb
	0x1c, // crc_lut_mode1_cr
	0xf0, // crc_lut_mode1_cg
	0xe0, // crc_lut_mode1_cb
	0xe2, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xd6, // crc_lut_mode1_mb
	0xe0, // crc_lut_mode1_yr
	0xd4, // crc_lut_mode1_yg
	0x02, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_UI_DYNAMIC_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_UI_DYNAMIC_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_UI_AUTO_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x02, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_UI_AUTO_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_UI_AUTO_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_UI_AUTO_MDNIE_4[] = {
	0x62, // TCS
	0x20, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x12, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_GALLERY_AUTO_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x02, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_GALLERY_AUTO_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x14, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xf0, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xff, // crc_lut_mode1_wg
	0xff, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_GALLERY_AUTO_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_GALLERY_AUTO_MDNIE_4[] = {
	0x62, // TCS
	0x20, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_EBOOK_AUTO_MDNIE_1[] = {
	//start
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_EBOOK_AUTO_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x14, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xff, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xf0, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xef, // crc_lut_mode1_wg
	0xd6, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_EBOOK_AUTO_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_EBOOK_AUTO_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1[] = {
	0x5D, // CRC
	0x06, // CRC on/off
	0x00,
	0x00, // TCS on/off
	0x00, // ACE on/off
	0x00, // ACE gain
	0x00, // ORE on/off
	0x00, // ORE level
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2[] = {
	0x62, // CRC
	0x00, // crc_bypass
	0xff, // crc_lut_mode1_rr
	0x00, // crc_lut_mode1_rg
	0x00, // crc_lut_mode1_rb
	0x00, // crc_lut_mode1_gr
	0xff, // crc_lut_mode1_gg
	0x00, // crc_lut_mode1_gb
	0x00, // crc_lut_mode1_br
	0x00, // crc_lut_mode1_bg
	0xf5, // crc_lut_mode1_bb
	0x00, // crc_lut_mode1_cr
	0xff, // crc_lut_mode1_cg
	0xff, // crc_lut_mode1_cb
	0xff, // crc_lut_mode1_mr
	0x00, // crc_lut_mode1_mg
	0xff, // crc_lut_mode1_mb
	0xff, // crc_lut_mode1_yr
	0xff, // crc_lut_mode1_yg
	0x00, // crc_lut_mode1_yb
	0xff, // crc_lut_mode1_wr
	0xfa, // crc_lut_mode1_wg
	0xf0, // crc_lut_mode1_wb
	0xff, // crc_lut_mode2_rr_temp
	0x00, // crc_lut_mode2_rg_temp
	0x00, // crc_lut_mode2_rb_temp
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3[] = {
	0xb0,
	0x00,
	0xa0,
	0x62,
};

static char DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4[] = {
	0x62, // TCS
	0x21, // bypass, y_type
	0x01, // obj_sel, skin_boundary_para
	0x79, // skin_boundary_para
	0x00,
	0x01,
	0x00,
	0x04,
	0x01,
	0x1E,
	0x80,
	0x01,
	0x00,
	0x02,
	0x01, // grass_boundary_para
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x59,
	0x01, // sky_boundary_para
	0x02,
	0x49,
	0x01,
	0x00,
	0x60,
	0x01,
	0x02,
	0x5A,
	0x01,
	0x00,
	0x63,
	0x00, // skin_boundary_para
	0x00,
	0xFF,
	0x00,
	0x00,
	0x86,
	0x00,
	0x11,
	0xAC,
	0x00,
	0x00,
	0xFF,
	0x00, // grass_boundary_para
	0x00,
	0x9F,
	0x00,
	0x00,
	0x33,
	0x00,
	0x00,
	0xF0,
	0x00,
	0x00,
	0x72,
	0x00, // sky_boundary_para
	0x01,
	0xAE,
	0x00,
	0x00,
	0x89,
	0x00,
	0x02,
	0x16,
	0x00,
	0x00,
	0xB3,
	0x00, // skin_boundary_para
	0x00,
	0x04,
	0x00,
	0x8F,
	0x00,
	0x01,
	0x00,
	0x87,
	0x01,
	0x02,
	0x22,
	0x00, // grass_boundary_para
	0x0B,
	0x24,
	0x00,
	0x0A,
	0x18,
	0x01,
	0x04,
	0x6A,
	0x01,
	0x06,
	0xCD,
	0x00, // sky_boundary_para
	0x04,
	0x98,
	0x00,
	0x0F,
	0xC1,
	0x01,
	0x06,
	0xE6,
	0x01,
	0x0A,
	0xE1,
	0x64, // skin_boundary_idx
	0x62, // grass_boundary_idx
	0x61, // sky_boundary_idx
	0x24, // Skin Color Gain
	0x80, // grass Color Gain
	0x80, // sky Color Gai
	0x80, // Target Skin Color (Cb)
	0x52, // Target grass Color (Cb)
	0xAE, // Target Sky Color (Cb)
	0x86, // Target Skin Color (Cr)
	0x69, // Target grass Color (Cr)
	0x58, // Target Sky Color (Cr)
	0x00, // Threshold Value of Skin Color Detection
	0x00, // Threshold Value of grass Color Detection
	0x00, // Threshold Value of Sky Color Detection
	0x32, // Minumum Y of Skin Brightness Control
	0x1E, // Minumum Y of grass Brightness Control
	0x1E, // Minumum Y of Sky Brightness Control
	0xDC, // Maximum Y of Skin Brightness Control
	0xC8, // Maximum Y of grass Brightness Control
	0xC8, // Maximum Y of Sky Brightness Control
	0x88, // Reference Y of Skin Brightness Control
	0x78, // Reference Y of grass Brightness Control
	0x78, // Reference Y of Sky Brightness Control
	0x8A, // Target Y of Skin Brihgtness Contol
	0x78, // Target Y of grass Brihgtness Contol
	0x78, // Target Y of Sky Brihgtness Contol
	0x00, // Brightness Parameter
	0x24,
	0x00,
	0x00,
	0x00,
	0x00,
	0x00,
	0x8A,
	0x00,
	0x80,
	0x00,
	0x80,
	0x01,
	0x86,
	0x00,
	0x00,
	0x00,
	0x00,
	0x82,
	0xFA,
	0x80,
	0x00,
	0x80,
	0x00,
	0x7C,
	0xF4,
	0x80,
	0x00,
	0x80,
	0x00,
	0x00, // dummy 0x62 P326
	0x00, // dummy 0x62 P327
	0x00, // dummy 0x62 P328
	0x00, // dummy 0x62 P329
	0x00, // dummy 0x62 P330
	0x00, // ACE bypass : 0x01, ACE on : 0x00
	0xf0,
	0x03,
	0xff,
	0x04,
	0xc8,
	0xc8,
	0xff,
	0xff,
	0x28,
	0x28,
	0x3c,
	0x00,
	0x00,
	0x05,
	0x00,
	0x64,
	0x1e,
	0x1e,
	0x10,
	0x01,
	0x00,
	0x10,
	0x64,
	0x06,
	0x08,
	0x08,
	0x10,
	0x00,
	0x20,
	0x00,
	0x10,
	0x00,
	0x04,
	0x10,
	0x0a,
	0x00,
	0x00,
	0x00,
	0x02,
	0x00,
	0x04,
	0x00,
	0xff,
	0x00,
	0xff,
	0x00,
};

static struct dsi_cmd_desc DSI0_BYPASS_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_1), DSI0_BYPASS_MDNIE_1, 0, NULL}, false, 0, DSI0_BYPASS_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_2), DSI0_BYPASS_MDNIE_2, 0, NULL}, false, 0, DSI0_BYPASS_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_3), DSI0_BYPASS_MDNIE_3, 0, NULL}, false, 0, DSI0_BYPASS_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_BYPASS_MDNIE_4), DSI0_BYPASS_MDNIE_4, 0, NULL}, false, 0, DSI0_BYPASS_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_COLOR_BLIND_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_1), DSI0_COLOR_BLIND_MDNIE_1, 0, NULL}, false, 0, DSI0_COLOR_BLIND_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_2), DSI0_COLOR_BLIND_MDNIE_2, 0, NULL}, false, 0, DSI0_COLOR_BLIND_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_3), DSI0_COLOR_BLIND_MDNIE_3, 0, NULL}, false, 0, DSI0_COLOR_BLIND_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_COLOR_BLIND_MDNIE_4), DSI0_COLOR_BLIND_MDNIE_4, 0, NULL}, false, 0, DSI0_COLOR_BLIND_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_NIGHT_MODE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_1), DSI0_NIGHT_MODE_MDNIE_1, 0, NULL}, false, 0, DSI0_NIGHT_MODE_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_2), DSI0_NIGHT_MODE_MDNIE_2, 0, NULL}, false, 0, DSI0_NIGHT_MODE_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_3), DSI0_NIGHT_MODE_MDNIE_3, 0, NULL}, false, 0, DSI0_NIGHT_MODE_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_NIGHT_MODE_MDNIE_4), DSI0_NIGHT_MODE_MDNIE_4, 0, NULL}, false, 0, DSI0_NIGHT_MODE_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HBM_CE_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_1), DSI0_HBM_CE_MDNIE_1, 0, NULL}, false, 0, DSI0_HBM_CE_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_2), DSI0_HBM_CE_MDNIE_2, 0, NULL}, false, 0, DSI0_HBM_CE_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_3), DSI0_HBM_CE_MDNIE_3, 0, NULL}, false, 0, DSI0_HBM_CE_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_MDNIE_4), DSI0_HBM_CE_MDNIE_4, 0, NULL}, false, 0, DSI0_HBM_CE_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HBM_CE_D65_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_1), DSI0_HBM_CE_D65_MDNIE_1, 0, NULL}, false, 0, DSI0_HBM_CE_D65_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_2), DSI0_HBM_CE_D65_MDNIE_2, 0, NULL}, false, 0, DSI0_HBM_CE_D65_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_3), DSI0_HBM_CE_D65_MDNIE_3, 0, NULL}, false, 0, DSI0_HBM_CE_D65_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HBM_CE_D65_MDNIE_4), DSI0_HBM_CE_D65_MDNIE_4, 0, NULL}, false, 0, DSI0_HBM_CE_D65_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_RGB_SENSOR_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_1), DSI0_RGB_SENSOR_MDNIE_1, 0, NULL}, false, 0, DSI0_RGB_SENSOR_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_2), DSI0_RGB_SENSOR_MDNIE_2, 0, NULL}, false, 0, DSI0_RGB_SENSOR_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_3), DSI0_RGB_SENSOR_MDNIE_3, 0, NULL}, false, 0, DSI0_RGB_SENSOR_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_RGB_SENSOR_MDNIE_4), DSI0_RGB_SENSOR_MDNIE_4, 0, NULL}, false, 0, DSI0_RGB_SENSOR_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_SCREEN_CURTAIN_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_1), DSI0_SCREEN_CURTAIN_MDNIE_1, 0, NULL}, false, 0, DSI0_SCREEN_CURTAIN_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_2), DSI0_SCREEN_CURTAIN_MDNIE_2, 0, NULL}, false, 0, DSI0_SCREEN_CURTAIN_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_3), DSI0_SCREEN_CURTAIN_MDNIE_3, 0, NULL}, false, 0, DSI0_SCREEN_CURTAIN_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_SCREEN_CURTAIN_MDNIE_4), DSI0_SCREEN_CURTAIN_MDNIE_4, 0, NULL}, false, 0, DSI0_SCREEN_CURTAIN_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_LIGHT_NOTIFICATION_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_1), DSI0_LIGHT_NOTIFICATION_MDNIE_1, 0, NULL}, false, 0, DSI0_LIGHT_NOTIFICATION_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_2), DSI0_LIGHT_NOTIFICATION_MDNIE_2, 0, NULL}, false, 0, DSI0_LIGHT_NOTIFICATION_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_3), DSI0_LIGHT_NOTIFICATION_MDNIE_3, 0, NULL}, false, 0, DSI0_LIGHT_NOTIFICATION_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_LIGHT_NOTIFICATION_MDNIE_4), DSI0_LIGHT_NOTIFICATION_MDNIE_4, 0, NULL}, false, 0, DSI0_LIGHT_NOTIFICATION_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_1_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_1), DSI0_HDR_VIDEO_1_MDNIE_1, 0, NULL}, false, 0, DSI0_HDR_VIDEO_1_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_2), DSI0_HDR_VIDEO_1_MDNIE_2, 0, NULL}, false, 0, DSI0_HDR_VIDEO_1_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_3), DSI0_HDR_VIDEO_1_MDNIE_3, 0, NULL}, false, 0, DSI0_HDR_VIDEO_1_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_1_MDNIE_4), DSI0_HDR_VIDEO_1_MDNIE_4, 0, NULL}, false, 0, DSI0_HDR_VIDEO_1_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_2_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_1), DSI0_HDR_VIDEO_2_MDNIE_1, 0, NULL}, false, 0, DSI0_HDR_VIDEO_2_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_2), DSI0_HDR_VIDEO_2_MDNIE_2, 0, NULL}, false, 0, DSI0_HDR_VIDEO_2_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_3), DSI0_HDR_VIDEO_2_MDNIE_3, 0, NULL}, false, 0, DSI0_HDR_VIDEO_2_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_2_MDNIE_4), DSI0_HDR_VIDEO_2_MDNIE_4, 0, NULL}, false, 0, DSI0_HDR_VIDEO_2_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HDR_VIDEO_3_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_1), DSI0_HDR_VIDEO_3_MDNIE_1, 0, NULL}, false, 0, DSI0_HDR_VIDEO_3_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_2), DSI0_HDR_VIDEO_3_MDNIE_2, 0, NULL}, false, 0, DSI0_HDR_VIDEO_3_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_3), DSI0_HDR_VIDEO_3_MDNIE_3, 0, NULL}, false, 0, DSI0_HDR_VIDEO_3_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HDR_VIDEO_3_MDNIE_4), DSI0_HDR_VIDEO_3_MDNIE_4, 0, NULL}, false, 0, DSI0_HDR_VIDEO_3_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_UI_DYNAMIC_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_1), DSI0_UI_DYNAMIC_MDNIE_1, 0, NULL}, false, 0, DSI0_UI_DYNAMIC_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_2), DSI0_UI_DYNAMIC_MDNIE_2, 0, NULL}, false, 0, DSI0_UI_DYNAMIC_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_3), DSI0_UI_DYNAMIC_MDNIE_3, 0, NULL}, false, 0, DSI0_UI_DYNAMIC_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_DYNAMIC_MDNIE_4), DSI0_UI_DYNAMIC_MDNIE_4, 0, NULL}, false, 0, DSI0_UI_DYNAMIC_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_UI_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_1), DSI0_UI_AUTO_MDNIE_1, 0, NULL}, false, 0, DSI0_UI_AUTO_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_2), DSI0_UI_AUTO_MDNIE_2, 0, NULL}, false, 0, DSI0_UI_AUTO_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_3), DSI0_UI_AUTO_MDNIE_3, 0, NULL}, false, 0, DSI0_UI_AUTO_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_UI_AUTO_MDNIE_4), DSI0_UI_AUTO_MDNIE_4, 0, NULL}, false, 0, DSI0_UI_AUTO_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_GALLERY_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_1), DSI0_GALLERY_AUTO_MDNIE_1, 0, NULL}, false, 0, DSI0_GALLERY_AUTO_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_2), DSI0_GALLERY_AUTO_MDNIE_2, 0, NULL}, false, 0, DSI0_GALLERY_AUTO_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_3), DSI0_GALLERY_AUTO_MDNIE_3, 0, NULL}, false, 0, DSI0_GALLERY_AUTO_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_GALLERY_AUTO_MDNIE_4), DSI0_GALLERY_AUTO_MDNIE_4, 0, NULL}, false, 0, DSI0_GALLERY_AUTO_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_EBOOK_AUTO_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_1), DSI0_EBOOK_AUTO_MDNIE_1, 0, NULL}, false, 0, DSI0_EBOOK_AUTO_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_2), DSI0_EBOOK_AUTO_MDNIE_2, 0, NULL}, false, 0, DSI0_EBOOK_AUTO_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_3), DSI0_EBOOK_AUTO_MDNIE_3, 0, NULL}, false, 0, DSI0_EBOOK_AUTO_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_EBOOK_AUTO_MDNIE_4), DSI0_EBOOK_AUTO_MDNIE_4, 0, NULL}, false, 0, DSI0_EBOOK_AUTO_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc DSI0_HMT_COLOR_TEMP_6500K_MDNIE[] = {
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_on), level_0_key_on, 0, NULL}, false, 0, level_0_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_on), level_1_key_on, 0, NULL}, false, 0, level_1_key_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_on), multi_cmd_on, 0, NULL}, false, 0, multi_cmd_on},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1, 0, NULL}, false, 0, DSI0_HMT_COLOR_TEMP_6500K_MDNIE_1},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2, 0, NULL}, false, 0, DSI0_HMT_COLOR_TEMP_6500K_MDNIE_2},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3, 0, NULL}, false, 0, DSI0_HMT_COLOR_TEMP_6500K_MDNIE_3},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4), DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4, 0, NULL}, false, 0, DSI0_HMT_COLOR_TEMP_6500K_MDNIE_4},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_off), multi_cmd_off, 0, NULL}, false, 20, multi_cmd_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(multi_cmd_dummy), multi_cmd_dummy, 0, NULL}, false, 0, multi_cmd_dummy},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_1_key_off), level_1_key_off, 0, NULL}, true, 0, level_1_key_off},
	{{0, MIPI_DSI_DCS_LONG_WRITE, 0, 0, 0, sizeof(level_0_key_off), level_0_key_off, 0, NULL}, true, 0, level_0_key_off},
};

static struct dsi_cmd_desc *mdnie_tune_value_dsi0[MAX_APP_MODE][MAX_MODE][MAX_OUTDOOR_MODE] = {
	/*
		DYNAMIC_MODE
		STANDARD_MODE
		NATURAL_MODE
		MOVIE_MODE
		AUTO_MODE
		READING_MODE
	*/
	/* UI_APP */
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_UI_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* VIDEO_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE, NULL},
	},
	/* VIDEO_WARM_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* VIDEO_COLD_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* CAMERA_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* NAVI_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* GALLERY_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* VT_APP*/
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* BROWSER_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	/* eBOOK_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// EMAIL_APP
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_UI_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
	// GAME_LOW_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// GAME_MID_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// GAME_HIGH_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// VIDEO_ENHANCER_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	// VIDEO_ENHANCER_THIRD_APP
	{
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
	},
	/* TDMB_APP*/
	{
		{DSI0_UI_DYNAMIC_MDNIE,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{NULL,	NULL},
		{DSI0_GALLERY_AUTO_MDNIE,	NULL},
		{DSI0_EBOOK_AUTO_MDNIE,	NULL},
	},
};
static struct dsi_cmd_desc *hmt_color_temperature_tune_value_dsi0[HMT_COLOR_TEMP_MAX] = {
	/*
		HMT_COLOR_TEMP_3000K, // 3000K
		HMT_COLOR_TEMP_4000K, // 4000K
		HMT_COLOR_TEMP_5000K, // 5000K
		HMT_COLOR_TEMP_6500K, // 6500K
		HMT_COLOR_TEMP_7500K, // 7500K
	*/
	NULL,
	NULL,
	NULL,
	NULL,
	DSI0_HMT_COLOR_TEMP_6500K_MDNIE,
	NULL,
};

static struct dsi_cmd_desc *light_notification_tune_value_dsi0[LIGHT_NOTIFICATION_MAX] = {
	NULL,
	DSI0_LIGHT_NOTIFICATION_MDNIE,
};

static struct dsi_cmd_desc *hdr_tune_value_dsi0[HDR_MAX] = {
	NULL,
	DSI0_HDR_VIDEO_1_MDNIE,
	DSI0_HDR_VIDEO_2_MDNIE,
	DSI0_HDR_VIDEO_3_MDNIE,
	NULL,
	NULL,
};

#define DSI0_RGB_SENSOR_MDNIE_1_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_1)
#define DSI0_RGB_SENSOR_MDNIE_2_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_2)
#define DSI0_RGB_SENSOR_MDNIE_3_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_3)
#define DSI0_RGB_SENSOR_MDNIE_4_SIZE ARRAY_SIZE(DSI0_RGB_SENSOR_MDNIE_4)

#endif
