#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int a[10];

	int *p = malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		a[i] = i;
		p[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

	free(p);
	return 0;
}
