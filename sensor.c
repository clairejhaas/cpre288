
/*
 * sensor.c
 *
 *  Created on: Feb 12, 2025
 *      Author: cjhaas
 */

#include "sensor.h"
#include "cyBot_uart.h"
#include "cyBot_Scan.h"
#include <stdio.h>
#include "lcd.h"
#include <string.h>
#include "uart.h"


void send_string(char msg[]){
        int i;
        for (i = 0; i < strlen(msg); i++){
            cyBot_sendByte(msg[i]);
        }

        // lcd_printf(msg);
        // lcd_clear();
}

void send_string_our_method(char msg[]){
        int i;
        for (i = 0; i < strlen(msg); i++){
            uart_sendChar(msg[i]);
        }

        // lcd_printf(msg);
        // lcd_clear();
}




