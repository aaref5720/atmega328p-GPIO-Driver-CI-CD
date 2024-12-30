/*
 * gpio.h
 *
 * Created: 8/28/2024 11:41:28 AM
 *  Author: Abdelrahman Aref
 */ 


#ifndef GPIO_H
#define GPIO_H

#ifdef __AVR__
#include <avr/io.h>
#else
// Define dummy versions or provide alternate implementations if needed
typedef volatile unsigned char PORT_t;
#define PORTB (*(PORT_t *)0x25)  // Example, adjust according to your needs
#define PB0 0
#endif

void gpio_init(void);
void gpio_set_pin(volatile uint8_t *port, uint8_t pin);
void gpio_clear_pin(volatile uint8_t *port, uint8_t pin);

#endif // GPIO_H
