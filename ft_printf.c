/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:57:31 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/04/22 14:07:57 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

t_strk	ft_init_strk(void)
{
	t_strk		strk;

	strk.space = 0;
	strk.spaces = 0;
	strk.dot = -1;
	strk.upper = 0;
	strk.minus = 0;
	strk.star = 0;
	strk.type = 'd';
	strk.width = 0;
	strk.zero = 0;
	strk.nbr_len = 0;
	strk.base = 10;
	strk.push_front = 0;
	strk.signal = ' ';
	strk.nbr_len = 0;
	strk.padchar = ' ';
	strk.already_print = 0;
	return (strk);
}

void	ft_itostr_letter_for_10(t_strk *strk, int index, long nbr)
{
	if (strk->upper == 1)
		strk->nbr_str[index] = nbr + 'A' - 10;
	else
		strk->nbr_str[index] = nbr + 'a' - 10;
}

size_t	ft_itostr_base(size_t nbr, t_strk *strk, int nbr_len)
{
	int	index;

	if (nbr_len == 0)
	{
		if (nbr == 0)
		{
			if (strk->nbr_len == 0)
				strk->nbr_len += 1;
			return (0);
		}
		strk->nbr_len += 1;
		ft_itostr_base((nbr / strk->base), strk, 0);
		return (nbr);
	}
	if (nbr == 0 && nbr_len == 1)
		strk->nbr_str[0] = '0';
	if (nbr == 0)
		return (0);
	ft_itostr_base((nbr / strk->base), strk, nbr_len + 1);
	index = strk->nbr_len - nbr_len + strk->push_front;
	if (nbr % strk->base > 9)
		ft_itostr_letter_for_10(strk, index, nbr % strk->base);
	else
		strk->nbr_str[index] = nbr % strk->base + '0';
	return (nbr);
}

static char	*ft_fprint_parseflags(char *fmt, va_list *args, t_strk *strk)
{
	while (1)
	{
		if (*fmt == '0' && strk->width == 0 && strk->minus == 0)
			strk->zero = 1;
		if (*fmt == '-' || *fmt == '+' || ft_isdigit(*fmt)
			|| *fmt == ' ' || *fmt == '#')
			ft_flag_parser(*fmt, strk);
		if (*fmt == '.')
			fmt = ft_flag_dot(fmt, strk, args);
		if (*fmt == '*')
			ft_flag_width(args, strk);
		if (ft_is_spec(*fmt))
			break ;
		fmt++;
	}
	ft_set_nbrstr(*fmt, args, strk);
	return (fmt);
}

void	ft_printf(char *fmt, ...)
{
	va_list	args;
	t_strk	strk;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (ft_is_flag(*fmt))
				strk = ft_init_strk();
			fmt++;
			fmt = ft_fprint_parseflags(fmt, &args, &strk);
			ft_printoscreen(&strk);
		}
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	va_end(args);
}
