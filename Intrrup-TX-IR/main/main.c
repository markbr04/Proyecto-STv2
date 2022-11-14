#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define INPUT_PIN 18
#define LED_PIN 26

int state = 0;
xQueueHandle interputQueue;
esp_err_t init_led(void);
esp_err_t init_isr(void);

esp_err_t init_led()
{
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    return ESP_OK;
}

static void IRAM_ATTR gpio_interrupt_handler(void *args)
{
    int pinNumber = (int)args;
    xQueueSendFromISR(interputQueue, &pinNumber, NULL);
}

esp_err_t init_isr(void)
{
    gpio_config_t pGPIOConfig;
    pGPIOConfig.pin_bit_mask = (1ULL << INPUT_PIN);
    pGPIOConfig.mode = GPIO_MODE_DEF_INPUT;
    pGPIOConfig.pull_up_en = GPIO_PULLUP_DISABLE;
    pGPIOConfig.pull_down_en = GPIO_PULLDOWN_ENABLE;
    pGPIOConfig.intr_type = GPIO_INTR_POSEDGE;

    gpio_config(&pGPIOConfig);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(INPUT_PIN, gpio_interrupt_handler, (void *)INPUT_PIN);

    return ESP_OK;
}


void Control_Accionamiento(void *params)
{
    int pinNumber, count = 1;
    while (true)
    {
        if (xQueueReceive(interputQueue, &pinNumber, portMAX_DELAY))
        {
            if (gpio_get_level(INPUT_PIN)==1)
            {
                printf("Gatillo Accionado %d veces.\n", count++);
            }
            
            gpio_set_level(LED_PIN, gpio_get_level(INPUT_PIN));
        
        }
            

    }
}

void app_main()
{

    init_led();
    init_isr();

    interputQueue = xQueueCreate(10, sizeof(int));
    xTaskCreate(Control_Accionamiento, "LED_Control_Task", 2048, NULL, 1, NULL);
    gpio_isr_handler_add(INPUT_PIN, gpio_interrupt_handler, (void *)INPUT_PIN);
}