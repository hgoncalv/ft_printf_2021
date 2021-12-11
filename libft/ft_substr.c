/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 03:07:34 by hugogonca         #+#    #+#             */
/*   Updated: 2021/03/03 11:31:00 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		start = s_len;
	if (len > s_len)
		len = s_len;
	substr = (char *)malloc((len + 1) * sizeof(*s));
	if (!substr)
		return (NULL);
	else
	{
		ft_memmove(substr, s + start, len + 1);
		substr[len] = '\0';
	}
	return (substr);
}
