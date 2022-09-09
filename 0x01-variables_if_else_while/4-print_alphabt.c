#include <stdio.h>

/**
 * main - Prints out all the letters in
 * the alphabet in order, excluding letter,
 * e and q.
 * Return: Always 0 (Success)
 */

int main(void)

{

	int l;



	/* Initializes l to the ASCII value of 'a' */

	/* Prints out all the letters up until 'z' */

	for (l = 'a'; l <= 'z'; l++)

		if (l != 'e' && l != 'q') 	/* if e/q, skip */

			continue;

		putchar(l); /* Else, continue printing */



	putchar ('\n');

	return (0);

}
