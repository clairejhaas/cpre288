
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

        //add the char to the buffer array as long as it isn't a return character
        if (data != '\r') {
            strncat(buffer_array, &data, 1);
        }

        // if the buffer_array becomes 20 or is enter. Stop and print out line on LCD
        if(strlen(buffer_array) == 20 || data == '\r') {
            lcd_clear();
            //makes sure 20 chars are printed and spaces fill in the gaps. Had to do this because \n had weird bugs when the buffer_array had only one char
            lcd_printf("%-20s%d", buffer_array, strlen(buffer_array));
            //if the char is a \r, send a newline and return to putty (part 3)
            if (data == '\r'){
                send_string_uart_library_putty("\n\r");
            }

//            uart_sendStr("\nEnd of message"); //demonstrates the sendStr function
            break;
        }
        else {
            send_string_uart_library_putty(msg); // send string to putty (msg should only contain one char)

            // prints the current char in msg and the size of the buffer under it
            lcd_printf("%c\n%d", msg[0], strlen(buffer_array));
            //lcd_printf("\n%d",strlen(buffer_array));
        }

    }

}
