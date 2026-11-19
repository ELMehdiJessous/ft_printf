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

int ft_putchar(char r)
{
    return (write(1,&r,1));
}

int ft_puthexLow(unsigned long n)
{
    char    *hex;
    int     count;

    count = 0;
    hex = "0123456789abcdef";
    if (n >= 16)
        count += ft_puthexLow(n / 16);
    count += write(1, &hex[n % 16], 1);
    return (count);
}

int ft_puthexUp(unsigned long n)
{
    char    *hex;
    int     count;

    count = 0;
    hex = "0123456789ABCDEF";
    if (n >= 16)
        count += ft_puthexUp(n / 16);
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
    return (2 + ft_puthexLow(x));
}
