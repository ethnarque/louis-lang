CC = gcc
CFLAGS = -Wall -Wextra -g
# CFLAGS = -g
SRC_DIR = ./
OBJ_DIR = ./
SOURCES = $(wildcard $(SRC_DIR)*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
