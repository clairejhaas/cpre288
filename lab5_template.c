
/**
 * lab5_template.c
 *
 * Template file for CprE 288 Lab 5
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 *
 * @author Phillip Jones, updated 6/4/2019
 * @author Diane Rover, updated 2/25/2021, 2/17/2022
 */

#include "button.h"
#include "timer.h"
#include "lcd.h"
#include "sensor.h"
#include "uart.h"

#include "cyBot_uart.h"  // Functions for communicating between CyBot and Putty (via UART1)
                         // PuTTy: Baud=115200, 8 data bits, No Flow Control, No Parity, COM1

#include "cyBot_Scan.h"  // Scan using CyBot servo and sensors


// #warning "Possible unimplemented functions"


int main(void) {
    button_init();
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();

  // initialize the cyBot UART1 before trying to use it

  // (Uncomment ME for UART init part of lab)
    cyBot_uart_init_clean();  // Clean UART1 initialization, before running your UART1 GPIO init code

//      // Initialize the scan
//    // cyBOT_init_Scan();
//      // Remember servo calibration function and variables from Lab 3
//
//  // YOUR CODE HERE

    uart_init();

    char msg[2];
    char buffer_array[21];
    while(1)
    {
        char data = uart_receive();
        sprintf(msg, "%c", data); // Format to array to fit lab 3 syntax

        // if the buffer_array becomes 20 or is enter. Stop and print out line on LCD
        if(strlen(buffer_array) == 20 | data == '\r') {
            lcd_clear();
            lcd_printf(buffer_array);
        }
        else {
            strncat(buffer_array, &data, 1);
            send_string_uart_library(msg); // sends character to PuTTy and LCD one by one

            // will need to do some formatting to get on correct LCD line
            // prints the size of the buffer
            lcd_printf("%d",strlen(buffer_array));
        }

    }

}
