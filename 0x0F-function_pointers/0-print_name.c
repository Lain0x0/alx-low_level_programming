#include "function_pointers.h"
#include <stdio.h>
/**
 *func_name - print name using pointer to function
 *@name: string to add
 *@f: pointer to function
 *Return: nothing
*/
void func_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}

