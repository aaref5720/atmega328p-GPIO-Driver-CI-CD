# Define MCU and toolchain
MCU = atmega328p
AVR_CC = avr-gcc
AVR_AR = avr-ar
CFLAGS = -mmcu=$(MCU) -Wall -Os -Isrc -Iunity/src
OBJ_DIR = obj
SRC_DIR = .
UNITY_DIR = unity/src
LIBRARY = libUnity
TEST_EXEC = test_runner

# Source and object files
SRC = gpio.c test_gpio.c
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
UNITY_OBJ = $(OBJ_DIR)/unity.o
TEST_OBJ = $(OBJ_DIR)/test_gpio.o

# Default target
all: gpio_driver.elf

# Build the main application
gpio_driver.elf: $(OBJ) $(UNITY_OBJ)
	$(AVR_CC) $(CFLAGS) -o $@ $^

# Compile source files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(AVR_CC) $(CFLAGS) -c -o $@ $<

# Compile Unity
$(OBJ_DIR)/unity.o: $(UNITY_DIR)/unity.c
	@mkdir -p $(OBJ_DIR)
	$(AVR_CC) $(CFLAGS) -c -o $@ $<

# Create the Unity library
$(OBJ_DIR)/$(LIBRARY).a: $(OBJ_DIR)/unity.o
	@mkdir -p $(OBJ_DIR)
	ar rcs $@ $(OBJ_DIR)/unity.o

# Build the test executable
test: $(OBJ) $(OBJ_DIR)/$(LIBRARY).a
	$(AVR_CC) $(CFLAGS) -o $(TEST_EXEC) $(OBJ) $(OBJ_DIR)/$(LIBRARY).a

# Clean up
clean:
	rm -f $(OBJ_DIR)/*.o gpio_driver.elf $(TEST_EXEC) $(OBJ_DIR)/$(LIBRARY).a

.PHONY: all clean test
