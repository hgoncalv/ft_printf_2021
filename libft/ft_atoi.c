/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:28:12 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/03/03 16:28:14 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\f' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

static int	return_for_long_int(int signal)
{
	if (signal >= 0)
		return (-1);
	if (signal < 0)
		return (0);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		res;
	int			signal;
	int			count;

	signal = 1;
	count = 0;
	res = 0;
	while (my_isspace(*str))
		str++;
	if (*str == '-')
	{
		signal = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str++ - '0');
		count++;
		if (count == 20)
			return (return_for_long_int(signal));
	}
	return (signal * res);
}
