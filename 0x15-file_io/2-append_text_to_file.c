#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The text to be appended at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 * -1 if filename is NULL or if the file cannot be opened or written.
 **/
int append_text_to_file(const char *filename, char *text_content)
{
    int fd = open(filename, O_APPEND | O_WRONLY), len = 0;

    if (!filename || fd == -1)
        return (-1);

    while (text_content && text_content[len] != '\0')
        len++;

    if (len)
        write(fd, text_content, len);

    close(fd);

    return (1);
}
