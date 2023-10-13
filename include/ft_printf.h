/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikulnok <sikulnok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:34 by sikulnok          #+#    #+#             */
/*   Updated: 2023/10/13 22:01:43 by sikulnok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_decimal(long int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned long int n, int state);
int	print_ptr(unsigned long long int n);
int	ft_printf(const char *format, ...);

#endif