/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:35:43 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static char			*convert_shasum(unsigned int *tab, int i, int alg);
static void			initialize(t_sha256 *base, int alg);
static void			reverse_bits(t_glob *glob);

void				sha224(t_glob *glob)
{
	sha256(glob);
}

void				sha256(t_glob *glob)
{
	t_sha256		base;
	unsigned int	tab[8];
	unsigned long	i;

	i = 0;
	initialize(&base, ALG);
	append_512(glob);
	reverse_bits(glob);
	while (i < LEN)
	{
		process_sha256(&MSG[i], &base);
		i += 64;
	}
	tab[0] = base.a;
	tab[1] = base.b;
	tab[2] = base.c;
	tab[3] = base.d;
	tab[4] = base.e;
	tab[5] = base.f;
	tab[6] = base.g;
	tab[7] = base.h;
	HASH = convert_shasum(tab, 8, ALG);
}

/*
**	Initializing nums according sha256 or sha224;
*/

static void			initialize(t_sha256 *base, int alg)
{
	if (alg == 2)
	{
		base->a = 0xc1059ed8;
		base->b = 0x367cd507;
		base->c = 0x3070dd17;
		base->d = 0xf70e5939;
		base->e = 0xffc00b31;
		base->f = 0x68581511;
		base->g = 0x64f98fa7;
		base->h = 0xbefa4fa4;
	}
	else
	{
		base->a = 0x6a09e667;
		base->b = 0xbb67ae85;
		base->c = 0x3c6ef372;
		base->d = 0xa54ff53a;
		base->e = 0x510e527f;
		base->f = 0x9b05688c;
		base->g = 0x1f83d9ab;
		base->h = 0x5be0cd19;
	}
}

/*
**	Reversing last bits of the message;
*/

static void			reverse_bits(t_glob *glob)
{
	char			tmp;
	int				i;
	int				n;

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
**	Converting resulting nums to a string and storing in the struct;
*/

static char			*convert_shasum(unsigned int *tab, int i, int alg)
{
	char			*sum;
	char			*tmp;
	char			*sprint;
	int				n;

	if (alg == 2)
		i--;
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
