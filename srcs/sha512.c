/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:37:21 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char				*convert_shasum_long(unsigned long *tab, int i);
static void				reverse_end_bits(t_glob *glob);
static void				cicle_base(t_glob *glob, t_sha512 *base);

void					sha512(t_glob *glob)
{
	t_sha512			base;
	unsigned long		tab[8];

	base.a = 0x6a09e667f3bcc908;
	base.b = 0xbb67ae8584caa73b;
	base.c = 0x3c6ef372fe94f82b;
	base.d = 0xa54ff53a5f1d36f1;
	base.e = 0x510e527fade682d1;
	base.f = 0x9b05688c2b3e6c1f;
	base.g = 0x1f83d9abfb41bd6b;
	base.h = 0x5be0cd19137e2179;
	append_1024(glob);
	reverse_end_bits(glob);
	cicle_base(glob, &base);
	tab[0] = base.a;
	tab[1] = base.b;
	tab[2] = base.c;
	tab[3] = base.d;
	tab[4] = base.e;
	tab[5] = base.f;
	tab[6] = base.g;
	tab[7] = base.h;
	HASH = convert_shasum_long(tab, 8);
}

/*
** Swaping the end of message to the little endian because it is a num;
*/

static void				reverse_end_bits(t_glob *glob)
{
	char				tmp;
	unsigned long		i;
	unsigned long		n;

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
** Mixing every piece 1024 bit block of message;
*/

static void				cicle_base(t_glob *glob, t_sha512 *base)
{
	unsigned long		i;

	i = 0;
	while (i < LEN)
	{
		process_sha512(&MSG[i], base);
		i += 128;
	}
}

/*
** Convert base nums result to the hashsum;
*/

static char				*convert_shasum_long(unsigned long *tab, int i)
{
	char				*sum;
	char				*tmp;
	char				*sprint;
	int					n;

	n = -1;
	sum = ft_memalloc(2);
	while (++n < i)
	{
		ft_sprintf(&sprint, "%016lx", tab[n]);
		tmp = ft_strjoin(sum, sprint);
		free(sum);
		free(sprint);
		sum = tmp;
	}
	return (sum);
}
