/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljessou <eljessou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:58:22 by eljessou          #+#    #+#             */
/*   Updated: 2026/11/19 17:25:22 by eljessou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int ft_handl(char r, va_list ap);
int ft_printf(const char *str, ...);
int ft_putchar(char r);
int ft_putstr(const char *s);
int ft_putnbr(int n);
int ft_putunbr(unsigned int n);
int ft_puthex(unsigned int n, char *hex);
int ft_p_pointer(unsigned long n, char *hex);
int ft_pput(void *p);

# endif