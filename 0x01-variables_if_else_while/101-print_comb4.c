#include <stdio.h>

/**
 * main - Prints out all the numbers
 * between 0 - 1000 with non repeating
 * digits.
 * Return: Always 0 (Success)
 */

int main(void)

{

	int f, m, l;



	for (f = '0'; f <= '9'; f++)

		for (m = '0'; m <= '9'; m++)

			for (l = '0'; l <= '9'; l++)

			{

				if ((f < m) && (m < l))

					putchar(f), putchar(m), putchar(l);

				if (f != 55 || m != 56 || l != 57)

					putchar(','), putchar(' ');

			}



	putchar('\n');

	return (0);

}
