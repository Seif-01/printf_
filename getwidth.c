#include "main.h"

/**
 * get_width - Calculates the width for printing
 *
 * This function calculates the width for printing based on the format string.
 *
 * @format: The formatted string in which to find the width specifier.
 * @i: Pointer to the current position in the format string.
 * @list: List of arguments.
 *
 * Return: The calculated width value.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_s;
    int width = 0;

    for (curr_s = *i + 1; format[curr_s] != '\0'; curr_s++)
    {
        if (is_digit(format[curr_s]))
        {
            width *= 10;
            width += format[curr_s] - '0';
        }
        else if (format[curr_s] == '*')
        {
            curr_s++;
            width = va_arg(list, int);
            break;
        }
        else
        {
            break;
        }
    }

    *i = curr_s - 1;

    return width;
}
