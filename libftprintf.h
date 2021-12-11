/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgoncalv <hgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:02:27 by hugogoncalv       #+#    #+#             */
/*   Updated: 2021/04/22 14:22:31 by hgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_strk
{
	char				*nbr_str;
	char				padchar;
	int					nbr;
	unsigned long long	ull;
	size_t				nbr_len;
	int					space;
	int					dots;
	char				signal;
	int					hash;
	int					push_front;
	int					spaces;
	int					already_print;
	int					type;
	int					width;
	int					minus;
	int					plus;
	int					zero;
	int					dot;
	int					star;
	int					base;
	int					upper;
}						t_strk;

void				ft_printf(char *fmt, ...);
int					lower_of_2(int a, int b);
void				ft_itostr_letter_for_10(t_strk *strk, int index, long nbr);
size_t				ft_itostr_base(size_t nbr, t_strk *strk, int nbr_len);
void				ft_put_strktr(t_strk *strk);

int					ft_is_flag(char c);
int					ft_is_spec(char c);
void				ft_flag_parser(char fmt, t_strk *strk);
void				ft_flag_width(va_list *args, t_strk *strk);
char				*ft_flag_dot(char *fmt, t_strk *strk, va_list *args);

void				ft_nbr2struc_1(char fmt, va_list *ap,
						t_strk *strk, long *nb);
void				ft_nbr2struc_2(char fmt, t_strk *strk, long *nb);
void				ft_nbr2struc_2b(char fmt, t_strk *strk, long *nb);
void				ft_str2struc_1(char fmt, va_list *ap, t_strk *strk);
void				ft_str2struc_2(char fmt, t_strk *strk);
void				ft_set_nbrstr(char fmt, va_list *ap, t_strk *strk);

void				ft_put_strktr(t_strk *strk);
void				ft_p_nbr_minus(t_strk *strk);
void				ft_p_nbr_no_minus_b(t_strk *strk);
void				ft_p_nbr_no_minus(t_strk *strk);
void				ft_set_dots_n_spaces(t_strk *strk);
void				ft_set_dots_n_spaces_b(t_strk *strk);
void				ft_printoscreen(t_strk *strk);

void				flags(t_strk *strk);

#endif
