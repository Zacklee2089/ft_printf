/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:02:26 by lchun-jh          #+#    #+#             */
/*   Updated: 2022/11/07 13:58:19 by lchun-jh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int number)
{
	int	total;

	total = 0;
	if (number > 9)
		total += ft_putunsigned(number / 10);
	total += ft_putcharf("0123456789"[number % 10]);
	return (total);
}

int	checkflag(const char *format, va_list argptr)
{
	int	total;

	total = 0;
	if (*format == 's')
		total += ft_putstrf(va_arg(argptr, char *));
	else if (*format == 'c')
		total += ft_putcharf(va_arg(argptr, int));
	else if (*format == 'i' || *format == 'd')
		total += ft_putnum(va_arg(argptr, int));
	else if (*format == 'x' || *format == 'X')
		total += ft_puthex(va_arg(argptr, unsigned long long), *format);
	else if (*format == '%')
		total += ft_putcharf('%');
	else if (*format == 'u')
		total += ft_putunsigned(va_arg(argptr, unsigned int));
	else if (*format == 'p')
		total += ft_putptr(va_arg(argptr, void *));
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		total;

	total = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total += checkflag(format, argptr);
		}
		else
			total += ft_putcharf(*format);
		format++;
	}
	va_end(argptr);
	return (total);
}
