#include <stdio.h>
#include <math.h>

/**
 * main - contains all functions to
 * print out the largest prime factor.
 * Return: Always 0.
 */



int main(void)

{

	int div;

	long int store;



	div = 3;

	store = 612852475143;



	while (div <= store && div >= 3)

	{

		if (store % div == 0)

		{

			store = store / div;

		}



		else

		{

			div = div + 2;

		}

	}

	printf("%d", div);

	printf("\n");

	return (0);

}
