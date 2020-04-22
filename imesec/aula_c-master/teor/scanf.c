#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d", &x);
	int *p;
	p = &x;
	scanf("%d", p);

	printf("%d\n", x);

	return 0;
}
