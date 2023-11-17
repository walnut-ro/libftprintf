/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:14:27 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:24 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
* @notice	This function counts the lenght of a pointer.
* @param	uintptr_t			The unsigned integer pointer to count lenght.
* @return	int					The lenght of characters of the pointer.
*/
int	ptr_len(uintptr_t num)
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
* @notice	This function converts a pointer.
* @param	uintptr_t			The unsigned integer pointer to print.
* @return	void				No return value needed now.
*/
static int	put_ptr(uintptr_t num, int len)
{
	if (num >= 16)
	{
		put_ptr(num / 16, len);
		put_ptr(num % 16, len);
	}
	else
		write(1, &LHEX[num], 1);
	return (++len);
}

/**
* @notice	This function checks the pointer of something, converts it, prints
*			it and counts its pointer lenght.
* @param	unsigned_long_long	The unsigned integer pointer to print.
* @return	int					The lenght of characters of the printed
*								pointer.
*/
int	ft_print_pointer(unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	return (put_ptr(ptr, 2));
}
