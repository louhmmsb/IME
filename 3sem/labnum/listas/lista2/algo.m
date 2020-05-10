#!/usr/bin/octave

disp("Running");

function result = derivatives(der1, y, x, n)
  result(1) = der1;
  for i = 1:n
    result(i+1) = -result(i) + 2*((y(i+1)-y(i))/(x(i+1)-x(i)));
  endfor
endfunction

function main()
  n = 10; #numero de divisoes do intervalo
  der1 = 1; #derivada no começo do intervalo
  x = []; #lista de coordenadas xi
  y = []; #lista de coordenadas yi
  z = derivatives(der1, y, x, n);
  
  for i = 1:n
    Qi = @(q) (q-x(i))*(q-x(i))*(z(i+1)-z(i))/(2*x(i+1)-x(i))+z(i)*(q-x(i))+y(i);
    fplot(Qi, [x(i), x(i+1)]);
    hold on;
  endfor
  plot();
endfunction

main();
