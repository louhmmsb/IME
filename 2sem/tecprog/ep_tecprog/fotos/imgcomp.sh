#!/bin/bash
#Esse script faz com que as imagens com o nome do estilo qualquercoisao.xcf sejam convertidas para xpm, rodadas 15 graus até completarem uma volta e mude o tamanho delas para o tamaho desejado
rm -rf imagens
for l in 1*.xcf
do
    convert -background none $l -scale 128x128 ${l/.xcf/.xpm}
done

for j in 2*.xcf
do
    convert -background none $j -scale 32x32 ${j/.xcf/o.xpm}
done

for k in 3*.xcf
do
    convert -background none $k -scale 8x8 ${k/.xcf/o.xpm}
done

for i in $(ls *o.xpm)
do
    for counter in $(seq 0 23)
    do
	if [ $counter -lt 10 ]
	then
	    convert -background none -distort SRT $(( ($counter)*15 )) $i{o.xpm} ${i/o.xpm/0$counter.xpm}
	else
	    convert -background none -distort SRT $(( ($counter)*15 )) $i{o.xpm} ${i/o.xpm/$counter.xpm}
	fi
    done
    rm $i
done

convert -background none background.png -scale 500x500 background.xpm

mkdir imagens
mv *.xpm imagens
