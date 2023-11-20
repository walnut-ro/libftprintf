/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:17:27 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/20 15:17:15 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_conversion(va_list ap, const char c)
{
	int	len;

	len = 1;
	if (c == 'c')
	{
		if ((int) ft_putchar_fd(va_arg(ap, int), 1) < 0)
			return (-1);
	}
	else if (c == 's')
		len = ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		len = ft_print_pointer((unsigned long int) va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		len = ft_print_number(va_arg(ap, int));
	else if (c == 'u')
		len = ft_print_unsigned_number(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_print_hex(va_arg(ap, unsigned int), c);
	else if (c == '%')
	{
		if (ft_putchar_fd('%', 1) < 0)
			return (-1);
	}
	return (len);
}

int	ft_print_format(const char *format, va_list *ap)
{
	int			ret;
	int			tmp;

	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			if (ft_putchar_fd(*format, 1) < 0)
				return (-1);
			ret++;
		}
		else
		{
			format++;
			tmp = arg_conversion(*ap, *format);
			if (tmp == -1)
				return (-1);
			ret += tmp;
			if (!*format)
				break ;
		}
		format++;
	}
	return (ret);
}
