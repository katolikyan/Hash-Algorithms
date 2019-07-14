/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:30:52 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
**	Functions creates new string which length is mod 512 or mod 1024 bits.
**
**	First we try to understand how much bits to append to the end to fit
**	everything according to the padding requirements.
**	Then malloc that size + originsl len if message.
*/

void					append_512(t_glob *glob)
{
	unsigned long		len;
	char				*new_msg;

	len = (unsigned long)ft_strlen(MSG);
	if (len % 64 == 0)
		LEN = 64;
	else if (len % 64 < 56)
		LEN = 64 - len % 64;
	else
		LEN = 64 + (64 - len % 64);
	LEN += len;
	new_msg = ft_memalloc(LEN);
	str_copy(new_msg, MSG, len);
	((unsigned char *)new_msg)[len] = 128;
	((unsigned long *)new_msg)[LEN / 8 - 1] = len * 8;
	if (FREEIT)
		free(MSG);
	MSG = new_msg;
}

void					append_1024(t_glob *glob)
{
	unsigned long long	len;
	char				*new_msg;

	len = (unsigned long long)ft_strlen(MSG);
	if (len % 128 == 0)
		LEN = 128;
	else if (len % 128 < 112)
		LEN = 128 - len % 128;
	else
		LEN = 128 + (128 - len % 128);
	LEN += len;
	new_msg = ft_memalloc(LEN);
	str_copy(new_msg, MSG, len);
	((unsigned char *)new_msg)[len] = 128;
	((uintmax_t *)new_msg)[LEN / 8 - 1] = len * 8;
	if (FREEIT)
		free(MSG);
	MSG = new_msg;
}

/*
**	Helper to copy existing message to new malloced string.
*/

void					str_copy(char *dst, char *src, long len)
{
	long				i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		++i;
	}
}
