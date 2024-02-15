SRC_DIR = src
OBJ_DIR = bin

CC = gcc
CFLAGS = -Wall
LIBS = -lcurl

e1: 
	$(CC) $(CFLAGS) $(SRC_DIR)/example1.c -o $(OBJ_DIR)/example1 $(LIBS)

e2:
	$(CC) $(CFLAGS) $(SRC_DIR)/example2.c -o $(OBJ_DIR)/example2 $(LIBS)

$(OBJ_DIR):
	mkdir -p bin

clean:
	rm -rf bin
