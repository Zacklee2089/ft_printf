/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:10 by lchun-jh          #+#    #+#             */
/*   Updated: 2022/11/07 19:23:31 by lchun-jh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long hex)
{
	int	total;

	total = 0;
	if (hex > 15)
		total += ft_printptr(hex / 16);
	total += ft_putcharf("0123456789abcdef"[hex % 16]);
	return (total);
}

int	ft_putptr(void *ptr)
{
	int				total;
	unsigned long	pointer;

	total = 0;
	pointer = (unsigned long) ptr;
	total += ft_putstrf("0x");
	total += ft_printptr(pointer);
	return (total);
}
