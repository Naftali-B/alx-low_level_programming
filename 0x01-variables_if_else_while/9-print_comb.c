#include <stdio.h>

/**
 * main - Prints out all the values
 * 0-9 along with spaces and commas
 * acting as seperators.
 * Return: Always 0 (Success)
 */

int main(void)

{

	int l;



	for (l = '0'; l <= '9'; l++)

		putchar(l);

		if (l < 57)

		{

			/* putchar(44); Space | putchar(32); Comma */

			putchar(' '), putchar(',');

		}



	putchar ('\n');

	return (0);

}
