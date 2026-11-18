/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljessou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:57:40 by eljessou          #+#    #+#             */
/*   Updated: 2026/11/17 17:57:42 by eljessou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handl(char r, va_list ap)
{
    int count;

    count = 0;
    if (r == 's')
        count += ft_putstr(va_arg(ap,char *));
    if (r == 'd' || r == 'i')
        count += ft_putnbr(va_arg(ap,int));
    if (r == 'c')
        count += ft_putchar(va_arg(ap, int));
    if (r == 'x')
        count += ft_puthexLow(va_arg(ap, int));
    if (r == 'X')
        count += ft_puthexUp(va_arg(ap, int));
    if (r == '%')
        count += ft_putchar(37);
    return (count);
}

int ft_printf(const char *str, ...)
{
    int     count;
    va_list ap;

    count = 0;
    va_start (ap,str);
    if (!str)
    {
        va_end(ap);
        return (-1);
    }
    while (*str)
    {
        if (*str == '%')
            count+=ft_handl(*++str,ap);
        else
            ft_putchar(*str);
        str++;
    }
    return (count);
    
}