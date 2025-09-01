/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:46:28 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 13:46:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putint(unsigned int n)
{
    char digit;
    int count;
   
    count = 0;
    if (n >= 10)
        count += ft_putuint(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
    count++;
    
    return (count);
}
