#include <stdio.h>
#include "driver/gpio.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define GPIO pin for onboard LED
#define LED_PIN GPIO_NUM_4  // The onboard LED is usually connected to GPIO 4 on ESP32-CAM

extern "C" void app_main(void)
{
    // Initialize the LED GPIO as an output pin
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Blink the LED every 5 seconds
    while (1) {
        gpio_set_level(LED_PIN, 1);  // Turn LED on
        printf("LED ON\n");  // Print to serial console (similar to std::cout)
        vTaskDelay(5000 / portTICK_PERIOD_MS);  // Wait for 5 seconds

        gpio_set_level(LED_PIN, 0);  // Turn LED off
        printf("LED OFF\n");  // Print to serial console (similar to std::cout)
        vTaskDelay(5000 / portTICK_PERIOD_MS);  // Wait for 5 seconds
    }
}