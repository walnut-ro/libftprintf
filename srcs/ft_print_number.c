/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:39:04 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/20 16:13:27 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int num)
{
	int	len;
	int	tmp;

	len = 0;
	if (num < 0)
	{
		if (ft_putchar_fd('-', 1) < 0)
			return (-1);
		num *= -1;
		len = 1;
	}
	tmp = ft_print_unsigned_number((unsigned int) num);
	if (tmp < 0)
		return (-1);
	len += tmp;
	return (len);
}
