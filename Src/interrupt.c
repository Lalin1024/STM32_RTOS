/*
 * interrupt.c
 *
 *  Created on: Aug 25, 2026
 *      Author: lalin
 */


#include "interrupt.h"

#define GPIOC_EN	(1U<<2)
#define SYSCFGEN	(1U<<0)

void exti_13()
{
	__disable_irq();

	RCC->AHB2ENR|=GPIOC_EN;
	RCC->APB2ENR|=SYSCFGEN;

	GPIOC->MODER&=~(3U<<26);

	GPIOC->PUPDR&=~(3U<<26);
	GPIOC->PUPDR|=(1U<<27);

	SYSCFG->EXTICR[3]|=(1U<<5);

	EXTI->IMR1|=(1U<<13);

	EXTI->RTSR1|=(1U<<13);

	NVIC_EnableIRQ(EXTI15_10_IRQn);

	__enable_irq();
}
