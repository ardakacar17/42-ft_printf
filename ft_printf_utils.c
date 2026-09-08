/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:54:06 by akacar            #+#    #+#             */
/*   Updated: 2026/09/08 21:06:51 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	int		c;
	char	ch;

	c = va_arg(*args, int);
	ch = (char) c;
	write(1, &ch, 1);
	return (1);
}

int	ft_print_string(va_list *args)
{
}
