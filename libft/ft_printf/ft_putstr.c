#include "ft_printf.h"

int ft_putstr(const char *str)
{
    int count;

    count = 0;
    if (str == NULL)
    {
        write(1, "(null)", 6);
        count = 6;
    }
    else
    {
        while(*str)
        {
            write(1, str++, 1);
            count++;
        }
    }
    return (count);
}