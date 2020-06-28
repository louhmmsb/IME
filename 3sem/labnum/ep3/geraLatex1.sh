#!/usr/bin/env bash

i=10

echo "\begin{center}"
echo "\begin{tabular}{||c | c | c ||}"
echo "\hline"
echo "Partições & Trapezóide & Simpson \\\\ [0.5ex]"
echo "\hline\hline"



while [ $i != 1000000000 ]
do
    ./pt1.out $i latex
    echo "\hline"
    i=$(($i*10))
done

echo "\end{tabular}"
echo "\end{center}"
