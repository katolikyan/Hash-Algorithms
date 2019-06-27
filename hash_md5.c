/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:04:06 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/26 16:17:18 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include "../libft_github/inc/libft.h"
#include <stdio.h>

void				process(unsigned int *block, t_md5 *abcd)
{
	t_md5			old_abcd;

	old_abcd.a = abcd->a;
	old_abcd.b = abcd->b;
	old_abcd.c = abcd->c;
	old_abcd.d = abcd->d;

	round_1(block, abcd);
	round_2(block, abcd);
	round_3(block, abcd);
	round_4(block, abcd);

	abcd->a += old_abcd.a;
	abcd->b += old_abcd.b;
	abcd->c += old_abcd.c;
	abcd->d += old_abcd.d;
//	free(block);
//	printf("\n%u, %u, %u, %u\n", abcd->a, abcd->b, abcd->c, abcd->d);
}


void				round_1(unsigned int *x, t_md5 *abcd)
{
	unsigned int	tmp;

//	a = b + ((a + f_md5(b,c,d) + X[k] + T[i]) <<< s);
	tmp = (abcd->a + f_md5(abcd->b, abcd->c, abcd->d) + x[0] + 0xd76aa478);
	abcd->a = abcd->b + ((tmp << 7) | (tmp >> (32 - 7)));
		tmp = (abcd->d + f_md5(abcd->a, abcd->b, abcd->c) + x[1] + 0xe8c7b756);
	abcd->d = abcd->a + ((tmp << 12) | (tmp >> (32 - 12)));
		tmp = (abcd->c + f_md5(abcd->d, abcd->a, abcd->b) + x[2] + 0x242070db);
	abcd->c = abcd->d + ((tmp << 17) | (tmp >> (32 - 17)));
		tmp = (abcd->b + f_md5(abcd->c, abcd->d, abcd->a) + x[3] + 0xc1bdceee);
	abcd->b = abcd->c + ((tmp << 22) | (tmp >> (32 - 22)));

		tmp = (abcd->a + f_md5(abcd->b, abcd->c, abcd->d) + x[4] + 0xf57c0faf);
	abcd->a = abcd->b + ((tmp << 7) | (tmp >> (32 - 7)));
		tmp = (abcd->d + f_md5(abcd->a, abcd->b, abcd->c) + x[5] + 0x4787c62a);
	abcd->d = abcd->a + ((tmp << 12) | (tmp >> (32 - 12)));
		tmp = (abcd->c + f_md5(abcd->d, abcd->a, abcd->b) + x[6] + 0xa8304613);
	abcd->c = abcd->d + ((tmp << 17) | (tmp >> (32 - 17)));
		tmp = (abcd->b + f_md5(abcd->c, abcd->d, abcd->a) + x[7] + 0xfd469501);
	abcd->b = abcd->c + ((tmp << 22) | (tmp >> (32 - 22)));

		tmp = (abcd->a + f_md5(abcd->b, abcd->c, abcd->d) + x[8] + 0x698098d8);
	abcd->a = abcd->b + ((tmp << 7) | (tmp >> (32 - 7)));
		tmp = (abcd->d + f_md5(abcd->a, abcd->b, abcd->c) + x[9] + 0x8b44f7af);
	abcd->d = abcd->a + ((tmp << 12) | (tmp >> (32 - 12)));
		tmp = (abcd->c + f_md5(abcd->d, abcd->a, abcd->b) + x[10] + 0xffff5bb1);
	abcd->c = abcd->d + ((tmp << 17) | (tmp >> (32 - 17)));
		tmp = (abcd->b + f_md5(abcd->c, abcd->d, abcd->a) + x[11] + 0x895cd7be);
	abcd->b = abcd->c + ((tmp << 22) | (tmp >> (32 - 22)));

		tmp = (abcd->a + f_md5(abcd->b, abcd->c, abcd->d) + x[12] + 0x6b901122);
	abcd->a = abcd->b + ((tmp << 7) | (tmp >> (32 - 7)));
		tmp = (abcd->d + f_md5(abcd->a, abcd->b, abcd->c) + x[13] + 0xfd987193);
	abcd->d = abcd->a + ((tmp << 12) | (tmp >> (32 - 12)));
		tmp = (abcd->c + f_md5(abcd->d, abcd->a, abcd->b) + x[14] + 0xa679438e);
	abcd->c = abcd->d + ((tmp << 17) | (tmp >> (32 - 17)));
		tmp = (abcd->b + f_md5(abcd->c, abcd->d, abcd->a) + x[15] + 0x49b40821);
	abcd->b = abcd->c + ((tmp << 22) | (tmp >> (32 - 22)));

//	printf("\n%u, %u, %u, %u\n", abcd->a, abcd->b, abcd->c, abcd->d);
}

