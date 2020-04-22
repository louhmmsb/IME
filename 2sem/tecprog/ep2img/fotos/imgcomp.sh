#!/bin/bash
#Esse script faz com que as imagens com o nome do estilo qualquercoisao.xcf sejam convertidas para xpm, rodadas 15 graus até completarem uma volta e mude o tamanho delas para o tamaho desejado
for l in 1*.xcf
do
    convert -background none $l -scale 64x64 ${l/.xcf/.xpm}
done

for j in 2*.xcf
do
    convert -background none $j -scale 64x64 ${j/.xcf/o.xpm}
done

for k in 3*.xcf
do
    convert -background none $k -scale 64x64 ${k/.xcf/o.xpm}
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

mkdir imagens
mv *.xpm imagens
