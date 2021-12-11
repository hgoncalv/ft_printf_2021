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

void	ft_str2struc_1(char fmt, va_list *ap, t_strk *strk)
{
	if (fmt == '%')
		strk->nbr_str = "%";
	else if (fmt == 'c')
	{
		strk->nbr_str = calloc(sizeof(char), 2);
		strk->nbr_str[0] = (char)va_arg(*ap, int);
		strk->nbr_str[1] = '\0';
	}
	else
		strk->nbr_str = va_arg(*ap, char *);
	if (strk->nbr_str == NULL)
	{
		strk->nbr_str = calloc(sizeof(char), 7);
		ft_strlcpy(strk->nbr_str, "(null)", 7);
	}
}

void	ft_str2struc_2(char fmt, t_strk *strk)
{
	if (fmt == 'c' || fmt == '%')
		strk->nbr_len = 1;
	else if (strk->dot == 0 && strk->width == 0)
		strk->nbr_len = 0;
	else if (ft_strncmp(strk->nbr_str, "(null)", 6) && strk->dot == 0)
		strk->nbr_len = 0;
	else
	{
		if (strk->dot > 0)
		{
			if (strk->dot < (int)ft_strlen(strk->nbr_str))
				strk->nbr_len = strk->dot;
			else
				strk->nbr_len = (int)ft_strlen(strk->nbr_str);
		}
		else if (strk->dot == 0)
			strk->nbr_len = 0;
		else
			strk->nbr_len = ft_strlen(strk->nbr_str);
	}
}

void	ft_set_nbrstr(char fmt, va_list *ap, t_strk *strk)
{
	long	nb;

	nb = 0;
	strk->type = fmt;
	if (fmt != 'c' && fmt != 's' && fmt != '%')
	{
		ft_nbr2struc_1(fmt, ap, strk, &nb);
		ft_nbr2struc_2(fmt, strk, &nb);
	}
	else
	{
		ft_str2struc_1(fmt, ap, strk);
		ft_str2struc_2(fmt, strk);
	}
}
