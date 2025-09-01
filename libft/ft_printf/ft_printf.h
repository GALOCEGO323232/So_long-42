/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:24:32 by kgagliar            #+#    #+#           */
/*   Updated: 2025/08/04 13:24:32 by kgagliar           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_puthex(unsigned int num, const char format);
int	ft_putnbr(int nb);
int ft_putptr(void *ptr);
int ft_putstr(const char *str);
int ft_putint(unsigned int n);
int	ft_print_percent(void);

#endif
