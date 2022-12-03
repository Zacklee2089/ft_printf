/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchun-jh <lchun-jh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:11:42 by lchun-jh          #+#    #+#             */
/*   Updated: 2022/12/03 03:36:06 by lchun-jh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putcharf(char c);
int	ft_putstrf(char *str);
int	ft_putnum(int number);
int	ft_printhex(unsigned int hex, char *hexadecimal);
int	ft_puthex(unsigned int hex, char filter);
int	ft_putptr(void *ptr);
int	ft_printptr(unsigned long hex);
int	ft_putunsigned(unsigned int number);
int	checkflag(const char *format, va_list argptr);
int	ft_printf(const char *format, ...);

#endif