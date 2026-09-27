/*
 * FreeRTOSConfig.h
 *
 *  Created on: Feb 13, 2026
 *      Author: LalinPrasadC
 */

#ifndef FREERTOSCONFIG_H_
#define FREERTOSCONFIG_H_

#define configCPU_CLOCK_HZ       (16000000UL)
#define configTICK_RATE_HZ       (1000)
#define configMAX_PRIORITIES     (5)
#define configMINIMAL_STACK_SIZE (128)
#define configTOTAL_HEAP_SIZE    (10 * 1024)

#define configUSE_PREEMPTION     1
#define configUSE_IDLE_HOOK      0
#define configUSE_TICK_HOOK      0

#define configPRIO_BITS          4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY  15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

#define configTICK_TYPE_WIDTH_IN_BITS    TICK_TYPE_WIDTH_32_BITS

#define configKERNEL_INTERRUPT_PRIORITY \
( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#define INCLUDE_vTaskDelay 1
#define INCLUDE_vTaskDelayUntil     1
#define INCLUDE_uxTaskPriorityGet   1

#define INCLUDE_uxTaskGetStackHighWaterMark 1

#define vPortSVCHandler      SVC_Handler
#define xPortPendSVHandler   PendSV_Handler
#define xPortSysTickHandler  SysTick_Handler

#define configUSE_TASK_NOTIFICATIONS 1

#define configUSE_MUTEXES	1

#endif /* FREERTOSCONFIG_H_ */
