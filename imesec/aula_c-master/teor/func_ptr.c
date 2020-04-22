#include <stdio.h>
int func(float x)
{
	return (int)x;
}

int main(void)
{
	int (*foo)(float);
	foo = func;

	int x = foo(1.2);
	printf("%d\n", x);

	return 0;
}
