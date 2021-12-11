/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setnbrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:28:19 by hgoncalv          #+#    #+#             */
/*   Updated: 2021/03/20 02:42:07 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	ft_nbr2struc_1(char fmt, va_list *ap, t_strk *strk, long *nb)
{
	if (fmt == 'p')
	{
		strk->ull = (size_t)va_arg(*ap, int *);
		strk->push_front += 2;
	}
	else if (fmt == 'u')
		*nb = (unsigned int)va_arg(*ap, int);
	else
		*nb = va_arg(*ap, int);
	if (ft_toupper(fmt) == 'X' || fmt == 'p')
	{
		strk->base = 16;
		if (fmt == 'X')
			strk->upper = 1;
	}
	if (fmt == 'o')
		strk->base = 8;
}

void	ft_nbr2struc_2(char fmt, t_strk *strk, long *nb)
{
	if (nb > 0)
	{	
		if (fmt != 'o' && ft_toupper(fmt) != 'X' && fmt != 'p')
		{
			if (strk->plus != 1)
				strk->signal = ' ';
			else
				strk->signal = '+';
		}
	}
	if (*nb < 0)
	{
		if (fmt != 'o' && ft_toupper(fmt) != 'X' && fmt != 'p')
			strk->signal = '-';
		if (fmt == 'o' || ft_toupper(fmt) == 'X')
			*nb = 0xffffffff + *nb + 1;
		else
			*nb *= -1;
	}
	ft_nbr2struc_2b(fmt, strk, nb);
}

void	ft_nbr2struc_2b(char fmt, t_strk *strk, long *nb)
{
	if (strk->type != 'p')
		ft_itostr_base(*nb, strk, 0);
	else
		ft_itostr_base(strk->ull, strk, 0);
	strk->nbr_str = calloc(sizeof(char),
			(1 + strk->nbr_len + strk->push_front));
	if (fmt == 'p')
		ft_memcpy(strk->nbr_str, "0x", 2);
	strk->nbr_str[strk->nbr_len] = '\0';
	if (strk->type != 'p')
		ft_itostr_base(*nb, strk, 1);
	else
		ft_itostr_base(strk->ull, strk, 1);
	strk->nbr_len += strk->push_front;
}
