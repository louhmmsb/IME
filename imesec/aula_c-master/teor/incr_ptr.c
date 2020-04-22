#include <stdio.h>
int main(void)
{
	const char *s = "abc";
	for(; *s != '\0'; s++) {
		printf("%c ", *s);
	}
	printf("\n");
	return 0;
}
