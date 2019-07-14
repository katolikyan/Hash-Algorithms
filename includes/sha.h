/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:42:16 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:32:34 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
# define SHA_H

/*
**	DEFINES -----------------------------------------------------
*/

/*
**	GENERAL
*/

# define SHR(x, n)	(x >> n)
# define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define PARITY(x,y,z) (x ^ y ^ z)

/*
**	SHA256
*/

# define ROTL(x, n)	(((x) << (n)) | ((x) >> (32 - (n))))
# define ROTR(x, n)	(((x) >> (n)) | ((x) << (32 - (n))))
# define SUM0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
# define SUM1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
# define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
# define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

/*
**	SHA512
*/

# define ROTL2(x, n)	(((x) << (n)) | ((x) >> (64 - (n))))
# define ROTR2(x, n)	(((x) >> (n)) | ((x) << (64 - (n))))
# define SUM02(x) (ROTR2(x, 28) ^ ROTR2(x, 34) ^ ROTR2(x, 39))
# define SUM12(x) (ROTR2(x, 14) ^ ROTR2(x, 18) ^ ROTR2(x, 41))
# define SIG02(x) (ROTR2(x, 1) ^ ROTR2(x, 8) ^ SHR(x, 7))
# define SIG12(x) (ROTR2(x, 19) ^ ROTR2(x, 61) ^ SHR(x, 6))

/*
**	STRUCTS -----------------------------------------------------
*/

typedef struct		s_sha1
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
}					t_sha1;

typedef struct		s_sha256
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
}					t_sha256;

typedef struct		s_sha512
{
	unsigned long	a;
	unsigned long	b;
	unsigned long	c;
	unsigned long	d;
	unsigned long	e;
	unsigned long	f;
	unsigned long	g;
	unsigned long	h;
}					t_sha512;

/*
**	FUNCTIONS -----------------------------------------------------
*/

void				sha1(t_glob *glob);
void				process_sha1(char *block, t_sha1 *base);
void				sha256(t_glob *glob);
void				sha224(t_glob *glob);
void				process_sha256(char *block, t_sha256 *base);
void				sha512(t_glob *glob);
void				process_sha512(char *block, t_sha512 *base);

#endif
