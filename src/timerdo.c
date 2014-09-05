#include "timerdo.h" 
#include "stm32f4xx.h" 

/* Do stuff when timer interrupt happens */

/* Keep track of amount of time that has gone by */
static uint64_t timeElapsed;
static uint32_t ledTime;

static void timerdo_update_time(void)
{
    timeElapsed += 1;
}

/* Make leds do something every so often */
static void timerdo_setup_leds(void)
{
    GPIO_InitTypeDef GPIO_TIM_InitStruct;
    GPIO_TIM_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_2;
    GPIO_TIM_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_TIM_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_TIM_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_TIM_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    GPIO_Init(GPIOG, &GPIO_TIM_InitStruct);

    ledTime = LED_TIME_RESET_VAL; /* every 1000 ticks, do something with the leds */
}

/* Do something with the leds */
static void timerdo_led_do(void)
{
    GPIO_ToggleBits(GPIOG, GPIO_Pin_13 | GPIO_Pin_2);
}

void timerdo_setup(void)
{
    timeElapsed = 0;
    timerdo_setup_leds();
}

void timerdo_update_leds(void)
{
    
    if (--ledTime == 0) {
        timerdo_led_do();
        ledTime = LED_TIME_RESET_VAL;
    }
}

void timerdo_timerdo(void)
{
    timerdo_update_time();
    timerdo_update_leds();
}
