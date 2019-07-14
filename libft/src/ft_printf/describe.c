/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   describe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:44:20 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:46 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			describe(char **format, t_params *prms)
{
	if (**format == '%')
	{
		*format += 1;
		STR = ft_strdup("%");
		return ;
	}
	ft_parse_params(format, prms);
	if (!(ft_strchr("pscidouxXfeE%", TYPE)))
	{
		STR = ft_strdup("");
		return ;
	}
	ft_convert_type(prms);
	ft_apply_flags(prms);
	return ;
}

void			ft_convert_type(t_params *prms)
{
	if (ft_convert_num(prms))
		return ;
	if (ft_convert_string(prms))
		return ;
	if (ft_convert_double(prms))
		return ;
}

/*
**	add to ft_convert_type body to add new type bonyses;
**
**	if (ft_convert_bonus(prms))
**		return ;
*/

void			ft_apply_flags(t_params *prms)
{
	if (TYPE == 's' || TYPE == 'c' || TYPE == 'p' || TYPE == '%')
		ft_edit_psc(prms);
	else
		ft_edit_digits(prms);
	return ;
}
