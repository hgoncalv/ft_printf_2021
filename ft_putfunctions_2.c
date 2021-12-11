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

void	ft_p_nbr_minus(t_strk *strk)
{
	if ((strk->type != 's' && strk->type != 'p'
			&& ft_toupper(strk->type) != 'X') && (strk->signal == '-'
			|| strk->plus == 1 || strk->space == 1))
		ft_putchar_fd(strk->signal, 1);
	while (strk->dots-- > 0 && strk->type != 's' && strk->type != 'p')
		ft_putchar_fd('0', 1);
	if (ft_toupper(strk->type) == 'X' && strk->hash == 1
		&& (!(strk->nbr_len == 1 && strk->nbr_str[0] == '0')))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(strk->type, 1);
	}
	ft_put_strktr(strk);
	while (strk->spaces-- > 0)
		ft_putchar_fd(' ', 1);
}

void	ft_p_nbr_no_minus(t_strk *strk)
{
	if (strk->type != 's' && strk->type != 'p'
		&& ft_toupper(strk->type) != 'X' && strk->zero == 1 && strk->dot <= 0)
	{
		if (strk->signal == '-' || strk->plus == 1 || strk->space == 1)
		{
			ft_putchar_fd(strk->signal, 1);
			strk->already_print = 1;
		}
	}
	if (ft_toupper(strk->type) == 'X' && strk->hash == 1 && (strk->zero == 1
			|| strk->dot > 0)
		&& (!(strk->nbr_len == 1 && strk->nbr_str[0] == '0')))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(strk->type, 1);
	}
	ft_p_nbr_no_minus_b(strk);
}

void	ft_p_nbr_no_minus_b(t_strk *strk)
{
	while (strk->spaces-- > 0)
	{
		if ((strk->dot < 0 && strk->zero == 1)
			|| (strk->zero == 1 && strk->type == 's'))
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (strk->type != 's' && strk->type != 'p'
		&& ft_toupper(strk->type) != 'X' && strk->already_print != 1)
		if (strk->signal == '-' || strk->plus == 1 || strk->space == 1)
			ft_putchar_fd(strk->signal, 1);
	while (strk->dots-- > 0 && strk->type != 's' && strk->type != 'p')
		ft_putchar_fd('0', 1);
	if (strk->dot <= 0 && ft_toupper(strk->type) == 'X' && strk->hash == 1
		&& strk->zero == 0
		&& (!(strk->nbr_len == 1 && strk->nbr_str[0] == '0')))
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(strk->type, 1);
	}
	ft_put_strktr(strk);
}

void	ft_printoscreen(t_strk *strk)
{
	ft_set_dots_n_spaces(strk);
	if (strk->minus == 1)
		ft_p_nbr_minus(strk);
	else
		ft_p_nbr_no_minus(strk);
}
