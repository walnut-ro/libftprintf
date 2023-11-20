/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevinsc <dlevinsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:01:52 by dlevinsc          #+#    #+#             */
/*   Updated: 2023/11/06 19:15:11 by dlevinsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	size_t	i;

	if ((uintptr_t)src < (uintptr_t)dst
		&& (uintptr_t)src + count > (uintptr_t)dst)
		while (count--)
			*(char *)(dst + count) = *(char *)(src + count);
	else if ((uintptr_t)dst < (uintptr_t)src
		&& (uintptr_t)dst + count > (uintptr_t)src)
	{
		i = -1;
		while (++i < count)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	else
		ft_memcpy(dst, src, count);
	return (dst);
}
