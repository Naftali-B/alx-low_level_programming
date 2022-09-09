#include <stdio.h>

/**
 * main - Prints all the alphabets
 * from a to z backwards.
 * Return: Always 0 (Success)
 */

int main(void)

{

	int c;



	/* Initialize and store the ASCII value */

	/* of 'z' into C and decrement, printing */

	/* all the alphabets from a to z, backwards */

	for (c = 'z'; c >= 'a'; c--)

		putchar(c);



	putchar ('\n');

	return (0);

}
