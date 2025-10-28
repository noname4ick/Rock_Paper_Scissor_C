CC = gcc 
CFLAGS = -Wall -Wextra -Werror 

BUILD_DIR = build
SRC_DIR = src

all: 
	$(CC) -o $(BUILD_DIR)/game $(SRC_DIR)/rock_paper_scissor.c $(CFLAGS)

clean: 
	rm $(BUILD_DIR)/game

.PHONY: clean all