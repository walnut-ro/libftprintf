/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:39:04 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:13:09 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(long long nbr)
{
	int	size;

	size = (nbr < 0) + !(nbr);
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size + 1);
}

static int	power(long long base, long long exp)
{
	if (exp <= 0)
		return (exp == 0);
	if (exp % 2 == 0)
		return (power(base * base, exp / 2));
	else
		return (base * power(base * base, (exp - 1) / 2));
}

static char	*my_itoa(int n)
{
	char		*str;
	int			size;
	int			int_power;
	int			i;
	long long	nbr;

	nbr = (long long)n;
	size = get_size(nbr);
	int_power = power(10, size - 2 - (nbr < 0));
	str = malloc(size);
	if (!str)
		return (NULL);
	str[size - 1] = 0;
	i = (nbr < 0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (int_power)
	{
		str[i++] = (nbr / int_power) % 10 + '0';
		int_power /= 10;
	}
	return (str);
}

/**
* @notice	This function prints a number.
* @param	int					The number to print.
* @return	int					The lenght of characters of the printed
*								number.
*/
int	ft_print_number(int num)
{
	int		len;
	char	*numchar;

	len = 0;
	numchar = ft_itoa(num);
	len = print_str(numchar);
	free(numchar);
	return (len);
}
