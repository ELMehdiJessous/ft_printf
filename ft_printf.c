/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljessou <eljessou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:57:40 by eljessou          #+#    #+#             */
/*   Updated: 2026/11/19 17:02:55 by eljessou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_handl(char r, va_list ap)
{
    int count;

    count = 0;
    if (r == 's')
        count += ft_putstr(va_arg(ap,char *));
    else if (r == 'd' || r == 'i')
        count += ft_putnbr(va_arg(ap,int));
    else if (r == 'c')
        count += ft_putchar(va_arg(ap, int));
    else if (r == 'x')
        count += ft_puthex(va_arg(ap, int),"0123456789abcdef");
    else if (r == 'X')
        count += ft_puthex(va_arg(ap, int),"0123456789ABCDEF");
    else if (r == '%')
        count += ft_putchar(37);
    else if (r == 'p')
        count += ft_pput(va_arg(ap,void *));
    else if (r == 'u')
        count += ft_putunbr(va_arg(ap, unsigned int));
        
    return (count);
}

int ft_printf(const char *str, ...)
{
    int     count;
    va_list ap;

    if (write(1, "", 0) == -1)
        return -1;
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
        {
            if (*++str == '\0')
                return (va_end(ap),-1);
            count += ft_handl(*str,ap);
        }
        else
            count += write(1,&(*str),1);
        str++;
    }
    return (count);
    
}
