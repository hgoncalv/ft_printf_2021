/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:39:25 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/03/03 11:31:15 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*pdest;
	const char		*psrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if ((pdest == NULL) && (psrc == NULL))
		return (NULL);
	while (n--)
	{
		*pdest++ = *psrc++;
	}
	return (dest);
}
