FLAGS= -Wall -g -Werror -Wunused -O1
CC=g++
h= LL.h V.h BST.h TREAP.h BRT.h A23.h HASH.h

all : ep1

ep1 : main.cpp $(h)
	$(CC) $(FLAGS) -o main.out main.cpp

tar : $(h) main.cpp Makefile relatorio.pdf
	mkdir $(NUSP)
	echo $(NUSP) >> info.txt
	echo $(EMAIL) >> info.txt
	cp -t $(NUSP)/ info.txt

	tar -cvf $(NUSP).tar $(NUSP)/
