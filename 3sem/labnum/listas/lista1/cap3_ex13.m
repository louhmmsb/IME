#!/usr/bin/octave

#implementacao da funcao exemplo do ex 13 do capitulo 3, para trocar a funcao basta alterar as funcoes f e df

disp("Running...");

function result = newton(f, df, x, tol)
  result = {0, true};
  while abs(feval(f, x)) > tol
    xnext = x - feval(f, x)/feval(df, x);
    if abs(xnext) >= 0.5*abs(x);
      result{2} = false;
      break;
    endif
    x = xnext;
  end
  result{1} = x;
endfunction

function result = f_roots(f, df, a, b, tol)
  result = {};
  if feval(f, a) > feval(f, b)
    maior = a;
    menor = b;
  else
    maior = b;
    menor = a;
  endif
  nraizes = 0;
  inc = 0.01;
  r = {0, false};
  while r{2} == false
    r = newton(f, df, (maior+menor)/2, tol);
    if r{2} == true
      result{++nraizes} = r{1};
    else
      for i = 1:3
	if feval(f, (maior+menor)/2) > 0
	  maior = (maior+menor)/2;
	else
	  menor = (maior+menor)/2;
	endif
      endfor
    endif
  end
endfunction

function result = main(f, df, a, b, tol, nprobes)
  result = {};
  nraizes = 0;
  inc = (abs(a)+abs(b))/nprobes;
  for x = a+inc:inc:b
    if (feval(f, x) >= 0 && feval(f, x-inc) <= 0 || feval(f, x-inc) >= 0 && feval(f, x) <= 0)
      printf("Entrando no intervalo [%f;%f]\n", x-inc, x);
      r = f_roots(f, df, x-inc, x, tol);
      r{1}
      for i = 1:length(r)
	result{++nraizes} = r{i};
      endfor
    endif
  endfor
endfunction

function y = f(x)
  y = 2*cosh(x/4) - x;
endfunction

function y = df(x)
  y = (sinh(x/4)/2) - 1;
endfunction


x = main(@f, @df, 0, 10, 1e-8, 10);

for i = 1:length(x)
  printf("Raiz %d: %.8f\n", i, x{i});
endfor

