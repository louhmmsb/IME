#define SIZE 100000
struct foo {
	int x[SIZE];
}

struct foo func(void)
{
	struct foo f;
	for (int i = 0; i < SIZE; i++) {
		f.x[0] = 0;
	}
	return f;
}

int main(void)
{
	struct foo f1 = func();
	return 0;
}
