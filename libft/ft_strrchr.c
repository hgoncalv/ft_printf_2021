/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:08:33 by hugogonca         #+#    #+#             */
/*   Updated: 2021/03/03 11:31:02 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*sptr;

	sptr = s;
	while (*sptr)
		sptr++;
	while (sptr != s && *sptr != (char)c)
		sptr--;
	if (*sptr != (char)c)
		return (NULL);
	else
		return ((char *)sptr);
}
