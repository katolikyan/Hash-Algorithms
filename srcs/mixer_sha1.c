/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixer_sha256.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:10:55 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static const unsigned int g_k[4] =
{
	0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6
};

static void				prep_shedule(unsigned int *m, char *block);
static void				mix_1_2(unsigned int *t1, int *i,
								unsigned int *m, t_sha1 *tmp);
static void				mix_3_4(unsigned int *t1, int *i,
								unsigned int *m, t_sha1 *tmp);

void					process_sha1(char *block, t_sha1 *base)
{
	t_sha1				tmp;
	unsigned int		m[80];
	unsigned int		t1;
	int					i;

	i = 0;
	t1 = 0;
	tmp.a = base->a;
	tmp.b = base->b;
	tmp.c = base->c;
	tmp.d = base->d;
	tmp.e = base->e;
	prep_shedule(m, block);
	mix_1_2(&t1, &i, m, &tmp);
	mix_3_4(&t1, &i, m, &tmp);
	base->a += tmp.a;
	base->b += tmp.b;
	base->c += tmp.c;
	base->d += tmp.d;
	base->e += tmp.e;
}

/*
** preparation of the message block.
*/

static void				prep_shedule(unsigned int *m, char *block)
{
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		m[i] = ((unsigned char)block[j] << 24) |
			((unsigned char)block[j + 1] << 16) |
			((unsigned char)block[j + 2] << 8) | ((unsigned char)block[j + 3]);
		j += 4;
		i++;
	}
	i = 15;
	while (++i < 80)
		m[i] = ROTL((m[i - 3] ^ m[i - 8] ^ m[i - 14] ^ m[i - 16]), 1);
}

/*
** rounds
*/

static void				mix_1_2(unsigned int *t1, int *i,
								unsigned int *m, t_sha1 *tmp)
{
	while (*i < 20)
	{
		*t1 = ROTL(tmp->a, 5) + CH(tmp->b, tmp->c, tmp->d)
			+ tmp->e + g_k[0] + m[*i];
		tmp->e = tmp->d;
		tmp->d = tmp->c;
		tmp->c = ROTL(tmp->b, 30);
		tmp->b = tmp->a;
		tmp->a = *t1;
		*i += 1;
	}
	while (*i < 40)
	{
		*t1 = ROTL(tmp->a, 5) + PARITY(tmp->b, tmp->c, tmp->d)
			+ tmp->e + g_k[1] + m[*i];
		tmp->e = tmp->d;
		tmp->d = tmp->c;
		tmp->c = ROTL(tmp->b, 30);
		tmp->b = tmp->a;
		tmp->a = *t1;
		*i += 1;
	}
}

static void				mix_3_4(unsigned int *t1, int *i,
								unsigned int *m, t_sha1 *tmp)
{
	while (*i < 60)
	{
		*t1 = ROTL(tmp->a, 5) + MAJ(tmp->b, tmp->c, tmp->d)
			+ tmp->e + g_k[2] + m[*i];
		tmp->e = tmp->d;
		tmp->d = tmp->c;
		tmp->c = ROTL(tmp->b, 30);
		tmp->b = tmp->a;
		tmp->a = *t1;
		*i += 1;
	}
	while (*i < 80)
	{
		*t1 = ROTL(tmp->a, 5) + PARITY(tmp->b, tmp->c, tmp->d)
			+ tmp->e + g_k[3] + m[*i];
		tmp->e = tmp->d;
		tmp->d = tmp->c;
		tmp->c = ROTL(tmp->b, 30);
		tmp->b = tmp->a;
		tmp->a = *t1;
		*i += 1;
	}
}
