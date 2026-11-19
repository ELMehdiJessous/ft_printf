#include <stdio.h>
#include "ft_printf.h"


int main()
{
    int *a;

    int y = (unsigned long) a;
    unsigned long x = (unsigned long) a;

    printf("%d\n",y);
    printf("%lu\n",x);
}

