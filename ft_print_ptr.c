/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacar <akacar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 17:11:48 by akacar            #+#    #+#             */
/*   Updated: 2026/09/12 19:42:29 by akacar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_print_string("0x");
	count += ft_print_hex(n, 'x');
	return (count);
}
