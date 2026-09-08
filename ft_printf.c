/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:51:37 by akacar            #+#    #+#             */
/*   Updated: 2026/09/08 21:06:52 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_char(args));
	if (specifier == 's')
		return (ft_print_string(args));
}

int	ft_printf(const char *format, ...)
{
}
