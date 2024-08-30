/*
 * GccApplication1.c
 *
 * Created: 8/28/2024 11:40:59 AM
 * Author : Abdelrahman Aref
 */ 

#include "unity.h"
#include "gpio.h"

void test_gpio_set_pin(void);
void test_gpio_clear_pin(void);

// Define setUp and tearDown if you need them
void setUp(void) {
	// Initialization code here
	gpio_init(); // Initialize GPIO for tests
}

void tearDown(void) {
	// Cleanup code here
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_gpio_set_pin);
	RUN_TEST(test_gpio_clear_pin);
	return UNITY_END();
}

void test_gpio_set_pin(void) {
	gpio_init();
	
	volatile uint8_t *port = &PORTB;
	uint8_t pin = PB0;
	
	gpio_clear_pin(port, pin); // Ensure pin is low initially
	gpio_set_pin(port, pin);   // Set the pin high
	
	TEST_ASSERT_EQUAL(0x01, *port);  // Check if the pin is set high
}

void test_gpio_clear_pin(void) {
	gpio_init();
	
	volatile uint8_t *port = &PORTB;
	uint8_t pin = PB0;
	
	gpio_set_pin(port, pin); // Ensure pin is high initially
	gpio_clear_pin(port, pin); // Clear the pin
	
	TEST_ASSERT_EQUAL(0x00, *port);  // Check if the pin is cleared
}

