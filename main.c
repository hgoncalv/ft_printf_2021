/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:50:58 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/03/20 02:25:46 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libftprintf.h"
#include <stdarg.h>

void	flags(t_strk *strk)
{
	printf("WIDTH:\t%d\nDOT:\t%d\nSPACES:\t%d\nSPACE:\t%d\nDOTS:\t%d\nType:\t%c\nZERO:\t%d\nSTRING:\t%s\nsignal:\t%c\nplus:\t%d\nNBR:\t%c", strk->width, strk->dot, strk->spaces, strk->space, strk->dots, strk->type, strk->zero, strk->nbr_str, strk->signal, strk->plus, strk->nbr_str[0]);
}

int	main(void)
{
	int ncm_p;

	printf("\nthis % d number", 17);
	ft_printf("\nthis % d number", 17);

	return (0);
}
