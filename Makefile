# Makefile to compile and run the program #

# Compiler name
CC = gcc

# Flags
CFLAGS = -Wall -g

# Compile source files 
SRCS = main.c coding/coding.c file/write.c file/read.c decoding/decoding.c

# Create object files
OBJS = $(SRCS:.c=.o)

# Name of the executable file
TARGET = huffman

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Clean up object files and executable
clean:
	rm -f $(OBJS) 

# Clear the command line
clear:
	clear

# Run the executable file
run: $(TARGET)
	./$(TARGET)

# Default rule
all: $(TARGET) clean clear run #must write clear after clean

# This tells make that clean, run and clear are not files, but just commands that need to be run.
.PHONY: clean run clear

# set the default target that will be run
.DEFAULT_GOAL := all 