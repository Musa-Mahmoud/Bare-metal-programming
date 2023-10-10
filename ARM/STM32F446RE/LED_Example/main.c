/**
 * @file main.c
 * @author Musa Mahmoud
 * @brief Bare-metal programming example for STM32F446RE microcontroller
 * @version 1.0
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>

#include "RCC_interface.h"
#include "GPIO_interface.h"

#define LED_OFF			(0U)
#define LED_ON			(1U)

uint8_t UserLedState = LED_ON;

int main(void)
{
	/* Enable clock on GPIOA */
	RCC_AHB1EnableClock(RCC_AHB1_PERIPHERALTYPE_GPIOA);

	/* Configure PinA5 as: output, PushPull, NoPull, LowSpeed */
	GPIO_PinConfig_t LedPin =
	{
			.Port = PORTA,
			.PinNum = PIN5,
			.Mode = OUTPUT,
			.OutputType = PUSH_PULL,
			.Speed = LOW,
			.PullType = NOPULL
	};

	GPIO_u8PinInit(&LedPin);

	/* High on the pin to turn the user led on */
	GPIO_u8SetPinValue(PORTA, PIN5, UserLedState);

	UserLedState = LED_OFF;

	GPIO_u8SetPinValue(PORTA, PIN5, UserLedState);

	while (1);
}
