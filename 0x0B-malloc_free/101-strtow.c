#include "main.h"
#include <stdlib.h>

/**
 * _wc - word count in a string
 * @str: string to analyze
 * Return: count of words in a string
 */

int _wc(char *str)

{

	int i = 0, wc = 0, flag = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			flag = 1;
		else if (flag)
		{
			wc++;
			flag = 0;
		}
	}
	return (wc);
}

/**
 * strtow - splits a string into words
 * @str: string to be splitted
 *
 * Return: The function returns a pointer to an array of strings (words)
 * NULL if str == NULL or str == ""
 */

char **strtow(char *str)

{
	char **m = NULL;
	int i, ii, w_idx = 0, wl = 0, wc = 0;

	if (str == NULL || str == '\0') /*keep eye out ofr last comparison*/
		return (NULL);
	wc = _wc(str);
	if (wc > 0)
		m = malloc(sizeof(char *) * (wc + 1));
	if (m == NULL)
		return (NULL);
	m[wc] = NULL;
	for (i = 0; str[i] != '\0'; wl = 0)
	{
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))

			i++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			wl++, i++;
		}
		if (wl > 0)
		{
			m[w_idx] = malloc(sizeof(char) * (wl + 1));
			if (m[w_idx] == NULL)
			{
				while (w_idx > 0)
					free(m[--w_idx]);
				free(m);
				return (NULL);
			}
			m[w_idx][wl] = '\0';
			for (ii = 0; ii < wl; ii++)
				m[w_idx][ii] = str[i - (wl - ii)];
			w_idx++;
		}
	}

	return (m);
}
