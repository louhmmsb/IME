#include <stdio.h>
int main(void)
{
	int a[256];

	a[0] = 1;
	printf("%d\n", a[0]);
	*a = 3;
	printf("%d\n", a[0]);
}
