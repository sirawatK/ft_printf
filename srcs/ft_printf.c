/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikulnok <sikulnok@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:20 by sikulnok          #+#    #+#             */
/*   Updated: 2023/10/14 00:10:45 by sikulnok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed = print_char(va_arg(ap, int));
	else if (specifier == 's')
		printed = print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		printed = print_decimal(va_arg(ap, int));
	else if (specifier == 'u')
		printed = print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		printed = print_hex(va_arg(ap, unsigned int), 0);
	else if (specifier == 'X')
		printed = print_hex(va_arg(ap, unsigned int), 1);
	else if (specifier == 'p')
		printed = print_ptr(va_arg(ap, unsigned long long int));
	else if (specifier == '%')
		printed = write(1, "%", 1);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;
	int		error;

	printed = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			error = print_format(*(++format), ap);
		else
			error = print_char(*format);
		if (error == -1)
			return (-1);
		printed += error;
		format++;
	}
	va_end(ap);
	return (printed);
}
