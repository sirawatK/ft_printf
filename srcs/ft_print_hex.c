/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikulnok <sikulnok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:59:06 by sikulnok          #+#    #+#             */
/*   Updated: 2023/10/13 22:12:39 by sikulnok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_hex(unsigned long int n, int state)
{
	int		printed;
	char	buffer[16];
	int		i;
	char	*base;

	if (n == 0)
		return (print_char('0'));
	if (state == 0)
		base = "0123456789abcdef";
	else if (state == 1)
		base = "0123456789ABCDEF";
	i = 0;
	printed = 0;
	while (n > 0)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		if (print_char(buffer[--i]) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}

int	print_ptr(unsigned long long int n)
{
	int	printed;
	int	error;

	printed = 0;
	error = print_str("0x");
	if (error == -1)
		return (-1);
	printed += error;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		printed++;
	}
	else
		printed += print_hex(n, 0);
	return (printed);
}
