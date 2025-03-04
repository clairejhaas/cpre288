
/*
 * sensor.h
 *
 *  Created on: Feb 12, 2025
 *      Author: cjhaas
 */

#ifndef SENSOR_H_
#define SENSOR_H_

typedef struct {
            int start_angle;
            int end_angle;
            int middle_angle;
            int distance;
            int radial_width;
} detected_object;

void send_string(char data[]);
void send_string_uart_library_putty(char msg[]);
void send_string_uart_library_lcd(char msg[]);



#endif /* SENSOR_H_ */
