CC= g++
FlAGS= -Werror -Wall -Wextra -Wunused -g

all: main.out

main.out: main.cpp ./bibs/nfa.cpp
	$(CC) $(FLAGS) -o $@ $^

tar: main.cpp ./bibs/*
	mkdir entrega
	cp -r bibs main.cpp Makefile README entrega
	tar -cvf entrega.tar entrega
	rm -rf entrega
