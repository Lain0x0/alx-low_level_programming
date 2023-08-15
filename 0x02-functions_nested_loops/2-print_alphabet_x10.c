/**
 * print_alphabet_x10 - Funtion that print alphabet lowercase 10 times
 *
 * Return: Always 0.
*/
void print_alphabet_x10(void)
{
	char ch;

	int i;

	i = 0;

while (i < 10)
{

ch = 'a';
while (ch <= 'z')

{
_putchar(ch);
ch++;
}

	putchar('\n');
i++;
}

}

