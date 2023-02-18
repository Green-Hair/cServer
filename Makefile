CC=gcc
SRC=sqlite3/sqlite3.c cJSON/cJSON.c src/main.c
OBJ=obj/sqlite3.o obj/cJSON.o obj/main.o
DEL=del

build:bin/server.exe
	@echo Building Server...

bin/server.exe:$(OBJ)
	$(CC) $(OBJ) -o bin/server

obj/sqlite3.o:sqlite3/sqlite3.c
	$(CC) -c $< -o $@

obj/cJSON.o:cJSON/cJSON.c
	$(CC) -c $< -o $@

obj/main.o:src/main.c
	$(CC) -c $< -o $@

clean:
	$(DEL) $(OBJ)

.PHONY: build clean