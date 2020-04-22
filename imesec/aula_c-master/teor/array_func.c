#include <stdio.h>
int foo(int x[])
{
	printf("%d\n", sizeof(x));
}

int main(void)
{
	int a[256];
	foo(a);
	return 0;
}
