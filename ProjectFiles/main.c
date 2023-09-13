#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"

void led_task() {

    const uint LED_PIN = 0;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(1) {
        gpio_put(LED_PIN, 0);
        vTaskDelay(75);
        gpio_put(LED_PIN, 1);
        vTaskDelay(75);
    }
}

void led_task2() {
    
    const uint LED_PIN = 1;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(1) {
        gpio_put(LED_PIN, 0);
        vTaskDelay(10);
        gpio_put(LED_PIN, 1);
        vTaskDelay(10);
    }
}


int main() {
    stdio_init_all();

    // 256 = num of words allocated to the task stack
    // not passing args to the LED_Task function therefore NULL
    // task priority of 1
    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(led_task2, "LED_Task2", 256, NULL, 1, NULL);

    // start task scheduler
    vTaskStartScheduler();

    while(1) {};

}