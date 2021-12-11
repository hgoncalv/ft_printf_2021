/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:06:05 by hugogonca         #+#    #+#             */
/*   Updated: 2021/03/03 11:31:14 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest == src)
		return (dst);
	if (dest > source)
	{
		while (n--)
			dest[n] = source[n];
	}
	else if (dest < source)
		ft_memcpy(dst, src, n);
	return (dst);
}