void				round_2(unsigned int *x, t_md5 *abcd)
{
	unsigned int	tmp;

//	a = b + ((a + g_md5(b,c,d) + X[k] + T[i]) <<< s);
		tmp = (abcd->a + g_md5(abcd->b, abcd->c, abcd->d) + x[1] + 0xf61e2562);
	abcd->a = abcd->b + ((tmp << 5) | (tmp >> (32 - 5)));
		tmp = (abcd->d + g_md5(abcd->a, abcd->b, abcd->c) + x[6] + 0xc040b340);
	abcd->d = abcd->a + ((tmp << 9) | (tmp >> (32 - 9)));
		tmp = (abcd->c + g_md5(abcd->d, abcd->a, abcd->b) + x[11] + 0x265e5a51);
	abcd->c = abcd->d + ((tmp << 14) | (tmp >> (32 - 14)));
		tmp = (abcd->b + g_md5(abcd->c, abcd->d, abcd->a) + x[0] + 0xe9b6c7aa);
	abcd->b = abcd->c + ((tmp << 20) | (tmp >> (32 - 20)));

		tmp = (abcd->a + g_md5(abcd->b, abcd->c, abcd->d) + x[5] + 0xd62f105d);
	abcd->a = abcd->b + ((tmp << 5) | (tmp >> (32 - 5)));
		tmp = (abcd->d + g_md5(abcd->a, abcd->b, abcd->c) + x[10] + 0x02441453);
	abcd->d = abcd->a + ((tmp << 9) | (tmp >> (32 - 9)));
		tmp = (abcd->c + g_md5(abcd->d, abcd->a, abcd->b) + x[15] + 0xd8a1e681);
	abcd->c = abcd->d + ((tmp << 14) | (tmp >> (32 - 14)));
		tmp = (abcd->b + g_md5(abcd->c, abcd->d, abcd->a) + x[4] + 0xe7d3fbc8);
	abcd->b = abcd->c + ((tmp << 20) | (tmp >> (32 - 20)));

		tmp = (abcd->a + g_md5(abcd->b, abcd->c, abcd->d) + x[9] + 0x21e1cde6);
	abcd->a = abcd->b + ((tmp << 5) | (tmp >> (32 - 5)));
		tmp = (abcd->d + g_md5(abcd->a, abcd->b, abcd->c) + x[14] + 0xc33707d6);
	abcd->d = abcd->a + ((tmp << 9) | (tmp >> (32 - 9)));
		tmp = (abcd->c + g_md5(abcd->d, abcd->a, abcd->b) + x[3] + 0xf4d50d87);
	abcd->c = abcd->d + ((tmp << 14) | (tmp >> (32 - 14)));
		tmp = (abcd->b + g_md5(abcd->c, abcd->d, abcd->a) + x[8] + 0x455a14ed);
	abcd->b = abcd->c + ((tmp << 20) | (tmp >> (32 - 20)));

		tmp = (abcd->a + g_md5(abcd->b, abcd->c, abcd->d) + x[13] + 0xa9e3e905);
	abcd->a = abcd->b + ((tmp << 5) | (tmp >> (32 - 5)));
		tmp = (abcd->d + g_md5(abcd->a, abcd->b, abcd->c) + x[2] + 0xfcefa3f8);
	abcd->d = abcd->a + ((tmp << 9) | (tmp >> (32 - 9)));
		tmp = (abcd->c + g_md5(abcd->d, abcd->a, abcd->b) + x[7] + 0x676f02d9);
	abcd->c = abcd->d + ((tmp << 14) | (tmp >> (32 - 14)));
		tmp = (abcd->b + g_md5(abcd->c, abcd->d, abcd->a) + x[12] + 0x8d2a4c8a);
	abcd->b = abcd->c + ((tmp << 20) | (tmp >> (32 - 20)));

//	printf("\n%u, %u, %u, %u\n", abcd->a, abcd->b, abcd->c, abcd->d);
}

