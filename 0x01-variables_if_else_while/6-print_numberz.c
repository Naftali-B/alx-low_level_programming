#include <stdio.h>

/**
 * main - Prints out all the numbers
 * from 0 to 9, with putchar
 * Return: Always 0 (Success)
 */

int main(void)

{

	int l;



	/* Prints out all the digits from 0 */

	/* to 9 after initializing l to the */

	/* ASCII value of '0' */

	for (l = '0'; l <= '9'; l++)

		putchar(l);



	putchar ('\n');

	return (0);

}
