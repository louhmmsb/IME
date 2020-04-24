#!/bin/bash

echo "1000x1000
-2
2
2
-2
0" | ./newton.out

mv grafico.png grafico0.png

echo "1000x1000
-2
2
2
-2
1" | ./newton.out

mv grafico.png grafico1.png

echo "1000x1000
-2
2
2
-2
2" | ./newton.out

mv grafico.png grafico2.png

echo "1000x1000
-2
2
2
-2
3" | ./newton.out

mv grafico.png grafico3.png

echo "1000x1000
-2
2
2
-2
4" | ./newton.out

mv grafico.png grafico4.png

echo "1000x1000
-2
1
0
-1
5" | ./newton.out

mv grafico.png grafico5.png

echo "1000x1000
-2
1
0
-1
4" | ./newton.out

mv grafico.png grafico6.png







