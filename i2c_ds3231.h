/*!
	\file 		i2c_ds3231.h
    \author 	s2xxx (slava@s2xxx.ru)
    \version 	0.1
    \date 		31 июля 2015 г.

    \warning
	\todo		TODO
    \brief		work with ds3231

	This file contain header for implementation i2c real time clock DS3231

*/

#ifndef I2C_DS3231_H_
#define I2C_DS3231_H_
/* Includes -----------------------------------------------------------------*/
/* Defines ------------------------------------------------------------------*/
#define ds3231_I2C_ADDR        0x68
/* Macros -------------------------------------------------------------------*/
/* Typedefs -----------------------------------------------------------------*/
/* Variables-----------------------------------------------------------------*/

ErrorStatus ds3231_get_time(u8_t *sec, u8_t *min, u8_t *hour);


#endif /* I2C_DS3231_H_ */
