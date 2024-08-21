NAME = test

CC = clang
OPT = -Og
VERSION = -std=c89
OUTPUT = a.out

FLAGS = -g  -Wall -Wextra -Werror -pedantic -pedantic-errors -Wpedantic
WARNINGS =
HEADERS =
LIBS = $(shell find ../libs -name "*.a")

INPUT = $(shell find ../src -name "*.c") $(NAME).c

all: default

default:
	$(CC) $(OPT) $(VERSION) $(HEADERS) $(FLAGS) $(WARNINGS) $(LIBS) -o $(OUTPUT) $(INPUT)
	./$(OUTPUT)

clean:
	cd .. && em clean && cd examples
	$(RM) -r $(OUTPUT) ./*.dSYM
