#include "app_tasks.h"
#include "uart.h"
#include "timer.h"
#include "interrupt.h"

#define GPIOB_EN	(1U<<1)

//QueueHandle_t myqueue;
//SemaphoreHandle_t button_sem;


//void EXTI15_10_IRQHandler();


int main()
{

	char *msg1="Hello\r\n";
	char *msg2="Bye\r\n";

	SetClock_16MHz();
	uart_init();
	exti_13_init();

//	myqueue=xQueueCreate(5,sizeof(char *));

	RCC->AHB2ENR|=GPIOB_EN;
	GPIOB->MODER&=~(3U<<26);
	GPIOB->MODER|=(1U<<26);


	xTaskCreate(task1,"task1",1024,msg1,3,NULL);
	xTaskCreate(task2,"task2",1024,msg2,4,NULL);

	vTaskStartScheduler();
}
