/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:18:12 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:27 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int				ft_convert_num(t_params *prms)
{
	if (TYPE == 'i' || TYPE == 'd')
	{
		ft_cast_lenght_di(prms);
		prms->str = ft_imaxtoa_base(NUM, 10, 0);
		return (1);
	}
	else if (TYPE == 'o' || TYPE == 'u')
	{
		ft_cast_lenght_di(prms);
		prms->str = ft_uimaxtoa_base(NUM, (TYPE == 'o' ? 8 : 10), 0);
		return (1);
	}
	else if (TYPE == 'x' || TYPE == 'X')
	{
		ft_cast_lenght_di(prms);
		prms->str = ft_uimaxtoa_base(NUM, 16, (TYPE == 'x' ? 0 : 1));
		return (1);
	}
	return (0);
}

void			ft_cast_lenght_di(t_params *prms)
{
	if (TYPE == 'd' || TYPE == 'i')
	{
		if (prms->lenght == 0)
			NUM = (int)(va_arg(PARAM, int));
		else if (prms->lenght == 1)
			NUM = (short)(va_arg(PARAM, int));
		else if (prms->lenght == 2)
			NUM = (signed char)(va_arg(PARAM, int));
		else if (prms->lenght == 3)
			NUM = (long)(va_arg(PARAM, long));
		else if (prms->lenght == 4)
			NUM = (long long)(va_arg(PARAM, long long));
		else if (prms->lenght == 7)
			NUM = (intmax_t)(va_arg(PARAM, intmax_t));
		else if (prms->lenght == 9)
			NUM = (size_t)(va_arg(PARAM, size_t));
	}
	else
		ft_cast_lenght_ouxx(prms);
}

void			ft_cast_lenght_ouxx(t_params *prms)
{
	if (TYPE == 'o' || TYPE == 'u' || TYPE == 'x' || TYPE == 'X')
	{
		if (prms->lenght == 0)
			NUM = (unsigned int)(va_arg(PARAM, unsigned int));
		else if (prms->lenght == 1)
			NUM = (unsigned short)(va_arg(PARAM, unsigned int));
		else if (prms->lenght == 2)
			NUM = (unsigned char)(va_arg(PARAM, unsigned int));
		else if (prms->lenght == 3)
			NUM = (unsigned long)(va_arg(PARAM, unsigned long));
		else if (prms->lenght == 4)
			NUM = (unsigned long long)(va_arg(PARAM, unsigned long long));
		else if (prms->lenght == 7)
			NUM = (uintmax_t)(va_arg(PARAM, uintmax_t));
		else if (prms->lenght == 9)
			NUM = (size_t)(va_arg(PARAM, size_t));
	}
}

int				ft_convert_string(t_params *prms)
{
	char		*ch;

	if (TYPE == 's')
	{
		if (!(ch = va_arg(PARAM, char *)))
			prms->str = ft_strdup("(null)");
		else
			prms->str = ft_strdup(ch);
		return (1);
	}
	else if (TYPE == 'c')
	{
		ft_convert_c(prms);
		return (1);
	}
	else if (TYPE == 'p')
	{
		ch = ft_uimaxtoa_base((uintmax_t)(va_arg(PARAM, void *)), 16, 0);
		prms->str = ft_strjoin("0x", ch);
		ft_memdel((void **)&ch);
		return (1);
	}
	if (TYPE == '%' ? prms->str = ft_strdup("%") : 0)
		return (1);
	return (0);
}

void			ft_convert_c(t_params *prms)
{
	prms->str = ft_memalloc(2);
	if (!(STR[0] = va_arg(PARAM, int)))
		prms->c = 1;
	if (prms->c && WIDTH)
		WIDTH -= 1;
	return ;
}
