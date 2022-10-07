#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - program that multiplies two infinete length positive
 * numbers in base 10
 * @ac: size of @av
 * @av: arguments passed
 *
 * Return: 0 if succes, 98 if the number of arguments or their
 * composition is incorrect
 */

int main(int ac, char **av)

{
	int i1, i2, n1_len, n2_len, ip, ip2, plen = 0, *product, offset;
	const int Z = '0';

	validate_arg_count(ac);
	validate_strings_only_have_digits(av[1], av[2]);

	n1_len = _strlen(av[1]), n2_len = _strlen(av[2]);
	plen = n1_len + n2_len;

	product = malloc(sizeof(int) * (plen));
	if (product == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	for (ip = 0; ip < plen; ip++)
		product[ip] = 0;

	for (i2 = n2_len - 1, offset = 0; i2 >= 0; i2--, offset++)
	{
		for (i1 = n1_len - 1, ip = offset ; i1 >= 0; i1--, ip++)
		{
			product[ip] += (av[1][i1] - Z) * (av[2][i2] - Z);
			for (ip2 = ip; product[ip2] > 9; ip2++)
			{
				product[ip2 + 1] += product[ip2] / 10;
				product[ip2] %= 10;
			}
		}
	}
	while (product[ip] == 0)
		ip--;
	for (ip >= 0 ? (ip) : (ip = 0); ip >= 0; --ip)
		_putchar(product[ip] + Z);
	_putchar('\n');

	free(product);
	return (0);

}



/**

 * validate_arg_count - if the arg count is wrong program exit is handled

 * @count: arguments count

 */

void validate_arg_count(int count)

{

	if (count != 3)

	{

		printf("Error\n");

		exit(98);

	}

}
