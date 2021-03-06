/*
 * drivers/input/touchscreen/gt801_ts.h
 *
 * Copyright (C) 2010 ROCKCHIP, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __DRIVERS_TOUCHSCREEN_GT801_TS_H
#define __DRIVERS_TOUCHSCREEN_GT801_TS_H

#define IOMUX_NAME_SIZE 48

#define GT801_OPT_SWAP_XY   (1<<0)
#define GT801_OPT_INV_X     (1<<1)
#define GT801_OPT_INV_Y     (1<<2)

enum regadd {
	ptxh = 0, ptxl = 1, ptyh = 2, ptyl = 3, ptpressure = 4,
};
enum touchstate {
	TOUCH_UP = 0, TOUCH_DOWN = 1,
};	

struct gt801_platform_data {

	u16		model;			/* 801. */
	u16	    options;		/* swap x and y axes, etc */
	u16		x_min, x_max;
	u16		y_min, y_max;
    int 	gpio_reset;
    int     gpio_reset_active_low;
	int		gpio_pendown;		/* the GPIO used to decide the pendown */

	char	pendown_iomux_name[IOMUX_NAME_SIZE];
	char	resetpin_iomux_name[IOMUX_NAME_SIZE];
	int		pendown_iomux_mode;
	int		resetpin_iomux_mode;
	
	int	    (*get_pendown_state)(void);
    int     (*init_platform_hw)(void);
};
#endif
