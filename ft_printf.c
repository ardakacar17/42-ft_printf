/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:51:37 by akacar            #+#    #+#             */
/*   Updated: 2026/09/10 14:48:01 by akacar           ###   ########.fr       */
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
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(*args, int));
	else if (specifier == '%')
		count += ft_print_char('%');
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
		if (!format)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
		}
	}
}
