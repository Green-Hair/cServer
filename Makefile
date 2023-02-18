CC=gcc
SRC=$(wildcard ./src/*.c)
OBJ=$(subst src,obj,$(patsubst %.c, %.o, $(SRC)))
INC=inc

build:bin/server.exe
	@echo Building Server...

bin/server.exe:$(OBJ) obj/main.o
	$(CC) $(OBJ) obj/main.o -o bin/server.exe

obj/cJSON.o:src/cJSON.c
	$(CC) -c $< -o $@ -Iinc

obj/sqlite3.o:src/sqlite3.c
	$(CC) -c $< -o $@ -Iinc

obj/main.o:project/main.c
	$(CC) -c $< -o $@ -Iinc

clean:
	@del obj\*.o
	@del bin\server.exe

.PHONY: build clean