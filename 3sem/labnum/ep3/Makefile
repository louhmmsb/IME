CC= gcc
flags= -Wall -Wunused -Werror -Wextra -g

all : pt1.out pt2.out circ.out

pt1.out : pt1.c
	$(CC) $(flags) -o $@ pt1.c

pt2.out : pt2.c
	$(CC) $(flags) -o $@ pt2.c -lm

circ.out : circ.c
	$(CC) $(flags) -o $@ circ.c -lm

clean :
	rm relatorio.out relatorio.log relatorio.aux relatorio.toc
