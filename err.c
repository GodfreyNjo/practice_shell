#include "shell.h"
#include <limits.h>

/**
 * custom_atoi - converts a string to an integer
 *
 * @str: the string to be converted
 *
 * Return: 0 if there are no numbers in the string,
 * converted number, or
 * -1 on error
 */
int custom_atoi(const char *str)
{
    if (str == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    int result = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    while (*str)
    {
        if (*str >= '0' && *str <= '9')
        {
            int digit = *str - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                errno = ERANGE;
                return -1;
            }

            result = result * 10 + digit;
        }
        else
        {
            errno = EINVAL;
            return -1;
        }

        str++;
    }

    return result * sign;
}
/**
 * convert_to_base - converts a number to a given base
 * @num: number
 * @flags: the argument flags
 * @base: base
 *
 * Return: string representation
 */
char *convert_to_base(long int idty, int radix, int mask)
{
    static char buffer[80];
    char *digits = (mask & CONVERT_LOWERCASE) ?
                   "0123456789abcdef" : "0123456789ABCDEF";
    char *result = &buffer[79];
    char sign = 0;
    unsigned long n = (idty < 0 && !(mask & CONVERT_UNSIGNED)) ? -idty : idty;

    if (idty < 0 && !(mask & CONVERT_UNSIGNED))
        sign = '-';

    *result = '\0';

    do
    {
        result--;
        *result = digits[n % radix];
        n /= radix;
    } while (n != 0);

    if (sign)
        result--;

    if (sign)
        *result = sign;


    return result;
}

