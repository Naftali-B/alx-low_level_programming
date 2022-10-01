#include <stdio.h>
#include <stdlib.h>

/**
 * main -  a program that prints the minimum number of coins to
 * make change for an amount of money.
 * @argc: size of @argv
 * @argv: ought to contain the name of the program and exactly one more
 * argument;
 * Return: 1 if the amount s of arguments passed is not exactly 1,
 * 0 if succesful execution
 */

int main(int argc, char **argv)

{
	int cents;
	int coins = 0;
	int cv[5] = {25, 10, 5, 2, 1};   /*coins: values*/
	int i;

	if (argc !=  2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents > 0)
	{
		for (i = 0; i < 5; i++)
		{
			coins += cents / cv[i];
			cents -= (cents / cv[i]) * cv[i];
		}
	}

	printf("%d\n", coins);
	return (0);
}
