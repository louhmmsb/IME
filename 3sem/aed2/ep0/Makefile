HEADERS= queue.h aviao.h
IMPLEM= main.cpp aviao.cpp
CFLAGS= -Wall -Wextra -Werror -g
CC=g++

main: $(HEADERS) $(IMPLEM)
	$(CC) $(CFLAGS) -o main $(IMPLEM)
tar:
	mkdir $(NUSP)
	echo $(NUSP) >> NUSP.txt
	echo $(EMAIL) >> EMAIL.txt
	cp -t $(NUSP)/ *.cpp *.h Makefile NUSP.txt EMAIL.txt Relatorio.pdf
	tar -cvf $(NUSP).tar $(NUSP)
	rm -rf $(NUSP)/
	rm *.txt

clean:
	rm *.o
