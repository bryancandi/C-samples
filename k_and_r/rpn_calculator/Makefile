CC = cc
CFLAGS = -Wall -Wextra		# Enable warnings
LDFLAGS =
OBJ = main.o stack.o getop.o
TARGET = rpn_calc

all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Compile rules
main.o: calc.h
stack.o: calc.h
getop.o: calc.h

# Clean up build artifacts
clean:
	rm -f $(OBJ)
