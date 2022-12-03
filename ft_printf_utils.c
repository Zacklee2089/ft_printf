/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:44 by lchun-jh          #+#    #+#             */
/*   Updated: 2022/11/07 19:23:02 by lchun-jh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putcharf(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstrf(char *str)
{
	int	number;

	number = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		number += ft_putcharf(*str);
		str++;
	}
	return (number);
}

int	ft_putnum(int number)
{
	int	total;

	total = 0;
	if (number == -2147483648)
	{
		total += ft_putnum(number / 10);
		total += ft_putcharf('8');
		return (total);
	}
	else if (number < 0)
	{
		total += ft_putcharf('-');
		total += ft_putnum(-number);
	}
	else
	{
		if (number > 9)
			total += ft_putnum(number / 10);
		total += ft_putcharf("0123456789"[number % 10]);
	}
	return (total);
}
