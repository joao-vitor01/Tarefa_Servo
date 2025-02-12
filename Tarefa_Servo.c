#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO 22  // Pino do servomotor
#define PWM_LED 12    // Pino do LED RGB (apenas um dos canais, pode expandir para os outros)

const uint16_t WRAP_PERIOD = 19999; // Período para 50Hz (20ms)
const float PWM_DIVISER = 125.0; // Divisor de clock ajustado

// Definição dos ciclos ativos para posições do servo (em microssegundos)
const uint16_t POS_180 = 2400;  // 2.400µs → Aproximadamente 180°
const uint16_t POS_90  = 1470;  // 1.470µs → Aproximadamente 90°
const uint16_t POS_0   = 500;   // 500µs → Aproximadamente 0°

void pwm_setup()
{
    // Configuração do PWM para o servo
    gpio_set_function(PWM_SERVO, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO);
    pwm_set_clkdiv(slice, PWM_DIVISER);
    pwm_set_wrap(slice, WRAP_PERIOD);
    pwm_set_enabled(slice, true);

    // Configuração do PWM para o LED RGB
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM);
    uint slice_led = pwm_gpio_to_slice_num(PWM_LED);
    pwm_set_clkdiv(slice_led, PWM_DIVISER);
    pwm_set_wrap(slice_led, WRAP_PERIOD);
    pwm_set_enabled(slice_led, true);
}

// Define o ciclo ativo do PWM para uma determinada posição do servo
void set_servo_position(uint16_t pulse_width)
{
    pwm_set_gpio_level(PWM_SERVO, pulse_width);
}

// Define o brilho do LED RGB (para efeito visual)
void set_led_brightness(uint16_t brightness)
{
    pwm_set_gpio_level(PWM_LED, brightness);
}

int main()
{
    stdio_init_all();
    pwm_setup();

    // Movimentação do servo para as posições fixas com espera de 5 segundos
    printf("Movendo para 180 graus...\n");
    set_servo_position(POS_180);
    set_led_brightness(6000);  // LED mais brilhante
    sleep_ms(5000);

    printf("Movendo para 90 graus...\n");
    set_servo_position(POS_90);
    set_led_brightness(3000);  // LED médio brilho
    sleep_ms(5000);

    printf("Movendo para 0 graus...\n");
    set_servo_position(POS_0);
    set_led_brightness(1000);  // LED mais fraco
    sleep_ms(5000);

    // Movimentação contínua suave entre 0° e 180°
    printf("Iniciando movimentação contínua do servo...\n");

    while (true)
    {
        // Movimento de 0° para 180°
        for (uint16_t pulse = POS_0; pulse <= POS_180; pulse += 5)
        {
            set_servo_position(pulse);
            sleep_ms(10);
        }

        // Movimento de 180° para 0°
        for (uint16_t pulse = POS_180; pulse >= POS_0; pulse -= 5)
        {
            set_servo_position(pulse);
            sleep_ms(10);
        }
    }
}
