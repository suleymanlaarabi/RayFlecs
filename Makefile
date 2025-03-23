CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -pipe -O0 -g
CFLAGS += -lraylib -lm -ldl -lpthread -lGL -lrt
SRC_DIR = src
LIB_DIR = lib
OBJ_DIR = obj
BIN = rayflecs

SRC =  $(shell find src -name '*.c')
LIB = $(LIB_DIR)/flecs.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o) $(LIB:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean run

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(OBJ_DIR) $(BIN)
