/**
 * print_alphabet_x10 - Funtion that print alphabet lowercase 10 times
 *
 * Return: Always 0.
*/
void print_alphabet_x10(void)
{
	char al;

	int i;

	i = 0;

while (i < 10)
{

al = 'a';
while (al <= 'z')

{
_putchar(al);
al++;
}

	putchar('\n');
i++;
}

}

