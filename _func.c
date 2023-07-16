#include "main.h"

/**
* _strcmp - function to compare
* @string1: The input string
* @string2: The input string
* Return: return int
*/

int _strcmp(const char *string1, const char *string2)
{
	while (*string1 && (*string1 == *string2))
	{
		string1++;
		string2++;
	}
	return (*(unsigned char *)string1 - *(unsigned char *)string2);
}

/**
* _strlen - Calculates the length of a string
* @str: The input string
* Return: The length of the string
*/

size_t _strlen(const char *str)
{
	const char *s;

	for (s = str; *s; ++s)
		;
	return (s - str);

}

/**
 * _space - Checks if a character is a whitespace character
 * @c: The character to check
 * Return: 1 if it's a whitespace character, 0 otherwise
 */

int _space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

/**
 *
 *
*/

void *_memmov(void *des, const void *src, size_t num) {
    const unsigned char *_src = (const unsigned char *)src;
    unsigned char *_dest = (unsigned char *)des;

    if (_dest > _src) {
        _dest += num;
        _src += num;
        while (num--)
            *--_dest = *--_src;
    } else {
        while (num--)
            *_dest++ = *_src++;
    }

    return des;
}

/**
* trim_buffer - leading and trailing whitespace from a buffer
* @buffer: The input buffer
* return:  always 0
*/


void trim_buffer(char *buffer) {
    size_t size = _strlen(buffer), i = 0;

    if (size == 0)
        return;

    while (_space((unsigned char)buffer[i]))
        i++;

    _memmov(buffer, buffer + i, size - i + 1);
    size -= i;

    while (size > 0 && _space((unsigned char)buffer[size - 1]))
        size--;

    buffer[size] = '\0';
}

