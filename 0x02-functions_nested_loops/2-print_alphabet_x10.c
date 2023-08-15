/**
 * print_alphabet_x10 - Funtion that print alphabet lowercase 10 times
 *
 * Return: Always 0.
*/
void print_alphabet_x10(void)
{
	int ten;


	for (ten = 1; ten <= 10; ten++)
	{
		char a;

		for (a = 'a'; a <= 'z'; a++)
		{
			putchar(a);
		}
		putchar(10);
	}
}