void				round_3(unsigned int *x, t_md5 *abcd)
{
	unsigned int	tmp;

//	a = b + ((a + h_md5(b,c,d) + X[k] + T[i]) <<< s);
		tmp = (abcd->a + h_md5(abcd->b, abcd->c, abcd->d) + x[5] + 0xfffa3942);
	abcd->a = abcd->b + ((tmp << 4) | (tmp >> (32 - 4)));
		tmp = (abcd->d + h_md5(abcd->a, abcd->b, abcd->c) + x[8] + 0x8771f681);
	abcd->d = abcd->a + ((tmp << 11) | (tmp >> (32 - 11)));
		tmp = (abcd->c + h_md5(abcd->d, abcd->a, abcd->b) + x[11] + 0x6d9d6122);
	abcd->c = abcd->d + ((tmp << 16) | (tmp >> (32 - 16)));
		tmp = (abcd->b + h_md5(abcd->c, abcd->d, abcd->a) + x[14] + 0xfde5380c);
	abcd->b = abcd->c + ((tmp << 23) | (tmp >> (32 - 23)));

		tmp = (abcd->a + h_md5(abcd->b, abcd->c, abcd->d) + x[1] + 0xa4beea44);
	abcd->a = abcd->b + ((tmp << 4) | (tmp >> (32 - 4)));
		tmp = (abcd->d + h_md5(abcd->a, abcd->b, abcd->c) + x[4] + 0x4bdecfa9);
	abcd->d = abcd->a + ((tmp << 11) | (tmp >> (32 - 11)));
		tmp = (abcd->c + h_md5(abcd->d, abcd->a, abcd->b) + x[7] + 0xf6bb4b60);
	abcd->c = abcd->d + ((tmp << 16) | (tmp >> (32 - 16)));
		tmp = (abcd->b + h_md5(abcd->c, abcd->d, abcd->a) + x[10] + 0xbebfbc70);
	abcd->b = abcd->c + ((tmp << 23) | (tmp >> (32 - 23)));

		tmp = (abcd->a + h_md5(abcd->b, abcd->c, abcd->d) + x[13] + 0x289b7ec6);
	abcd->a = abcd->b + ((tmp << 4) | (tmp >> (32 - 4)));
		tmp = (abcd->d + h_md5(abcd->a, abcd->b, abcd->c) + x[0] + 0xeaa127fa);
	abcd->d = abcd->a + ((tmp << 11) | (tmp >> (32 - 11)));
		tmp = (abcd->c + h_md5(abcd->d, abcd->a, abcd->b) + x[3] + 0xd4ef3085);
	abcd->c = abcd->d + ((tmp << 16) | (tmp >> (32 - 16)));
		tmp = (abcd->b + h_md5(abcd->c, abcd->d, abcd->a) + x[6] + 0x04881d05);
	abcd->b = abcd->c + ((tmp << 23) | (tmp >> (32 - 23)));

		tmp = (abcd->a + h_md5(abcd->b, abcd->c, abcd->d) + x[9] + 0xd9d4d039);
	abcd->a = abcd->b + ((tmp << 4) | (tmp >> (32 - 4)));
		tmp = (abcd->d + h_md5(abcd->a, abcd->b, abcd->c) + x[12] + 0xe6db99e5);
	abcd->d = abcd->a + ((tmp << 11) | (tmp >> (32 - 11)));
		tmp = (abcd->c + h_md5(abcd->d, abcd->a, abcd->b) + x[15] + 0x1fa27cf8);
	abcd->c = abcd->d + ((tmp << 16) | (tmp >> (32 - 16)));
		tmp = (abcd->b + h_md5(abcd->c, abcd->d, abcd->a) + x[2] + 0xc4ac5665);
	abcd->b = abcd->c + ((tmp << 23) | (tmp >> (32 - 23)));

//	printf("\n%u, %u, %u, %u\n", abcd->a, abcd->b, abcd->c, abcd->d);
}

