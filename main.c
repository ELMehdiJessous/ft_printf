#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_list
{
        int position;
        char *p;
} t_list;


void ft_putchar(char r)
{
        write(1,&r,1);
}

void	ft_putnbr_fd(int n, int fd)
{
        if (n == -2147483648)
        {
                write(fd, "-2147483648", 11);
                return ;
        }
        if (n < 0)
        {
                write(fd, "-", 1);
                n = (-n);
        }
        if (n > 9)
                ft_putnbr_fd(n / 10, fd);
        ft_putchar((n % 10) + '0');
}

int ft_strlen(char *s)
{
        int i = 0;
        while (s[i])
                i++;
        return (i);
}

void ft_putstr(const char *s)
{
    while (*s)
        ft_putchar(*s++);
}



int point(char *r, t_list *lst)
{
        int src_len = ft_strlen(r);
        int dest_len = ft_strlen(lst->p);
        static int counter;

        counter += 1;
        if (!src_len)
                return (0);
        if (src_len < dest_len || dest_len == 0)
        {
                lst->p = r;
                lst->position = counter;
        }
        return (1);
}

int solve(va_list ap, t_list **lst)
{
        int index;
        while ((point(va_arg(ap,char *),*lst)));
        ft_putstr((*lst)->p);
        return ((*lst)->position);
}

void hello(char *s, ...)
{
        va_list ap;
        static t_list *lst;
        va_start(ap,s);
        int index;
        
        lst = malloc(sizeof(t_list));
        lst->p = "";
        lst->position = -1;
        while (*s)
        {
                if (*s == '%')                
                {
                        if (*++s == 's')
                        {
                                solve(ap,&lst);
                        }
                        if (*s == 'd')
                                ft_putnbr_fd(lst->position,1);
                }
                else
                        ft_putchar(*s);
                *s++;
        }
}


int main(int ac, char **av)
{
        int i = 1;
        hello("string is: %s at position : %d", av[1]);
}
