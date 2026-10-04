#include "app_tasks.h"
#include "uart.h"
#include "timer.h"

#define BUTTON1	(1U<<0)
#define BUTTON2	(1U<<1)



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

void button_task(void *para)
{
	while(1)
		{
			if(GPIOC->IDR & (1U<<13))
			{
			xTaskNotify(led_handle,0,eNoAction);
		}
			vTaskDelay(pdMS_TO_TICKS(500));
	}
}


void led_task(void* para)
{
	while(1)
	{
		xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);//Waiting till it get notified
		GPIOB->BSRR|=(1U<<13);
		vTaskDelay(pdMS_TO_TICKS(1000));
		GPIOB->BSRR|=(1U<<29);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
