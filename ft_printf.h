/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljessou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:58:22 by eljessou          #+#    #+#             */
/*   Updated: 2026/11/17 17:58:26 by eljessou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int ft_putstr(const char *s);
int ft_putnbr(int n);
int ft_printf(const char *str, ...);
int ft_putchar(char r);
int ft_puthexLow(unsigned long n);
int ft_puthexUp(unsigned long n);
int ft_pput(void *p);
int ft_putunbr(unsigned int n);


# endif