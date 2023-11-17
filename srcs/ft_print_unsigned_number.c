/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:28:27 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:39 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int num)
{
	char	*numchar;
	int		len;

	len = num_len(num);
	numchar = (char *)malloc(len + 1);
	if (!numchar)
		return (NULL);
	numchar[len] = '\0';
	while (len)
	{
		numchar[--len] = num % 10 + '0';
		num /= 10;
	}
	return (numchar);
}

/**
* @notice	This function prints the unsigned interger number.
* @param	unsigned_int		The unsigned integer number to print.
* @return	int					The lenght of characters of the printed
*								unsigned integer.
*/
int	ft_print_unsigned_number(unsigned int num)
{
	int		len;
	char	*numchar;

	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		len++;
	}
	else
	{
		numchar = ft_unsigned_itoa(num);
		len += print_str(numchar);
		free(numchar);
	}
	return (len);
}
