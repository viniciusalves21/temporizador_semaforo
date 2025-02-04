#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 13
#define LED_PIN_BLUE 12
#define LED_PIN_GREEN 11

// Variáveis para controlar o estado dos LEDs e qual LED deve acender
bool led_on_red = false;
bool led_on_blue = false;
bool led_on_green = false;
int current_led = 0; // 0: vermelho, 1: verde, 2: azul

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {

// Desliga TODOS os LEDs *antes* de ligar o LED correto
    gpio_put(LED_PIN_RED, false);
    gpio_put(LED_PIN_GREEN, false);
    gpio_put(LED_PIN_BLUE, false);

    if (current_led == 0) {
        printf("led vermelho\n");
        gpio_put(LED_PIN_RED, true);
    } else if (current_led == 1) {
        printf("led azul (simulando amarelo)\n");
        gpio_put(LED_PIN_BLUE, true);
    } else {
        printf("led verde\n");
        gpio_put(LED_PIN_GREEN, true);
    }

    current_led = (current_led + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos GPIO
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, true);

    // Inicializa o temporizador
    struct repeating_timer timer;

    // Configura o temporizador para chamar o callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito
    while (true) {
        sleep_ms(10000);
        printf("Rotina de repetição\n");
    }

    return 0;
}