#include "uart.h"
#include "timer.h"
#include "interrupt.h"
#include "app_tasks.h"

#define GPIOB_EN	(1U<<1)

char *msg1="Hello\r\n";
char *msg2="Bye\r\n";

SemaphoreHandle_t led_sema;
QueueHandle_t myqueue;
uint8_t flag=0;
void EXTI15_10_IRQHandler(void);
int main()
{
	SetClock_16MHz();
	uart_init();
	exti_13();

	RCC->AHB2ENR|=GPIOB_EN;
	GPIOB->MODER&=~(3U<<26);
	GPIOB->MODER|=(1U<<26);


	myqueue=xQueueCreate(5,sizeof(char *));
	led_sema=xSemaphoreCreateBinary();


	xTaskCreate(task1,"Writing Task1",256,msg1,1,NULL);
	xTaskCreate(task2,"Receiving Task1",256,NULL,3,NULL);
	xTaskCreate(task1,"Writing Task2",256,msg2,2,NULL);
	xTaskCreate(led_task,"LED Task",256,NULL,4,NULL);
	xTaskCreate(task3,"Button notification",256,NULL,2,NULL);

	vTaskStartScheduler();
	while(1){}

}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR1 & (1U<<13))
	{
		EXTI->PR1|=(1U<<13);
		BaseType_t flag=pdFALSE;
		xSemaphoreGiveFromISR(led_sema,&flag);
		portYIELD_FROM_ISR(flag);

	}
}
