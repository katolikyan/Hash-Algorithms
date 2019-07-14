/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixer_md5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:04:06 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 01:56:12 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void				process(unsigned int *block, t_md5 *abcd)
{
	t_md5			old_abcd;

	old_abcd.a = A;
	old_abcd.b = B;
	old_abcd.c = C;
	old_abcd.d = D;
	round_1(block, abcd);
	round_2(block, abcd);
	round_3(block, abcd);
	round_4(block, abcd);
	A += old_abcd.a;
	B += old_abcd.b;
	C += old_abcd.c;
	D += old_abcd.d;
}

void				round_1(unsigned int *x, t_md5 *abcd)
{
	A = B + ROTL((A + FMD5(B, C, D) + x[0] + 0xd76aa478), 7);
	D = A + ROTL((D + FMD5(A, B, C) + x[1] + 0xe8c7b756), 12);
	C = D + ROTL((C + FMD5(D, A, B) + x[2] + 0x242070db), 17);
	B = C + ROTL((B + FMD5(C, D, A) + x[3] + 0xc1bdceee), 22);
	A = B + ROTL((A + FMD5(B, C, D) + x[4] + 0xf57c0faf), 7);
	D = A + ROTL((D + FMD5(A, B, C) + x[5] + 0x4787c62a), 12);
	C = D + ROTL((C + FMD5(D, A, B) + x[6] + 0xa8304613), 17);
	B = C + ROTL((B + FMD5(C, D, A) + x[7] + 0xfd469501), 22);
	A = B + ROTL((A + FMD5(B, C, D) + x[8] + 0x698098d8), 7);
	D = A + ROTL((D + FMD5(A, B, C) + x[9] + 0x8b44f7af), 12);
	C = D + ROTL((C + FMD5(D, A, B) + x[10] + 0xffff5bb1), 17);
	B = C + ROTL((B + FMD5(C, D, A) + x[11] + 0x895cd7be), 22);
	A = B + ROTL((A + FMD5(B, C, D) + x[12] + 0x6b901122), 7);
	D = A + ROTL((D + FMD5(A, B, C) + x[13] + 0xfd987193), 12);
	C = D + ROTL((C + FMD5(D, A, B) + x[14] + 0xa679438e), 17);
	B = C + ROTL((B + FMD5(C, D, A) + x[15] + 0x49b40821), 22);
}

void				round_2(unsigned int *x, t_md5 *abcd)
{
	A = B + ROTL((A + GMD5(B, C, D) + x[1] + 0xf61e2562), 5);
	D = A + ROTL((D + GMD5(A, B, C) + x[6] + 0xc040b340), 9);
	C = D + ROTL((C + GMD5(D, A, B) + x[11] + 0x265e5a51), 14);
	B = C + ROTL((B + GMD5(C, D, A) + x[0] + 0xe9b6c7aa), 20);
	A = B + ROTL((A + GMD5(B, C, D) + x[5] + 0xd62f105d), 5);
	D = A + ROTL((D + GMD5(A, B, C) + x[10] + 0x02441453), 9);
	C = D + ROTL((C + GMD5(D, A, B) + x[15] + 0xd8a1e681), 14);
	B = C + ROTL((B + GMD5(C, D, A) + x[4] + 0xe7d3fbc8), 20);
	A = B + ROTL((A + GMD5(B, C, D) + x[9] + 0x21e1cde6), 5);
	D = A + ROTL((D + GMD5(A, B, C) + x[14] + 0xc33707d6), 9);
	C = D + ROTL((C + GMD5(D, A, B) + x[3] + 0xf4d50d87), 14);
	B = C + ROTL((B + GMD5(C, D, A) + x[8] + 0x455a14ed), 20);
	A = B + ROTL((A + GMD5(B, C, D) + x[13] + 0xa9e3e905), 5);
	D = A + ROTL((D + GMD5(A, B, C) + x[2] + 0xfcefa3f8), 9);
	C = D + ROTL((C + GMD5(D, A, B) + x[7] + 0x676f02d9), 14);
	B = C + ROTL((B + GMD5(C, D, A) + x[12] + 0x8d2a4c8a), 20);
}

void				round_3(unsigned int *x, t_md5 *abcd)
{
	A = B + ROTL((A + HMD5(B, C, D) + x[5] + 0xfffa3942), 4);
	D = A + ROTL((D + HMD5(A, B, C) + x[8] + 0x8771f681), 11);
	C = D + ROTL((C + HMD5(D, A, B) + x[11] + 0x6d9d6122), 16);
	B = C + ROTL((B + HMD5(C, D, A) + x[14] + 0xfde5380c), 23);
	A = B + ROTL((A + HMD5(B, C, D) + x[1] + 0xa4beea44), 4);
	D = A + ROTL((D + HMD5(A, B, C) + x[4] + 0x4bdecfa9), 11);
	C = D + ROTL((C + HMD5(D, A, B) + x[7] + 0xf6bb4b60), 16);
	B = C + ROTL((B + HMD5(C, D, A) + x[10] + 0xbebfbc70), 23);
	A = B + ROTL((A + HMD5(B, C, D) + x[13] + 0x289b7ec6), 4);
	D = A + ROTL((D + HMD5(A, B, C) + x[0] + 0xeaa127fa), 11);
	C = D + ROTL((C + HMD5(D, A, B) + x[3] + 0xd4ef3085), 16);
	B = C + ROTL((B + HMD5(C, D, A) + x[6] + 0x04881d05), 23);
	A = B + ROTL((A + HMD5(B, C, D) + x[9] + 0xd9d4d039), 4);
	D = A + ROTL((D + HMD5(A, B, C) + x[12] + 0xe6db99e5), 11);
	C = D + ROTL((C + HMD5(D, A, B) + x[15] + 0x1fa27cf8), 16);
	B = C + ROTL((B + HMD5(C, D, A) + x[2] + 0xc4ac5665), 23);
}

void				round_4(unsigned int *x, t_md5 *abcd)
{
	A = B + ROTL((A + IMD5(B, C, D) + x[0] + 0xf4292244), 6);
	D = A + ROTL((D + IMD5(A, B, C) + x[7] + 0x432aff97), 10);
	C = D + ROTL((C + IMD5(D, A, B) + x[14] + 0xab9423a7), 15);
	B = C + ROTL((B + IMD5(C, D, A) + x[5] + 0xfc93a039), 21);
	A = B + ROTL((A + IMD5(B, C, D) + x[12] + 0x655b59c3), 6);
	D = A + ROTL((D + IMD5(A, B, C) + x[3] + 0x8f0ccc92), 10);
	C = D + ROTL((C + IMD5(D, A, B) + x[10] + 0xffeff47d), 15);
	B = C + ROTL((B + IMD5(C, D, A) + x[1] + 0x85845dd1), 21);
	A = B + ROTL((A + IMD5(B, C, D) + x[8] + 0x6fa87e4f), 6);
	D = A + ROTL((D + IMD5(A, B, C) + x[15] + 0xfe2ce6e0), 10);
	C = D + ROTL((C + IMD5(D, A, B) + x[6] + 0xa3014314), 15);
	B = C + ROTL((B + IMD5(C, D, A) + x[13] + 0x4e0811a1), 21);
	A = B + ROTL((A + IMD5(B, C, D) + x[4] + 0xf7537e82), 6);
	D = A + ROTL((D + IMD5(A, B, C) + x[11] + 0xbd3af235), 10);
	C = D + ROTL((C + IMD5(D, A, B) + x[2] + 0x2ad7d2bb), 15);
	B = C + ROTL((B + IMD5(C, D, A) + x[9] + 0xeb86d391), 21);
}
