/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagparsers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:43:13 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/03/20 02:26:40 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' '
		|| c >= '0' || c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_spec(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'e' || c == 'E'
		|| c == 'f' || c == 'g' || c == 'G' || c == 'o'
		|| c == 's' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'n' || c == '%')
		return (1);
	else
		return (0);
}

void	ft_flag_parser(char fmt, t_strk *strk)
{
	if (fmt == '-')
	{
		strk->minus = 1;
		strk->zero = 0;
	}
	else if (fmt == '+')
		strk->plus = 1;
	else if (fmt == ' ')
		strk->space = 1;
	else if (fmt == '#')
		strk->hash = 1;
	else if (ft_isdigit(fmt))
	{
		if (strk->star == 1)
			strk->width = 0;
		strk->width = (strk->width * 10) + (fmt - '0');
	}
}

void	ft_flag_width(va_list *args, t_strk *strk)
{
	strk->star = 1;
	strk->width = va_arg(*args, int);
	if (strk->width < 0)
	{
		strk->minus = 1;
		strk->width *= -1;
	}
}

char	*ft_flag_dot(char *fmt,
				t_strk *strk, va_list *args)
{
	fmt++;
	if (*fmt == '*')
	{
		strk->dot = va_arg(*args, int);
		fmt++;
	}
	else
	{
		strk->dot = 0;
		while (ft_isdigit(*fmt))
			strk->dot = (strk->dot * 10) + (*(fmt++) - '0');
	}
	return (fmt);
}