void				round_4(unsigned int *x, t_md5 *abcd)
{
	unsigned int	tmp;

//	a = b + ((a + i_md5(b,c,d) + X[k] + T[i]) <<< s);
		tmp = (abcd->a + i_md5(abcd->b, abcd->c, abcd->d) + x[0] + 0xf4292244);
	abcd->a = abcd->b + ((tmp << 6) | (tmp >> (32 - 6)));
		tmp = (abcd->d + i_md5(abcd->a, abcd->b, abcd->c) + x[7] + 0x432aff97);
	abcd->d = abcd->a + ((tmp << 10) | (tmp >> (32 - 10)));
		tmp = (abcd->c + i_md5(abcd->d, abcd->a, abcd->b) + x[14] + 0xab9423a7);
	abcd->c = abcd->d + ((tmp << 15) | (tmp >> (32 - 15)));
		tmp = (abcd->b + i_md5(abcd->c, abcd->d, abcd->a) + x[5] + 0xfc93a039);
	abcd->b = abcd->c + ((tmp << 21) | (tmp >> (32 - 21)));

		tmp = (abcd->a + i_md5(abcd->b, abcd->c, abcd->d) + x[12] + 0x655b59c3);
	abcd->a = abcd->b + ((tmp << 6) | (tmp >> (32 - 6)));
		tmp = (abcd->d + i_md5(abcd->a, abcd->b, abcd->c) + x[3] + 0x8f0ccc92);
	abcd->d = abcd->a + ((tmp << 10) | (tmp >> (32 - 10)));
		tmp = (abcd->c + i_md5(abcd->d, abcd->a, abcd->b) + x[10] + 0xffeff47d);
	abcd->c = abcd->d + ((tmp << 15) | (tmp >> (32 - 15)));
		tmp = (abcd->b + i_md5(abcd->c, abcd->d, abcd->a) + x[1] + 0x85845dd1);
	abcd->b = abcd->c + ((tmp << 21) | (tmp >> (32 - 21)));

		tmp = (abcd->a + i_md5(abcd->b, abcd->c, abcd->d) + x[8] + 0x6fa87e4f);
	abcd->a = abcd->b + ((tmp << 6) | (tmp >> (32 - 6)));
		tmp = (abcd->d + i_md5(abcd->a, abcd->b, abcd->c) + x[15] + 0xfe2ce6e0);
	abcd->d = abcd->a + ((tmp << 10) | (tmp >> (32 - 10)));
		tmp = (abcd->c + i_md5(abcd->d, abcd->a, abcd->b) + x[6] + 0xa3014314);
	abcd->c = abcd->d + ((tmp << 15) | (tmp >> (32 - 15)));
		tmp = (abcd->b + i_md5(abcd->c, abcd->d, abcd->a) + x[13] + 0x4e0811a1);
	abcd->b = abcd->c + ((tmp << 21) | (tmp >> (32 - 21)));

		tmp = (abcd->a + i_md5(abcd->b, abcd->c, abcd->d) + x[4] + 0xf7537e82);
	abcd->a = abcd->b + ((tmp << 6) | (tmp >> (32 - 6)));
		tmp = (abcd->d + i_md5(abcd->a, abcd->b, abcd->c) + x[11] + 0xbd3af235);
	abcd->d = abcd->a + ((tmp << 10) | (tmp >> (32 - 10)));
		tmp = (abcd->c + i_md5(abcd->d, abcd->a, abcd->b) + x[2] + 0x2ad7d2bb);
	abcd->c = abcd->d + ((tmp << 15) | (tmp >> (32 - 15)));
		tmp = (abcd->b + i_md5(abcd->c, abcd->d, abcd->a) + x[9] + 0xeb86d391);
	abcd->b = abcd->c + ((tmp << 21) | (tmp >> (32 - 21)));

//	printf("\n%u, %u, %u, %u\n", abcd->a, abcd->b, abcd->c, abcd->d);
}



unsigned int			f_md5(unsigned int x, unsigned int y, unsigned int z)
{
	int		res;

	res = (x & y) | ((~x) & z);
	return (res);
}

unsigned int			g_md5(unsigned int x, unsigned int y, unsigned int z)
{
	unsigned int		res;

	res = (x & z) | (y & (~z));
	return (res);
}

unsigned int			h_md5(unsigned int x, unsigned int y, unsigned int z)
{
	unsigned int		res;

	res = x ^ y ^ z;
	return (res);
}

unsigned int			i_md5(unsigned int x, unsigned int y, unsigned int z)
{
	unsigned int		res;

	res = y ^ (x | (~z));
	return (res);
}

