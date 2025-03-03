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


#warning "Possible unimplemented functions"
#define REPLACEME 0



int main(void) {
	button_init();
	timer_init(); // Must be called before lcd_init(), which uses timer functions
	lcd_init();

  // initialize the cyBot UART1 before trying to use it

  // (Uncomment ME for UART init part of lab)
	cyBot_uart_init_clean();  // Clean UART1 initialization, before running your UART1 GPIO init code

//		// Initialize the scan
//	  // cyBOT_init_Scan();
//		// Remember servo calibration function and variables from Lab 3
//
//	// YOUR CODE HERE

	uart_init();
	int buffer = 0;
	char buffer_array[21];

	while(1)
	{
	    char data = uart_receive();
		
		// char msg[50];
	    // sprintf(msg, "Received a %c\n\r", data); // From lab 3
		
		// send_string_uart_library(data); // debug one character at a time

		
		while (data != '\r') | (buffer < 20) {
			sprintf(buffer_array,"%c",data);
			// Debug printing by sending one byte at a time. Will need to comment out later
			send_string_uart_library(data);

			buffer +=1;

		}
		if (data == '\r') | (buffer == 20){
			lcd_clear();
			send_string_uart_library(buffer_array);
			buffer = 0; // resets buffer

		}
		
		
	}

}
