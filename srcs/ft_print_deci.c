/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikulnok <sikulnok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:57:54 by sikulnok          #+#    #+#             */
/*   Updated: 2023/10/13 22:13:05 by sikulnok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	change_n(long int *n, int *printed)
{
	if (print_char('-') == -1)
		return (-1);
	*n = (*n) * -1;
	(*printed)++;
	return (1);
}

int	print_decimal(long int n)
{
	int		printed;
	char	buffer[10];
	int		i;

	i = 0;
	printed = 0;
	if (n == 0)
		return (print_char('0'));
	if (n < 0)
		if (change_n(&n, &printed) == -1)
			return (-1);
	while (n > 0)
	{
		buffer[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		if (print_char(buffer[--i]) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}

int	print_unsigned(unsigned int n)
{
	int		printed;
	char	buffer[10];
	int		i;

	if (n == 0)
		return (print_char('0'));
	i = 0;
	printed = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		if (print_char(buffer[--i]) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}
