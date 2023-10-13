/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikulnok <sikulnok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 21:56:44 by sikulnok          #+#    #+#             */
/*   Updated: 2023/10/13 22:22:19 by sikulnok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	printed;
	int	error;

	printed = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		error = print_char(*str);
		if (error == -1)
			return (-1);
		printed += error;
		str++;
	}
	return (printed);
}
