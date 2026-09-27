#include "uart.h"
#include "timer.h"
#include "interrupt.h"
#include "app_tasks.h"

#define GPIOB_EN	(1U<<1)
#define GPIOC_EN	(1U<<2)

char *msg1="Hello\r\n";
char *msg2="Bye\r\n";

SemaphoreHandle_t uart_mutex;//mutex handle

EventGroupHandle_t	button_events;

TaskHandle_t led_handle;

int main()
{
	SetClock_16MHz();
	uart_init();

	RCC->AHB2ENR|=(GPIOB_EN|GPIOC_EN);
	GPIOB->MODER&=~(3U<<26);
	GPIOC->MODER&=~(3U<<26);
	GPIOB->MODER|=(1U<<26);

	uart_mutex=xSemaphoreCreateMutex();//Creating Mutex

	button_events=xEventGroupCreate();


	xTaskCreate(task1,"Task1",256,msg1,3,NULL);
	xTaskCreate(task2,"Task2",256,msg2,4,NULL);
	xTaskCreate(ButtonTask,"ButtonTask",256,NULL,2,NULL);
	xTaskCreate(led_task,"LEDTask",256,NULL,1,&led_handle); //Handle created
	vTaskStartScheduler();
	while(1){}

}

