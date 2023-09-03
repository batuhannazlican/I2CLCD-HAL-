/*
 * lcd.c
 *
 *  Created on: 28 Ağu 2023
 *      Author: Batu
 */
#include "stdint.h"
#include "I2C.h"
#include "lcd.h"

extern I2C_HandleTypeDef hi2c1 ;
void lcd_send_command (char cmd)
 {
	char data_u,data_l ;
	uint8_t data[4] ;

    data_u = (cmd & 0xF0)   ;
	data_l = (cmd<<4 & 0xF0);


	data[0] = data_u | LCD_DISPLAY_ON  ;
	data[1] = data_u | LCD_DISPLAY_OFF ;
	data[2] = data_l | LCD_DISPLAY_ON  ;
	data[3] = data_l | LCD_DISPLAY_OFF ;


   HAL_I2C_Master_Transmit(&hi2c1,LCD_SLAVE_ADDRESS, (uint8_t)* data,4,100);



 }


void lcd_sendData(char data_cmd)
{
	char data_u,data_l ;
	uint8_t data[4] ;

    data_u = (data_cmd & 0xF0)   ;
	data_l = (data_cmd<<4 & 0xF0);


	data[0] = data_u | 0x0D ;
	data[1] = data_u | 0x09 ;
	data[2] = data_l | 0x0D ;
	data[3] = data_l | 0x09 ;

	HAL_I2C_Master_Transmit(&hi2c1,LCD_SLAVE_ADDRESS, (uint8_t)* data,4,100);

}

void LCD_init (void)
{
	HAL_Delay(100) ;
    lcd_send_command (LCD_RETURNHOME) ;
    HAL_Delay(500) ;
    lcd_send_command (LCD_ENTRY_MODE)  ;
    HAL_Delay(500) ;
    lcd_send_command (LCD_CURSOR_OFF) ;
    HAL_Delay(500) ;
    lcd_send_command (LCD_SET_DDRAM_ADRESS) ;
    HAL_Delay(500) ;
    lcd_send_command (LCD_CLEAR) ;
    HAL_Delay(500) ;


}
void lcd_home ()
{
	lcd_send_command(LCD_RETURNHOME) ;
}
void lcd_clear()
{
	lcd_send_command(LCD_CLEAR) ;
}
void lcd_shift2line()
{
	lcd_send_command(SECOND_ROW)     ;
	lcd_send_command(LCD_CURSOR_OFF) ;
}
void lcd_send_string(char *str)
{
	    HAL_Delay(25) ;
		while(*str)
		lcd_sendData(*str++) ;
}




