int main(void)
{
	int *x = malloc(10 * sizeof(int));

	for (int i = 0; i < 10; i++) {
		x[i] = 0;
	}

	free(x);

	x[0] = 1;

	return 0;
}
