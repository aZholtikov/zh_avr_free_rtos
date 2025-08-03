/*
 * FreeRTOS Kernel V11.1.0
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html.
 *----------------------------------------------------------*/

#define configUSE_PREEMPTION                                            1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION                         0
#define configUSE_TICKLESS_IDLE                                         0
#define configCPU_CLOCK_HZ                                              F_CPU
#define configTICK_RATE_HZ                                              1000
#define configMAX_PRIORITIES                                            4
#define configMINIMAL_STACK_SIZE                                        64
#define configMAX_TASK_NAME_LEN                                         16
#define configUSE_16_BIT_TICKS                                          1
#define configIDLE_SHOULD_YIELD                                         1
#define configUSE_TASK_NOTIFICATIONS                                    1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES                           3
#define configUSE_MUTEXES                                               1
#define configUSE_RECURSIVE_MUTEXES                                     1 
#define configUSE_COUNTING_SEMAPHORES                                   1
#define configQUEUE_REGISTRY_SIZE                                       0
#define configUSE_QUEUE_SETS                                            0
#define configUSE_TIME_SLICING                                          1
#define configUSE_NEWLIB_REENTRANT                                      0
#define configENABLE_BACKWARD_COMPATIBILITY                             1
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS                         5
#define configUSE_MINI_LIST_ITEM                                        1
#define configSTACK_DEPTH_TYPE                                          uint16_t
#define configMESSAGE_BUFFER_LENGTH_TYPE                                size_t
#define configHEAP_CLEAR_MEMORY_ON_FREE                                 1

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION                                 0
#define configSUPPORT_DYNAMIC_ALLOCATION                                1
#define configTOTAL_HEAP_SIZE                                           762
#define configAPPLICATION_ALLOCATED_HEAP                                0
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP                       0

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                                             0
#define configUSE_TICK_HOOK                                             0
#define configCHECK_FOR_STACK_OVERFLOW                                  0
#define configUSE_MALLOC_FAILED_HOOK                                    0
#define configUSE_DAEMON_TASK_STARTUP_HOOK                              0
#define configUSE_SB_COMPLETED_CALLBACK                                 0

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS                                   0
#define configUSE_TRACE_FACILITY                                        0
#define configUSE_STATS_FORMATTING_FUNCTIONS                            0

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                                           0
#define configMAX_CO_ROUTINE_PRIORITIES                                 1

/* Software timer related definitions. */
#define configUSE_TIMERS                                                1
#define configTIMER_TASK_PRIORITY                                       configMAX_PRIORITIES - 1
#define configTIMER_QUEUE_LENGTH                                        10
#define configTIMER_TASK_STACK_DEPTH                                    configMINIMAL_STACK_SIZE

/* Set the following INCLUDE_* constants to 1 to incldue the named API function,
 * or 0 to exclude the named API function.  Most linkers will remove unused
 * functions even when the constant is 1. */
#define INCLUDE_vTaskPrioritySet                                        1
#define INCLUDE_uxTaskPriorityGet                                       1
#define INCLUDE_vTaskDelete                                             1
#define INCLUDE_vTaskSuspend                                            1
#define INCLUDE_xTaskResumeFromISR                                      1
#define INCLUDE_xTaskDelayUntil                                         1
#define INCLUDE_vTaskDelay                                              1
#define INCLUDE_xTaskGetSchedulerState                                  1
#define INCLUDE_xTaskGetCurrentTaskHandle                               1
#define INCLUDE_uxTaskGetStackHighWaterMark                             1
#define INCLUDE_xTaskGetIdleTaskHandle                                  1
#define INCLUDE_eTaskGetState                                           1
#define INCLUDE_xEventGroupSetBitFromISR                                1
#define INCLUDE_xTimerPendFunctionCall                                  1
#define INCLUDE_xTaskAbortDelay                                         1
#define INCLUDE_xTaskGetHandle                                          1

#define configMAX(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define configMIN(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

/**
 * configASSERT macro: https://www.freertos.org/a00110.html#configASSERT
 */
#ifndef configASSERT
    #define configDEFAULT_ASSERT 0
#else
    /**
     * Enable configASSERT macro if it is defined.
     */
    #ifndef configDEFAULT_ASSERT
        #define configDEFAULT_ASSERT 1
    #endif

    /**
     * Define a hook method for configASSERT macro if configASSERT is enabled.
     */
    #if configDEFAULT_ASSERT == 1
        extern void vApplicationAssertHook();
        #define configASSERT( x ) if (( x ) == 0) { vApplicationAssertHook(); }
    #endif
#endif


#endif /* FREERTOS_CONFIG_H */