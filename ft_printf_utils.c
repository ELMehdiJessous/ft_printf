/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljessou <eljessou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 11:14:31 by eljessou          #+#    #+#             */
/*   Updated: 2026/11/19 22:50:34 by eljessou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char r)
{
    return (write(1,&r,1));
}

int ft_putstr(const char *s)
{
    int i;

    if (!s)
        return (write(1,"(null)",6));
    i = 0;
    while (*s)
        i += ft_putchar(*s++);
    return (i);
}

int ft_putnbr(int n)
{
    int     count;
    char    r;

    count = 0;
    if (n == -2147483648)
    {
        count += write (1,"-2147483648",11);
        return (count);
    }
    if (n < 0)
    {
        count += write (1, "-", 1);
        n = -n;
    }
    if (n > 9)
        count += ft_putnbr(n / 10);
    r = n % 10 + '0';
    count += write(1, &r, 1);
    return (count);
}

int ft_putunbr(unsigned int n)
{
    int     count;
    char    r;

    count = 0;
    if (n > 9)
        count += ft_putunbr(n / 10);
    r = n % 10 + '0';
    count += write(1, &r, 1);
    return (count);
}

int ft_puthex(unsigned int n, char *hex)
{
    int     count;

    count = 0;
    if (n >= 16)
        count += ft_puthex(n / 16, hex);
    count += write(1, &hex[n % 16], 1);
    return (count);
}

int ft_p_pointer(unsigned long n, char *hex)
{
    int     count;

    count = 0;
    if (n >= 16)
        count += ft_p_pointer(n / 16, hex);
    count += write(1, &hex[n % 16], 1);
    return (count);
}

int ft_pput(void *p)
{
    unsigned long   x;

    x = (unsigned long)p;
    if (x ==  0)
        return (write(1,"(nil)",5));
    write (1,"0x",2);
    return (2 + ft_p_pointer(x,"0123456789abcdef"));
}
