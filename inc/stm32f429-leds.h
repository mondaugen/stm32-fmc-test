#ifndef STM32F429-LEDS_H
#define STM32F429-LEDS_H 

/* Make leds do something every so often */
static inline void stmeval_leds_setup(void)
{
    GPIO_InitTypeDef GPIO_TIM_InitStruct;
    GPIO_TIM_InitStruct.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
    GPIO_TIM_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_TIM_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_TIM_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_TIM_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    GPIO_Init(GPIOG, &GPIO_TIM_InitStruct);

}

/* Do something with the leds */
static inline void stmeval_toggle_leds(void)
{
    GPIO_ToggleBits(GPIOG, GPIO_Pin_13 | GPIO_Pin_14);
}

static inline void stmeval_red_led_on(void)
{
    GPIO_SetBits(GPIOG, GPIO_Pin_14);
}

static inline void stmeval_green_led_on(void)
{
    GPIO_SetBits(GPIOG, GPIO_Pin_13);
}

static inline void stmeval_red_led_off(void)
{
    GPIO_ResetBits(GPIOG, GPIO_Pin_14);
}

static inline void stmeval_green_led_off(void)
{
    GPIO_ResetBits(GPIOG, GPIO_Pin_13);
}



#endif /* STM32F429-LEDS_H */
