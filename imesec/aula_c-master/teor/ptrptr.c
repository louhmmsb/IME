#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int **a;

	a = malloc(10 * sizeof(int*));
	for (int i = 0; i < 10; i++)
		a[i] = malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j] = 5;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	free(a);

	return 0;
}
