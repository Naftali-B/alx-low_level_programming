#include "main.h"

/**
 * print_numbers - prints 0-9 once
 * @sdnums - variable abbre based off
 * single digit numbers for simplicity
 */

void print_numbers(void)

{

	int sdnums = 0;



	for (sdnums = '0'; sdnums <= '9'; sdnums++)

		_putchar(sdnums);



	_putchar('\n');

}
