/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:44:20 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:58:27 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			ft_parse_params(char **format, t_params *prms)
{
	ft_parse_flags(format, prms);
	ft_parse_width(format, prms);
	ft_parse_precision(format, prms);
	ft_parse_lenght(format, prms);
	TYPE = **format;
	*format += 1;
}

void			ft_parse_flags(char **format, t_params *prms)
{
	char		*str;
	int			i;

	str = "#0- +";
	ft_bzero(prms->flags, sizeof(prms->flags));
	i = 0;
	while (str[i])
		FLAG[i++] = 0;
	i = 0;
	while (str[i])
	{
		if (**format == str[i])
		{
			(prms->flags)[i] = 1;
			*format += 1;
			i = 0;
			continue ;
		}
		i++;
	}
	return ;
}

void			ft_parse_width(char **format, t_params *prms)
{
	prms->width = 0;
	if (**format == '*')
	{
		prms->width = va_arg(PARAM, int);
		*format += 1;
		return ;
	}
	if (**format >= '1' && **format <= '9')
		prms->width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
	return ;
}

void			ft_parse_precision(char **format, t_params *prms)
{
	prms->precision = -1;
	if (**format != '.')
		return ;
	*format += 1;
	if (**format == '*')
	{
		prms->precision = va_arg(PARAM, int);
		*format += 1;
		return ;
	}
	prms->precision = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
	return ;
}

void			ft_parse_lenght(char **format, t_params *prms)
{
	prms->lenght = 0;
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
			LENGHT = 2;
		else
			LENGHT = 1;
	}
	else if (**format == 'l')
	{
		if (*(*format + 1) == 'l')
			LENGHT = 4;
		else
			LENGHT = 3;
	}
	else if (**format == 'L')
		LENGHT = 5;
	else if (**format == 'j')
		LENGHT = 7;
	else if (**format == 'z')
		LENGHT = 9;
	if ((LENGHT % 2 == 0) && LENGHT)
		*format += 2;
	if ((LENGHT % 2 == 1) && LENGHT)
		*format += 1;
}

/*
**void			ft_parse_lenght(char **format, t_params *prms)
**{
**	prms->lenght = 0;
**	if (**format == 'h')
**		(*((*format) + 1) == 'h' ? (LENGHT = 2) : (LENGHT = 1));
**	else if (**format == 'l')
**		(*((*format) + 1) == 'l' ? (LENGHT = 4) : (LENGHT = 3));
**	else if (**format == 'L')
**		LENGHT = 5;
**	else if (**format == 'j')
**		LENGHT = 7;
**	else if (**format == 'z')
**		LENGHT = 9;
**	if ((LENGHT % 2 == 0) && LENGHT)
**		*format += 2;
**	if ((LENGHT % 2 == 1) && LENGHT)
**		*format += 1;
**	return ;
**}
*/
