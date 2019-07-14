/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:33:58 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void				swap_end_bits(t_glob *glob);
static char				*convert_shasum(unsigned int *tab, int i);

void					sha1(t_glob *glob)
{
	t_sha1				base;
	unsigned int		tab[5];
	unsigned int		i;

	i = 0;
	base.a = 0x67452301;
	base.b = 0xefcdab89;
	base.c = 0x98badcfe;
	base.d = 0x10325476;
	base.e = 0xc3d2e1f0;
	append_512(glob);
	swap_end_bits(glob);
	while (i < LEN)
	{
		process_sha1(&MSG[i], &base);
		i += 64;
	}
	tab[0] = base.a;
	tab[1] = base.b;
	tab[2] = base.c;
	tab[3] = base.d;
	tab[4] = base.e;
	HASH = convert_shasum(tab, 5);
}

/*
**	swap the end of the message.
*/

static void				swap_end_bits(t_glob *glob)
{
	unsigned int		i;
	unsigned int		n;
	char				tmp;

	i = LEN - 8;
	n = LEN - 1;
	while (i < n)
	{
		tmp = MSG[i];
		MSG[i] = MSG[n];
		MSG[n] = tmp;
		i++;
		n--;
	}
}

/*
**	Convert num sum to the string and store it in the struct.
*/

static char				*convert_shasum(unsigned int *tab, int i)
{
	char				*sum;
	char				*tmp;
	char				*sprint;
	int					n;

	n = -1;
	sum = ft_memalloc(2);
	while (++n < i)
	{
		ft_sprintf(&sprint, "%08x", tab[n]);
		tmp = ft_strjoin(sum, sprint);
		free(sum);
		free(sprint);
		sum = tmp;
	}
	return (sum);
}
