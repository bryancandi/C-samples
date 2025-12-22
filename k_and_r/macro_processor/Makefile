# Makefile for #define macro processor

# Compiler
CC ?= gcc   # use environment/compiler override if provided

# Compiler flags
CFLAGS ?= -Wall -Wextra -Wpedantic

# Source files
SRCS = main.c macro.c getword.c

# Output executable
TARGET = macro

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean up build artifacts
clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean
