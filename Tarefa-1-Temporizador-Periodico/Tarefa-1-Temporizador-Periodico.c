#include <stdio.h>
#include "pico/stdlib.h" // Inclui a biblioteca padrão para funcionalidades básicas como GPIO.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

// Constantes - Pinos das Leds
const uint LED_R = 11;
const uint LED_Y = 12;
const uint LED_G = 13;

// Variaveis
volatile int led = 0; // Usado para saber qual led esta ligado

// Funcoes
bool acionaLed (struct repeating_timer *t); // Funcao para acionar os LEDs

int main(){
    stdio_init_all();
    
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    gpio_put(LED_R, 1);
    led ++;
    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos.
    add_repeating_timer_ms(3000, acionaLed, NULL, &timer);
    
    while (1) {
        printf("O semaforo está funcionando!\n");
        printf("Led ligada: %d\n", led);
        sleep_ms(1000);
    } // fim do while
} // fim do main


bool acionaLed(struct repeating_timer *t) {
    if(led == 0){ // Desliga o led verde caso esteja ligado e Aciona o vermelho;
        if(gpio_get(LED_G))
            gpio_put(LED_G, 0);
        gpio_put(LED_R, 1);
        led ++;
    }
    else if (led == 1){ // Desliga o led vermelho caso esteja ligado e Aciona o Amarelo;
        if(gpio_get(LED_R))
            gpio_put(LED_R, 0);
        gpio_put(LED_Y, 1);
        led ++;
    }
    else if (led == 2){ // Desliga o led Amarelo caso esteja ligado e Aciona o verde;
        if(gpio_get(LED_Y))
            gpio_put(LED_Y, 0);
        gpio_put(LED_G, 1);
        led = 0;
    }
    else{ // Caso de algum valor fora do esperado, desliga as leds.
        gpio_put(LED_R, 0);
        gpio_put(LED_Y, 0);
        gpio_put(LED_G, 0);
    }
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}