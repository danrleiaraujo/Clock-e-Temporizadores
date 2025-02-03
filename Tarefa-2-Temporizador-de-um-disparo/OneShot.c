#include <stdio.h>
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas como GPIO.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

// Constantes - Pinos 
const uint LED_R = 11;
const uint LED_Y = 12;
const uint LED_G = 13;

const uint BUTTON = 5;

// Variaveis
volatile int led = 0; // Usado para saber qual led esta ligado
volatile bool led_R_ativado = 0; // Usado para saber qual led esta ligado
volatile bool led_Y_ativado = 0; // Usado para saber qual led esta ligado
volatile bool led_G_ativado = 0; // Usado para saber qual led esta ligado
volatile bool botao_pressionado = false;


// Funcoes:

// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data);

//função para indicar que botão está sendo apertado
void callback_botao(uint gpio, uint32_t events);

int main(){
    stdio_init_all();
    
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    //função para iqr
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &callback_botao);
    
    while (1) {
        printf("ONE SHOT FUNCIONANDO!\n\n");
        if (led_R_ativado){
            printf("Leds ligadas:\n");
            printf("Led Vermelho:\n");
            printf("Led Amarelo:\n");
            printf("Led Verde:\n\n");
        }
        else if(led_Y_ativado){
            printf("Leds ligadas:\n");
            printf("Led Amarelo:\n");
            printf("Led Verde:\n\n");
        }    
        else if(led_G_ativado){
            printf("Leds ligada:\n");
            printf("Led Verde:\n\n");
        }
        sleep_ms(1000);
    } // fim do while
} // fim do main


// Função de callback para desligar o LED após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    if (led_R_ativado){
        gpio_put(LED_R, 0);
        led_R_ativado = 0;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
    else if(led_Y_ativado){
        gpio_put(LED_Y, 0);
        led_Y_ativado = 0;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }    
    else if(led_G_ativado){
        gpio_put(LED_G, 0);
        led_G_ativado = 0;
        botao_pressionado = false;
    }
    return 0;
}

//função para indicar que botão está sendo apertado
void callback_botao(uint gpio, uint32_t events){
    if (gpio == BUTTON && !botao_pressionado) {
        gpio_put(LED_R, 1);
        gpio_put(LED_Y, 1);
        gpio_put(LED_G, 1);
        led_R_ativado = 1;
        led_Y_ativado = 1;
        led_G_ativado = 1;
        botao_pressionado = true;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}
