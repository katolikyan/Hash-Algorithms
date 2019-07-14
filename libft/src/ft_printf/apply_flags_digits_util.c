/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_digits_util.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:59:03 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:15 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			ft_adjust_signs(t_params *prms)
{
	int			i;

	i = 0;
	while (STR[i])
	{
		if (NORM && IS_FUCKED)
		{
			STR[i] = STR[0];
			STR[0] = '-';
		}
		else if ((STR[i] == 'x' || STR[i] == 'X') && i > 1 && STR[i - 2] == '0')
		{
			STR[i] = STR[i - 2];
			STR[i - 1] = STR[i - 2];
			STR[0] = '0';
			STR[1] = (TYPE == 'x' ? 'x' : 'X');
		}
		else if (STR[i] == '+' && i != 0 && STR[0] != ' ' &&
				STR[i - 1] != 'e' && STR[i - 1] != 'E')
		{
			STR[i] = STR[0];
			STR[0] = '+';
		}
		i++;
	}
}

void			ft_adjust_precision_num(t_params *prms, size_t len)
{
	char		*zero;
	char		*tmp;
	size_t		spase;

	spase = (TYPE == 'e' || TYPE == 'E' || TYPE == 'f' ? WIDTH : PRECISION);
	zero = ft_memalloc(spase - len + 1);
	ft_memset(zero, '0', spase - len);
	tmp = ft_strjoin(zero, prms->str);
	ft_memdel((void **)&(prms->str));
	ft_memdel((void **)&zero);
	prms->str = tmp;
}

void			ft_add_ox(t_params *prms)
{
	char		*tmp;

	if (TYPE == 'o')
	{
		tmp = ft_strjoin("0", prms->str);
		ft_memdel((void **)&(prms->str));
		prms->str = tmp;
	}
	else
	{
		tmp = ft_strjoin((TYPE == 'x' ? "0x" : "0X"), prms->str);
		ft_memdel((void **)&(prms->str));
		prms->str = tmp;
	}
	return ;
}

void			ft_adjust_width_num(t_params *prms, size_t len)
{
	int			i;
	char		*app;
	char		*tmp;

	i = prms->width - len;
	if (!(app = ft_memalloc(i + 1)))
		return ;
	ft_memset(app,
			(FLAG[1] == 1 && FLAG[2] == 0 &&
			((prms->precision > prms->width) || prms->precision == -1)
			? '0' : ' '), i);
	if (FLAG[2] == 1)
		tmp = ft_strjoin(prms->str, app);
	else
		tmp = ft_strjoin(app, prms->str);
	ft_memdel((void **)&(prms->str));
	ft_memdel((void **)&app);
	prms->str = tmp;
	return ;
}
