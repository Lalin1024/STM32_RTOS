#include "uart.h"
#include "timer.h"
#include "interrupt.h"
#include "app_tasks.h"

#define GPIOB_EN	(1U<<1)

char *msg1="Hello\r\n";
char *msg2="Bye\r\n";

SemaphoreHandle_t uart_mutex;//mutex handle

int main()
{
	SetClock_16MHz();
	uart_init();

	RCC->AHB2ENR|=GPIOB_EN;
	GPIOB->MODER&=~(3U<<26);
	GPIOB->MODER|=(1U<<26);

	uart_mutex=xSemaphoreCreateMutex();//Creating Mutex




	xTaskCreate(task1,"Task1",256,msg1,1,NULL);
	xTaskCreate(task2,"Task2",256,msg2,3,NULL);
	vTaskStartScheduler();
	while(1){}

}


