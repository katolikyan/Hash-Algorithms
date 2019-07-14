/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:20:08 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:57:56 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_params	*prms;
	int			len;
	int			n;

	len = 0;
	if (!(prms = ft_memalloc(sizeof(t_params))))
		return (0);
	va_start(prms->params, format);
	ft_anlz(&format, prms, &n, &len);
	va_end(prms->params);
	ft_memdel((void **)&prms);
	return (len);
}

void			ft_anlz(const char **f, t_params *prms, int *n, int *len)
{
	while (**f)
	{
		*n = 0;
		while ((*f)[*n] != '%' && (*f)[*n] != 0)
			*n += 1;
		if (*n)
			write(1, *f, *n);
		*len += *n;
		*f += *n;
		if (**f)
		{
			*f += 1;
			describe((char **)f, prms);
			*n = ft_strlen(STR);
			if (*n)
				write(1, STR, *n);
			*len += *n;
			if (prms->c)
			{
				write(1, "\0", 1);
				*len += 1;
			}
			ft_memdel((void **)&STR);
		}
	}
}

/*
** *******************  NOT NORMED BUT READABLE (╯°□°）╯︵ ǝɯɹou  **************
**
**int				ft_printf(const char *format, ...)
**{
**	t_params	*prms;
**	int			len;
**	int			n;
**
**	len = 0;
**	if (!(prms = ft_memalloc(sizeof(t_params))))
**		return (0);
**	prms->str = NULL;
**	va_start(prms->params, format);
**	ft_anlz(&format, prms, &n, &len);
**	while (*format)
**	{
**		n = 0;
**		while (format[n] != '%' && format[n])
**			n++;
**		if (n)
**			write(1, format, n);
**		len += n;
**		format += n;
**		if (*format)
**		{
**			format += 1;
**			describe((char **)&format, prms);
**			n = ft_strlen(STR);
**			if (n)
**				write(1, STR, n);
**			len += n;
**			if (prms->c)
**			{
**				write(1, "\0", 1);
**				len += 1;
**			}
**			ft_memdel((void **)&STR);
**		}
**	}
**	va_end(prms->params);
**	ft_memdel((void **)&prms);
**	return (len);
**}
*/
