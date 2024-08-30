/*
 * gpio.c
 *
 * Created: 8/28/2024 11:41:28 AM
 *  Author: Abdelrahman Aref
 */ 

#include "gpio.h"

void gpio_init(void) {
	// Initialize GPIO ports; for example, set PORTB as output
	DDRB = 0xFF;  // Set all pins of PORTB as output
	PORTB = 0x00; // Set all pins of PORTB to low
}

void gpio_set_pin(volatile uint8_t *port, uint8_t pin) {
	*port |= (1 << pin)  // Set the specified pin high
}

void gpio_clear_pin(volatile uint8_t *port, uint8_t pin) {
	*port &= ~(1 << pin); // Set the specified pin low
}

