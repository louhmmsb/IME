/* 5 */
struct foo {
	int x;
	int y;
};

struct foo * func(int x, int y)
{
	struct foo f = {2 * x, 2 * y};
	return &f;
}
