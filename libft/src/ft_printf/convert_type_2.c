/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convety_type_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 23:31:12 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:37 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int					ft_convert_double(t_params *prms)
{
	if (TYPE == 'f')
	{
		ft_cast_lenght_f(prms);
		prms->str = ft_ftoa(FNUM,
				(prms->precision == -1 ? 6 : prms->precision));
		return (1);
	}
	if (TYPE == 'e' || TYPE == 'E')
	{
		ft_cast_lenght_f(prms);
		if (TYPE == 'e')
		{
			prms->str = ft_ftoe(FNUM,
				(prms->precision == -1 ? 6 : prms->precision));
		}
		else
		{
			prms->str = ft_ftobige(FNUM,
				(prms->precision == -1 ? 6 : prms->precision));
		}
		return (1);
	}
	return (0);
}

void				ft_cast_lenght_f(t_params *prms)
{
	if (prms->lenght == 0)
		FNUM = (double)(va_arg(PARAM, double));
	else if (prms->lenght == 3 || prms->lenght == 5)
		FNUM = (long double)(va_arg(PARAM, long double));
}
