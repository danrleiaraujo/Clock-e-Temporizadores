#include <stdio.h>
#include "pico/stdlib.h"


const uint LED_R = 11;
const uint LED_Y = 12;
const uint LED_G = 13;



int main(){
    stdio_init_all();
    
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    gpio_init(LED_Y);
    gpio_set_dir(LED_Y, GPIO_OUT);

    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

    while (1) {
        printf("Semáfaro funcionando...\n");

    } // fim do while
} // fim do main

/*

    gpio_put(LED_R, 1);
    sleep_ms(1000);  // Espera 1 segundo
    gpio_put(LED_R, 0);
    sleep_ms(1000);  // Espera 1 segundo


    gpio_put(LED_Y, 1);
    sleep_ms(1000);  // Espera 1 segundo
    gpio_put(LED_Y, 0);
    sleep_ms(1000);  // Espera 1 segundo

    gpio_put(LED_G, 1);
    sleep_ms(1000);  // Espera 1 segundo
    gpio_put(LED_G, 0);
    sleep_ms(1000);  // Espera 1 segundo



*/