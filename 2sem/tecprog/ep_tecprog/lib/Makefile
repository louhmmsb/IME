# Makefile para montar as bibliotecas estáticas

SRC := $(wildcard *.o)
TRG := $(SRC:%.o=lib%.a)

all : $(TRG)

$(TRG) : $(SRC)
	@echo $(SRC)	
	ar -crv  $@ $< 

