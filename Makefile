SRC_DIR = src
OBJ_DIR = bin

CC = gcc
CFLAGS = -Wall
LIBS = -lcurl

$(OBJ_DIR)/%: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(OBJ_DIR):
	mkdir -p bin

clean:
	rm -rf bin
