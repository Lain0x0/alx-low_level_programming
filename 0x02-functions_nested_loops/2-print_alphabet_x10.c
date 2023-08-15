/**
 * print_alphabet_x10 - Funtion that print alphabet lowercase 10 times
 *
 *_putchar - prototype for the function to be called
 *
 *
 * Return: Always 0.
*
*/
void print_alphabet_x10(void)
{
	int line, ch;

	for (line = 0; line <= 9; line++)
	{
	for (ch = 'a'; ch <= 'z'; ch++)
		_putchar(ch);
_putchar('\n');

	}


}
