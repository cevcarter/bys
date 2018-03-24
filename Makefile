CC = g++
SRC = main.cpp
OUT = test

all: test

test: $(SRC)
	$(CC) -g -o $(OUT) main.cpp

clean: 
	rm -f $(OUT)
