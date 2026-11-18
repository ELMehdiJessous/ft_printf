#include "ft_printf.h"

int ft_putstr(const char *s)
{
    int i;

    i = 0;
    while (*s)
    {
        i +=write(1,&(*s),1);
        s++;
    }
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
    if (n > 9)
        count += ft_putnbr(n / 10);
    r = n % 10 + '0';
    count += write(1, &r, 1);
    return (count);
}

int ft_putchar(char r)
{
    return (write(1,&r,1));
}

int ft_puthexLow(int n)
{
    char    *hex;
    int     count;
    char    r;

    count = 0;
    hex = "0123456789abcdefg";
    if (n > 16)
        count += ft_putnbr(n / 16);
    r = hex[n % 16];
    count += write(1, &r, 1);
    return (count);
}

int ft_puthexUp(int n)
{
    char    *hex;
    int     count;
    char    r;

    count = 0;
    hex = "0123456789ABCDEFG";
    if (n > 16)
        count += ft_putnbr(n / 16);
    r = hex[n % 16];
    count += write(1, &r, 1);
    return (count);
}