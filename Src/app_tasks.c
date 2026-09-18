#include "app_tasks.h"
#include "uart.h"
#include "timer.h"

void task1(void *para)
{
	char *receive1=(char *)para;
	while(1)
	{
		xSemaphoreTake(uart_mutex,portMAX_DELAY);
		uart_write(receive1);
		xSemaphoreGive(uart_mutex);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void task2(void *para)
{
	char *receive2=(char *)para;
	while(1)
	{
		xSemaphoreTake(uart_mutex,portMAX_DELAY);
		uart_write(receive2);
		xSemaphoreGive(uart_mutex);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

