#include "main.h"

/**
 * get_size - Determines the size to cast the argument
 *
 * This function calculates the size to cast the argument based on the format string.
 *
 * @format: The formatted string in which to find the size specifier.
 * @s: Pointer to the current position in the format string.
 *
 * Return: The size specifier (S_LONG or S_SHORT), or 0 if no size specifier is found.
 */
int get_size(const char *format, int *s)
{
    int curr_s = *s + 1;
    int size = 0;

    if (format[curr_s] == 'l')
        size = S_LONG;
    else if (format[curr_s] == 'h')
        size = S_SHORT;

    if (size == 0)
        *s = curr_s - 1;
    else
        *s = curr_s;

    return size;
}
