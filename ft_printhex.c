/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:59 by lchun-jh          #+#    #+#             */
/*   Updated: 2022/11/07 14:50:56 by lchun-jh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int hex, char *hexadecimal)
{
	int	total;

	total = 0;
	if (hex > 15)
		total += ft_printhex(hex / 16, hexadecimal);
	total += ft_putcharf(hexadecimal[hex % 16]);
	return (total);
}

int	ft_puthex(unsigned int hex, char filter)
{
	int		total;
	char	*upperhex;
	char	*lowerhex;

	total = 0;
	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (filter == 'x')
		total += ft_printhex(hex, lowerhex);
	else
		total += ft_printhex(hex, upperhex);
	return (total);
}
