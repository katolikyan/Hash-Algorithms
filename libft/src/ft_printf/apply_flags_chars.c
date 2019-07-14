/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:59:03 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:56:35 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			ft_edit_psc(t_params *prms)
{
	size_t		len;

	len = ft_strlen(prms->str);
	if (len > (size_t)prms->precision && prms->precision != -1 && TYPE == 's')
	{
		ft_adjust_precision(prms);
		len = ft_strlen(prms->str);
	}
	if ((size_t)prms->width > len)
		ft_adjust_width(prms, len);
	return ;
}

void			ft_adjust_precision(t_params *prms)
{
	char		*ch;

	ch = ft_strndup(prms->str, prms->precision);
	ft_memdel((void **)&(prms->str));
	prms->str = ch;
	return ;
}

void			ft_adjust_width(t_params *prms, size_t len)
{
	int			i;
	char		*app;
	char		*tmp;

	i = prms->width - len;
	if (!(app = ft_memalloc(i + 1)))
		return ;
	ft_memset(app, ' ', i);
	if (FLAG[2] == 1)
		tmp = ft_strjoin(prms->str, app);
	else
		tmp = ft_strjoin(app, prms->str);
	ft_memdel((void **)&(prms->str));
	ft_memdel((void **)&app);
	prms->str = tmp;
}
