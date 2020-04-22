# Makefile para o SpaceWars

CC = gcc

CFLAGS= -Wall -ansi -pedantic -O4 -g

MAINDIR= main

PROJECTNAME = space_Wars

PROJECTBIN = spaceWars.bin

LSRCDIR =libSource/

LSOURCE := $(wildcard libSource/*.c)

LIBDIR=lib/

LIBS= -lvetores -lfisica -lentrada -lsimulacao -lutil -lX11 -lXpm -lstructs

INCLUDEDIR=include/

FOTOS=fotos/

EXTRA= -I$(INCLUDEDIR) -L$(LIBDIR) $(LIBS)

# Monta o programa principal

default:
	@echo "Procedimentos:"
	@echo "make bin: cria o executável do programa e prepara as imagens"
	@echo "make main: monta o programa e as bibliotecas"
	@echo "make library: cria as bibliotecas estáticas"
	@echo "make clean: remove arquivos temporários"
	@echo "make tar: cria arquivo.tar para ser compartilhado"
	@echo "make img: cria as imagens para desenhar"

# Para gerar o executável
.PHONY : bin
bin : main imagens

# Para montar o programa principal
.PHONY : main library objects archives
main : $(MAINDIR)/$(PROG) lib objects 	
#	$(CC) -o $(PROJECTBIN) main/main.c -Llib/ $(LIBS) -Iinclude/
	$(CC) -o $(PROJECTBIN) main/main.c lib/*.o -Iinclude/ -lm -lXpm -lX11

# Regra para montar as bibliotecas
library : objects archives

# Regra para montar os objetos
objects :
	cd $(LSRCDIR) && $(MAKE)
	mv $(LSRCDIR)*.o $(LIBDIR)

archives : objects
	cd $(LIBDIR) && $(MAKE)

# Regras adicionais

# Remover os arquivos temporários
.PHONY : clean
clean :
	rm -rf *~ *.o
	cd $(LIBDIR) && rm -rf *.o *.a

# Prepar o tar para envio 
.PHONY : tar
tar :
	mkdir $(PROJECTNAME)
	cd fotos/ && $(MAKE) clean
	cp -rt $(PROJECTNAME)/ $(LIBDIR) $(MAINDIR) $(LSRCDIR) $(INCLUDEDIR) $(FOTOS) Makefile README.txt testeOrbita.txt
	tar -cvf $(PROJECTNAME).tar $(PROJECTNAME)
	rm -rf $(PROJECTNAME)/
	@echo "\n.tar criado com sucesso!\n"

# Gerar as imagens .xmp
.PHONY : img
imagens :
	cd fotos/ && $(MAKE)
	@echo "Imagens criadas"
