#include <stdio.h>

/**
 * main - Prints out all the numbers
 * between 0 and 99 with non-repeating
 * digits.
 * Return: Always 0 (Success)
 */



int main(void)

{

	int f, l;



	for (f = '0'; f <= '9'; f++)

		for (l = '0'; l <= '9'; l++)

			if (l > f)

			{

				putchar(f), putchar(l);

				if ((f != '8') || (l != '9'))

					putchar(','), putchar(' ');

			}



	putchar('\n');

	return (0);

}
