/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:17:09 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:42 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		len = ft_print_str("(null)");
	else
	{
		while (str[len])
			if (ft_putchar_fd(str[len++], 1) < 0)
				return (-1);
	}
	return (len);
}
