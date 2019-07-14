/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:20:08 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/22 18:58:10 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int				ft_sprintf(char **str, const char *format, ...)
{
	t_params	*prms;
	int			n;

	if (!(prms = ft_memalloc(sizeof(t_params))))
		return (0);
	if (!(*str = ft_memalloc(1)))
		return (0);
	prms->str = NULL;
	va_start(prms->params, format);
	while (*format)
	{
		n = 0;
		while (format[n] != '%' && format[n])
			n++;
		*str = ft_strnjoin_r(str, (char *)format, n);
		format += n;
		if (*format)
		{
			format++;
			describe((char **)&format, prms);
			*str = ft_strjoin_r(str, STR);
			ft_memdel((void **)&prms->str);
		}
	}
	return (ft_free_printf(&prms, str));
}

char			*ft_strnjoin_r(char **s1, char *s2, int n)
{
	char		*new;

	if (!s1 || !s2 || !(new = ft_memalloc((ft_strlen(*s1) + n + 1))))
		return (0);
	new = ft_strcat(new, *s1);
	new = ft_strncat(new, s2, n);
	ft_memdel((void **)(s1));
	return (new);
}

char			*ft_strjoin_r(char **s1, char *s2)
{
	char		*new;

	if (!s1 || !s2 ||
			!(new = ft_memalloc((ft_strlen(*s1) + ft_strlen(s2) + 1))))
		return (0);
	new = ft_strcat(new, *s1);
	new = ft_strcat(new, s2);
	ft_memdel((void **)(s1));
	return (new);
}

size_t			ft_free_printf(t_params **prms, char **print)
{
	size_t		len;

	len = ft_strlen(*print);
	va_end((*prms)->params);
	ft_memdel((void **)prms);
	return (len);
}
