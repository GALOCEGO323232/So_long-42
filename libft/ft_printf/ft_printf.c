/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:24:32 by kgagliar            #+#    #+#           */
/*   Updated: 2025/08/04 13:24:32 by kgagliar           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_printf_parser(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_args(args, int)));
    else if (c == 'i' || c == 'd')
        return (ft_putnbr(va_args(args, int)));
    else if (c == 'x' || c == 'X')
        return (ft_puthex(va_args(args, unsigned int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c == 'p')
        return (ft_putptr(va_args(args, void *)));
    else if (c == 'u')
        return (ft_putint(va_args(args, unsigned int)));
    else if (c == '%')
        return (ft_print_percent());
    return (0);
    
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int print;
    int i;

    if (!format)
        return (write(1, "(null)", 6));
    while (format[i])
    {
        if (forrmat[i] == '%')
        {
            i++;
            print += ft_parser(args, format);
        }
        else
        {
            print += ft_puthar(format[i]);
            i++;
        }
    }
    va_end(args);
    return (print);
}
