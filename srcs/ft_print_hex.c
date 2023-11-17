/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:33 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:01 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
* @notice	This function counts the lenght of an unsigned integer number converted
*			into a hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

/**
* @notice	This function converts an unsigned integer number into hexadecimal.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @param	len					Initial size.
*								
* @return	int					The lenght of characters of the hexadecimal number.
*/
static int	put_hex(unsigned int num, const char conversion, int len)
{
	if (num >= 16)
	{
		put_hex(num / 16, conversion, len);
		put_hex(num % 16, conversion, len);
	}
	else
	{
		if (conversion == 'x')
			write(1, &LHEX[num], 1);
		else
			write(1, &UHEX[num], 1);
	}
	return (++len);
}

/**
* @notice	This function checks an unsigned integer number, converts it into
*			hexadecimal, prints it and counts its lenght.
* @param	unsigned_int		The unsigned integer number to convert in
*								hexadecimal.
* @param	const_char			The conversion needed ('x' for lowercase and 'X'
*								for uppercase).
* @return	int					The lenght of characters of the hexadecimal number.
*/
int	ft_print_hex(unsigned int num, const char conversion)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (put_hex(num, conversion, 0));
}
