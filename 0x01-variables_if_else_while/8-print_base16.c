
#include <stdio.h>

/**
 * main - Prints out all the letters
 * from 0 - 9 and a - f.
 * Return: Always 0 (Success)
 */



int main(void)

{

	int l, u;



	for (l = 48; l <= 57; l++)

		putchar(l);



	for (u = 97; u <= 102; u++)

		putchar(u);



	putchar ('\n');

	return (0);

}


