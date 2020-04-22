#!/bin/bash

if [ $# -ne 3 ]
then
    echo "Para usar passe o número de .txt"
    exit
fi

echo "set xrange [-2:2]">printa.gnu
echo "set yrange [-2:2]">>printa.gnu
echo "set terminal png enhanced size $2,$3">>printa.gnu
echo "set output 'grafico.png'">>printa.gnu
echo "set style line 1 lc rgb 'orange' pt 0">>printa.gnu
echo "set style line 2 lc rgb 'green' pt 0">>printa.gnu
echo "set style line 3 lc rgb 'blue' pt 0">>printa.gnu
echo "set style line 4 lc rgb 'red' pt 0">>printa.gnu
echo "set style line 5 lc rgb 'violet' pt 0">>printa.gnu
echo "set style line 6 lc rgb 'pink' pt 0">>printa.gnu
echo "set style line 7 lc rgb 'purple' pt 0">>printa.gnu
echo "set style line 8 lc rgb 'yellow' pt 0">>printa.gnu
echo "set style line $1 lc rgb 'black' pt 0">>printa.gnu



echo -n "plot ">>printa.gnu

a=1;

for i in *.txt
do
    echo -n "'$i' with points ls $((a++)) notitle, ">>printa.gnu
done

echo >>printa.gnu

echo "unset output">>printa.gnu

gnuplot printa.gnu
rm printa.gnu
rm *.txt
