/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:51:37 by akacar            #+#    #+#             */
/*   Updated: 2026/09/15 14:03:48 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(*args, int));
	else if (specifier == 's')
		count += ft_print_string(va_arg(*args, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(*args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(*args, int));
	else if (specifier == '%')
		count += ft_print_char('%');
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(*args, unsigned int), specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count += ft_format_check(format[i], &args);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
