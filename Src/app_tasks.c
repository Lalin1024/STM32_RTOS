/*
 * app_tasks.c
 *
 *  Created on: Aug 12, 2026
 *      Author: LalinPrasadC
 */

#include "app_tasks.h"
#include "uart.h"

void task1(void *para)
{
	char *val=(char *) para;
    while(1)
    {

    	uart_write(val);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void task2(void *para)
{
char *msg=(char *) para;
    while(1)
    {
   uart_write(msg);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}



