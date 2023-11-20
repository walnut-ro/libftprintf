/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:33 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/20 15:22:29 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned int num, const char conversion)
{
	int	i;
	int	err;

	i = 0;
	if (num < 16)
	{
		if (conversion == 'x')
			err = ft_putchar_fd(LHEX[num], 1);
		else
			err = ft_putchar_fd(UHEX[num], 1);
		if (err < 0)
			return (-1);
		return (1);
	}
	i = 1 + put_hex(num / 16, conversion);
	if (i <= 0)
		return (-1);
	if (put_hex(num % 16, conversion) < 0)
		return (-1);
	return (i);
}

int	ft_print_hex(unsigned int num, const char conversion)
{
	if (num == 0)
	{
		if (ft_putchar_fd('0', 1) < 0)
			return (-1);
		return (1);
	}
	return (put_hex(num, conversion));
}
