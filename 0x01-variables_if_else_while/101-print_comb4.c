#include <stdio.h>

/**
 *main - prints unique  possible combinations of 3 digits in which 012, 120,
 * 102, 021, 201, 210 are considered the same combination
 *Return: alway 0
 */

int main(void)

{

	int d1, d2, d3;



	for (d1 = 0; d1 < 10; d1++)

	{

		for (d2 = d1 + 1; d2 < 10; d2++)

		{

			for (d3 = d2 + 1; d3 < 10; d3++)

			{

				putchar(d1 + '0');

				putchar(d2 + '0');

				putchar(d3 + '0');



				if ((d1 * 100 + d2 * 10 + d3) < 789)

				{

					putchar(',');

					putchar(' ');



				}

			}

		}

	}

	putchar('\n');



	return (0);

}
