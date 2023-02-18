CC=gcc
SRC=sqlite3/sqlite3.c cJSON/cJSON.c src/main.c
OBJ=sqlite3/sqlite3.o cJSON/cJSON.o src/main.o
DEL=del

build:bin/server.exe
	@echo Building Server...

bin/server.exe:$(OBJ)
	$(CC) $(OBJ) -o bin/server

sqlite3/sqlite3.o:sqlite3/sqlite3.c
	$(CC) -c $<

cJSON/cJSON.o:cJSON/cJSON.c
	$(CC) -c $<

clean:
	$(DEL) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $<

.PHONY: build clean