/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:49:54 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:17:01 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static unsigned int g_k[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void			prepare_shedule(char *block, unsigned int *m);
static void			mix_block(unsigned int *m, t_sha256 *tmp);

void				process_sha256(char *block, t_sha256 *base)
{
	t_sha256		tmp;
	unsigned int	m[64];

	tmp.a = base->a;
	tmp.b = base->b;
	tmp.c = base->c;
	tmp.d = base->d;
	tmp.e = base->e;
	tmp.f = base->f;
	tmp.g = base->g;
	tmp.h = base->h;
	prepare_shedule(block, m);
	mix_block(m, &tmp);
	base->a += tmp.a;
	base->b += tmp.b;
	base->c += tmp.c;
	base->d += tmp.d;
	base->e += tmp.e;
	base->f += tmp.f;
	base->g += tmp.g;
	base->h += tmp.h;
}

static void			prepare_shedule(char *block, unsigned int *m)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		m[i] = ((unsigned char)block[j] << 24) |
			((unsigned char)block[j + 1] << 16) |
			((unsigned char)block[j + 2] << 8) | ((unsigned char)block[j + 3]);
		i++;
		j += 4;
	}
	i = 15;
	while (++i < 64)
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];
}

static void			mix_block(unsigned int *m, t_sha256 *tmp)
{
	int				i;
	unsigned int	t1;
	unsigned int	t2;

	i = -1;
	while (++i < 64)
	{
		t1 = tmp->h + SUM1(tmp->e) + CH(tmp->e, tmp->f, tmp->g) + g_k[i] + m[i];
		t2 = SUM0(tmp->a) + MAJ(tmp->a, tmp->b, tmp->c);
		tmp->h = tmp->g;
		tmp->g = tmp->f;
		tmp->f = tmp->e;
		tmp->e = tmp->d + t1;
		tmp->d = tmp->c;
		tmp->c = tmp->b;
		tmp->b = tmp->a;
		tmp->a = t1 + t2;
	}
}
