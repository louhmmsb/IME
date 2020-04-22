#include <stdio.h>
int main(void)
{
	int a[256];

	a[2] = 1;
	printf("%d\n", a[2]);
	*(a + 2) = 3;
	printf("%d\n", a[2]);
}
