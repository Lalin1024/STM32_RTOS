/*
 * app_tasks.h
 *
 *  Created on: Aug 16, 2026
 *      Author: lalin
 */

#ifndef APP_TASKS_H_
#define APP_TASKS_H_

#include "stm32l433xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

extern SemaphoreHandle_t uart_mutex;

void task1(void *para);
void task2(void *para);
//void task3(void *para);


#endif /* APP_TASKS_H_ */
