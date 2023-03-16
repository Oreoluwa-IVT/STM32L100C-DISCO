#include "stm32l1xx.h"

#define LED_PIN GPIO_PIN_11
#define LED_PORT GPIOB

int main(void)
{
  // Enable the GPIOB clock
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
  
  // Configure PB11 as output
  LED_PORT->MODER |= GPIO_MODER_MODER11_0;
  
  // Set the LED to initially be off
  LED_PORT->ODR &= ~LED_PIN;
  
  while(1)
  {
    // Increase brightness gradually
    for(int i = 0; i <= 255; i++)
    {
      // Set the PWM duty cycle based on the brightness level
      TIM2->CCR2 = i;
      
      // Delay for a short time to observe the change in brightness
      for(int j = 0; j < 10000; j++);
    }
    
    // Decrease brightness gradually
    for(int i = 255; i >= 0; i--)
    {
      // Set the PWM duty cycle based on the brightness level
      TIM2->CCR2 = i;
      
      // Delay for a short time to observe the change in brightness
      for(int j = 0; j < 10000; j++);
    }
  }
}
