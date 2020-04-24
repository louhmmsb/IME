IMPLEM= main.cpp
CFLAGS= -Wall -Wextra -Werror -g
CC=gcc

all : fixed.out newton.out

fixed.out : fixed.c
	$(CC) $(CFLAGS) -o $@ $< -lm

newton.out : newton.c
	$(CC) $(CFLAGS) -o $@ $< -lm

tar:
	mkdir $(NUSP)
	echo $(NUSP) >> NUSP.txt
	echo $(EMAIL) >> EMAIL.txt
	cp -t $(NUSP)/ *.c *.png *.sh README Makefile NUSP.txt EMAIL.txt relatorio.pdf
	tar -cvf $(NUSP).tar $(NUSP)
	rm -rf $(NUSP)/
	rm *.txt

clean:
	rm *.o
