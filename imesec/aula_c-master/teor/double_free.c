int main(void)
{
	int *x = malloc(sizeof(int));

	free(x);
	free(x);
	return 0;
}
