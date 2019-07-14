/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:54:53 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:55:41 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ---------------------------------INCLUDES-----------------------------------
*/

# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

/*
** -------------------------------DATA STRUCTS---------------------------------
*/

/*
**	description:
**
**	flags			[0] == '#', [1] == '0', [2] == '-', [3] == ' ', [4] == '+'.
**	lenght 			1 == h, 2 == hh, 3 == l, 4 == ll, 5 == L, 7 == j, 9 == z.
*/
typedef struct		s_params
{
	va_list			params;
	short			flags[5];
	int				width;
	int				precision;
	int				lenght;
	char			type;
	char			*str;
	char			c;
	intmax_t		num;
	long double		fnum;
}					t_params;

/*
** ---------------------------------DEFINES------------------------------------
*/

# define PARAM 		(prms->params)
# define FLAG		(prms->flags)
# define WIDTH		(prms->width)
# define PRECISION	(prms->precision)
# define LENGHT		(prms->lenght)
# define TYPE 		(prms->type)
# define STR		(prms->str)
# define ZEROC		(prms->c)
# define NUM		(prms->num)
# define FNUM		(prms->fnum)

# define NORM		STR[i] == '-' && i != 0 && STR[0] != ' '
# define IS_FUCKED	STR[i - 1] != 'e' && STR[i - 1] != 'E'

/*
** --------------------------------PROTOTPES-----------------------------------
*/

int					ft_printf(const char *format, ...);
int					ft_sprintf(char **str, const char *format, ...);
void				ft_anlz(const char **f, t_params *prms, int *n, int *len);
char				*ft_strnjoin_r(char **s1, char *s2, int n);
char				*ft_strjoin_r(char **s1, char *s2);
size_t				ft_free_printf(t_params **prms, char **print);

void				describe(char **s, t_params *prms);
void				ft_parse_params(char **format, t_params *prms);
void				ft_parse_flags(char **format, t_params *prms);
void				ft_parse_width(char **format, t_params *prms);
void				ft_parse_precision(char **format, t_params *prms);
void				ft_parse_lenght(char **format, t_params *prms);

void				ft_convert_type(t_params *prms);
int					ft_convert_num(t_params *prms);
int					ft_convert_string(t_params *prms);
void				ft_convert_c(t_params *prms);
int					ft_convert_double(t_params *prms);
void				ft_cast_lenght_di(t_params *prms);
void				ft_cast_lenght_ouxx(t_params *prms);
void				ft_cast_lenght_f(t_params *prms);

void				ft_apply_flags(t_params *prms);
void				ft_edit_psc(t_params *prms);
void				ft_adjust_precision(t_params *prms);
void				ft_adjust_width(t_params *prms, size_t len);
void				ft_edit_digits(t_params *prms);
void				ft_precision_ox(t_params *prms, size_t *len);
void				ft_adjust_precision_num(t_params *prms, size_t len);
void				ft_adjust_width_num(t_params *prms, size_t len);
void				ft_add_ox(t_params *prms);

void				ft_analize_str(t_params *prms);
void				ft_add_sign(t_params *prms);
void				ft_adjust_signs(t_params *prms);

#endif
