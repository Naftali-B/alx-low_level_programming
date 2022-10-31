#include "main.h"

/**
 *  * get_endianness - get information about
 *   * processor whether its big endian or
 *    * little endian
 *     * Return: 0 | 1
 *      */
int get_endianness(void)
{
		int x = 1;

			char *y = (char *)&x;

				if (*y)
						{
									return (1);
										}
				return (0);
}
