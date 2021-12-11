/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:57:31 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/04/22 14:14:20 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_put_strktr(t_strk *strk)
{
	int	dots;

	dots = 0;
	if (strk->type != 's')
	{
		if (!(strk->nbr_len == 1 && strk->nbr_str[0] == '0' && strk->dot == 0))
			ft_putstr_fd(strk->nbr_str, 1);
	}
	else
	{
		while (dots < (int)strk->nbr_len)
		{
			ft_putchar_fd(strk->nbr_str[dots], 1);
			dots++;
		}
	}
	if (strk->type == 'c' && strk->nbr_str[0] == '\0')
		write(1, &strk->nbr_str[0], 1);
	if (strk->type == 'p' && ft_toupper(strk->nbr_str[1]) != 'X')
	{
		if (strk->type == 'p' && strk->nbr_str[0] == '0' && strk->dot == 0)
			ft_putchar_fd('x', 1);
		else
			ft_putstr_fd("x0", 1);
	}
}

void	ft_set_dots_n_spaces(t_strk *strk)
{
	if (strk->type == 'p' && strk->nbr_str[0] == '0' && strk->dot == 0)
		strk->nbr_len = 2;
	if (strk->type == '%' || strk->type == 'c')
		strk->type = 's';
	if (strk->dot <= -1)
	{
		strk->spaces = strk->width - strk->nbr_len;
		strk->dots = 0;
	}
	else
	{
		if (strk->dot >= (int)strk->nbr_len && strk->type != 's'
			&& strk->type != 'p' )
			strk->spaces = strk->width - strk->dot;
		else
			strk->spaces = strk->width - strk->nbr_len;
		strk->dots = strk->dot - strk->nbr_len;
	}
	ft_set_dots_n_spaces_b(strk);
}

void	ft_set_dots_n_spaces_b(t_strk *strk)
{
	if ((strk->nbr_len <= 1 && strk->nbr_str[0] == '0' && strk->dot == 0))
		strk->spaces++;
	if ((strk->type != 's' && strk->type != 'p') && (strk->signal == '-'
			|| strk->plus == 1 || strk->space == 1))
		strk->spaces--;
	if (ft_toupper(strk->type) == 'X' && strk->hash == 1
		&& (!(strk->nbr_len == 1 && strk->nbr_str[0] == '0')))
		strk->spaces -= 2;
	if (strk->spaces < 0)
		strk->spaces = 0;
	if (strk->dots < 0)
		strk->dots = 0;
}
