/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:01:27 by hugogonca         #+#    #+#             */
/*   Updated: 2021/03/03 11:31:17 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		car;
	unsigned char		*dest;
	const unsigned char	*sorce;
	size_t				i;

	car = (unsigned char)c;
	dest = (unsigned char *)dst;
	sorce = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorce[i];
		if (sorce[i] == car)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
