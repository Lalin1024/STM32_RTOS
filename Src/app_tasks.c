#include "app_tasks.h"
#include "uart.h"
#include "timer.h"

void task1(void *para)
{
	char *val=(char *)para;
	while(1)
	{
		xQueueSend(myqueue,&val,pdMS_TO_TICKS(100));
		vTaskDelay(pdMS_TO_TICKS(1000));
}
}

void task2(void *para)
{
	char *receive=NULL;
	while(1)
	{
		xQueueReceive(myqueue,&receive,portMAX_DELAY);
		uart_write(receive);
}
}


void task3(void *para)
{
	while(1)
	{
		xSemaphoreTake(led_sema,portMAX_DELAY);
		uart_write("Button Pressed\r\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
}
}

void led_task(void *para)
{
	while(1)
	{
		xSemaphoreTake(led_sema,portMAX_DELAY);
		GPIOB->BSRR=(1U<<13);
		vTaskDelay(1000);
		GPIOB->BSRR=(1U<<29);
		vTaskDelay(1000);
	}
}
