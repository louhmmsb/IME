CC= g++
flags= -Werror -Wall -Wextra -Wunused -g
headers= $(ls ./bibs/*.hpp)

all: main.out

main.out : main.cpp $(headers) ./bibs/util.cpp
	$(CC) $(flags) -o $@ main.cpp ./bibs/util.cpp

tar :
	mkdir $(NUSP)	
	cp -r bibs $(NUSP)
	cp Makefile $(NUSP)
	cp relatorio.pdf $(NUSP)
	cp main.cpp $(NUSP)
	echo $(EMAIL) > $(NUSP)/email.txt
	echo $(NUSP) > $(NUSP)/nusp.txt
	tar -cvf $(NUSP).tar $(NUSP)
	rm -rf $(NUSP)
