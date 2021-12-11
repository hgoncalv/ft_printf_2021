/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:38:34 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/03/03 11:31:16 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char			*ptr;

	ptr = (char *)s;
	while (n--)
	{
		if (*ptr == (char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
