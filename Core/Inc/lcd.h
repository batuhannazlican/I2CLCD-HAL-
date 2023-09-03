/*
 * lcd.h
 *
 *  Created on: 28 Ağu 2023
 *      Author: Batu
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "main.h"

#define LCD_SLAVE_ADDRESS    		0x3F<<1

#define LCD_CLEAR   		    	0X01
#define LCD_RETURNHOME  		    0x02
#define LCD_ENTRY_MODE       	    0x06
#define LCD_DISPLAY_ON 	   	        0x0C
#define LCD_DISPLAY_OFF		        0x08
#define LCD_CURSOR_OFF  		    0x0C
#define LCD_CURSOR_ON   		    0x0D
#define LCD_BLINKCURSORON		    0x0F
#define LCD_MOVECURSOR_LEFT         0x10
#define LCD_MOVECURSOR_RIGHT        0x14
#define LCD_SHIFT_LEFT              0x18
#define LCD_SHIFT_RIGHT             0x1C



#define LCD_SET_DDRAM_ADRESS 		0x80
#define _4BIT						0x00
#define _8BIT						0x10

void lcd_send_command (char cmd) ;
void LCD_init (void) ;
void lcd_home () ;
void lcd_clear();
void lcd_shift2line();
void lcd_send_string(char *str);

#define FIRST_ROW					0x80
#define SECOND_ROW 					0xC0

#endif /* INC_LCD_H_ */
