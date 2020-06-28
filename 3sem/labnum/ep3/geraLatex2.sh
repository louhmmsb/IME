#!/usr/bin/env bash

i=10

echo "\begin{center}"
echo "\begin{tabular}{||c | c | c | c | c ||}"
echo "\hline"
echo "Função & Número de V.A. & Menor Erro & Maior Erro & Erro Médio \\\\ [0.5ex]"
echo "\hline\hline"



while [ $i != $1 ]
do
    ./pt2.out $i $2 latex
    i=$(($i*10))
done

echo "\end{tabular}"
echo "\end{center}"
