# FreeRTOS (v11.1) port for AVR 8bit microcontrollers

## Using

In an existing project, run the following command to install the component:

```text
cd ../your_project/lib
git clone http://git.zh.com.ru/avr_libraries/zh_avr_free_rtos
```

In the application, add the component:

```c
#include "FreeRTOS.h"
```

## Example

Led blink:

```c
#include "FreeRTOS.h"
#include "task.h"
#include "avr/io.h"

void led_flash_task(void *pvParameters)
{
    DDRB |= (1 << PORTB5);
    for (;;)
    {
        PORTB ^= (1 << PORTB5);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

int main(void)
{
    xTaskCreate(led_flash_task, "led flash task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL);
    vTaskStartScheduler();
    return 0;
}
```
