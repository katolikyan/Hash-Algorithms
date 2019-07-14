/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:59:03 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:05 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			ft_edit_digits(t_params *prms)
{
	size_t		len;
	char		*tmp;

	len = ft_strlen(prms->str) - (NUM < 0 && TYPE != 'f' ? 1 : 0);
	ft_precision_ox(prms, &len);
	if ((FLAG[3] == 1 || FLAG[4] == 1) &&
			(TYPE == 'f' || TYPE == 'e' || TYPE == 'E'
			? FNUM >= 0 : NUM >= 0) && TYPE != 'u')
	{
		tmp = ft_strjoin((FLAG[4] == 1 ? "+" : " "), prms->str);
		ft_memdel((void **)&(prms->str));
		prms->str = tmp;
	}
	len = ft_strlen(prms->str);
	if (WIDTH > PRECISION && PRECISION != -1 && WIDTH)
		ft_adjust_signs(prms);
	if ((size_t)prms->width > len)
		ft_adjust_width_num(prms, len);
	ft_adjust_signs(prms);
	return ;
}

void			ft_precision_ox(t_params *prms, size_t *len)
{
	if (PRECISION == 0 &&
			(TYPE == 'o' ? FLAG[0] != 1 : 1) &&
			(TYPE == 'f' ? FNUM == 0 : NUM == 0))
		STR[0] = 0;
	if ((*len < (TYPE == 'f' || TYPE == 'e' || TYPE == 'E' ? (size_t)WIDTH :
			(size_t)PRECISION)) && (TYPE == 'f' || TYPE == 'e' || TYPE == 'E'
			? WIDTH != 0 : PRECISION != -1))
	{
		ft_adjust_precision_num(prms, *len);
		*len = ft_strlen(prms->str);
	}
	if ((TYPE == 'o' || TYPE == 'x' || TYPE == 'X') && FLAG[0] == 1 && NUM != 0)
	{
		ft_add_ox(prms);
		*len = ft_strlen(prms->str);
	}
	return ;
}
