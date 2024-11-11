#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "pico_servo.hpp"

int main()
{
    stdio_init_all();

    // For more examples of timer use see https://github.com/raspberrypi/pico-examples/tree/master/timer

    pwm_config pwm_config = pwm_get_default_config();
    pwm_config_set_clkdiv(&pwm_config, 50); // should be 2.5MHz
    printf("System Clock Frequency is %d Hz\n", clock_get_hz(clk_sys));
    printf("USB Clock Frequency is %d Hz\n", clock_get_hz(clk_usb));
    // For more examples of clocks use see https://github.com/raspberrypi/pico-examples/tree/master/clocks

    Servo sparkMax = Servo(10);
    sparkMax.servo_enable();
    int count = 0;
    while (true)
    {
        printf("Hello, world!\n");
        // 550 is full reverse on spark max
        // 910 is full neutral on a Spark
        // 1240 is full forward on a Spark
        sparkMax.percentOutput(-1);
        sleep_ms(20);
        count++;
    }
}