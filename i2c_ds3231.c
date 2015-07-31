/*!
	\file 		i2c_ds3231.c
    \author 	s2xxx (slava@s2xxx.ru)
    \version 	0.1
    \date 		31 июля 2015 г.

    \warning
	\todo		TODO
    \brief		work with ds3231

	This file contain header for implementation i2c real time clock DS3231

*/

/* Includes -----------------------------------------------------------------*/
#include "i2c_ds3231.h"
#include "i2c.h"
/* Defines ------------------------------------------------------------------*/
#define REG_SECOND		0x00
#define REG_MINUTE		0x01
#define REG_HOUR		0x02
#define REG_DAY			0x03
#define REG_DATE		0x04
#define REG_MONTH		0x05
#define REG_YEAR		0x06
#define REG_CONTROL		0x0E
#define REG_STATUS		0x0F
/* Macros -------------------------------------------------------------------*/
/* Typedefs -----------------------------------------------------------------*/
/* Variables-----------------------------------------------------------------*/
/* Function prototype -------------------------------------------------------*/

ErrorStatus ds3231_get_time(u8_t *sec, u8_t *min, u8_t *hour)
{
	ErrorStatus res = ERROR;

	if (SUCCESS == i2c_read(ds3231_I2C_ADDR, &cur_val, 1))
	{

	}
	else
	{
		LOG_WR_WARNING("read i2c data ERROR");
	}

	return res;
}
