#!/usr/bin/env bash

arquivos=$(ls $1)

echo "\noindent\mytitle{k=$2}"

echo "\begin{center}"
echo "\begin{tabular}{||c | c | c | c | c | c | c | c | c||}"
echo "\hline"
echo "Livro & Vertices & Arestas & Componentes & Maior Comp. & Menor Comp. & Média Comp. & Dist. Média & Denso \\\\ [0.5ex]"
echo "\hline\hline"

for i in $arquivos
do
    echo -n $i" & "
    ./main.out $2 $1$i latex
    echo "\hline"
done

echo "\end{tabular}"
echo "\end{center}"

