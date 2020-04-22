1 - Leia uma matriz de tamanho arbitrário do arquivo matrix.txt.
Os números em uma mesma linha da matriz estão na mesma linha do arquivo,
separadas por um espaço.
Assuma que todas as linhas do arquivo tem a mesma quantidade de números.

2 - Crie uma lista ligada de tamanho arbitrário com todas as palavras
em um arquivo. A lista NÃO pode conter entradas repetidas:
se uma palavra ocorrer mais de uma vez, nada deve ser inserido na lista.

Sugestão: use a seguinte struct:

struct list {
	const char *palavra;
	struct list *next;
};

3 - Fizemos um visualizador que cria quadrados em posições aleatórias
e com uma certa velocidade (também aleatória) para a direita. Os quadrados
são colocados na inseridos na lista ligada rect_list, que pode ser acessada
incluindo o header graphic.h.
Infelizmente, o visualizador não dá free() em nada do que é alocado.
Sua tarefa é implementar a função destroy_unused_rects(), que deve dar
free() em cada rect_type_list cujo retângulo já tenha saído da tela.
