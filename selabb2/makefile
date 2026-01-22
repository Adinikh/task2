# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -std=c11

# Source files
SRC = main.c utils.c

# Header files
HDR = student.h utils.h

# Output executable
TARGET = student

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean executable
clean:
	rm -f $(TARGET)

# Rebuild everything
rebuild: clean all
