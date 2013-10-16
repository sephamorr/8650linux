/*
 * include/linux/nsa3xx.hwmon.h
 *
 * Platform data structure for ZyXEL NSA3xx hwmon driver
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#ifndef __LINUX_NSA3XX_HWMON_H
#define __LINUX_NSA3XX_HWMON_H

struct nsa3xx_hwmon_platform_data {
	/* GPIO pins */
	unsigned act_pin;
	unsigned clk_pin;
	unsigned data_pin;
};

#endif /* __LINUX_NSA3XX_HWMON_H */
