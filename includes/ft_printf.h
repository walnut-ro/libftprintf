/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:49:30 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/17 15:14:45 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * includes
 */
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/**
 * defines
 */
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

/**
 * helper functions
 *
 * void	ft_putchar_fd(char c, int fd);
*/

/**
 * function to extract flags, width, precision and specifier from format string
 */
int		ft_print_format(const char *format, va_list ap);

/**
 * format and argument printing functions
 */
int		ft_print_format(const char *format, va_list ap);
int		ft_print_str(char *str);
int		ft_print_number(int num);
int		ft_print_unsigned_number(unsigned int num);
int		ft_print_hex(unsigned int num, const char conversion);
int		ft_print_pointer(unsigned long long ptr);

/**
 * mandatory function
 */
int		ft_printf(const char *format, ...);

#endif