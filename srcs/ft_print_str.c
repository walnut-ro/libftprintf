/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:17:09 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:31 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
* @notice	This function prints a string.
* @param	char_pointer		The string to print.
* @return	int					The lenght of characters of the printed
*								string.
*/
int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}
