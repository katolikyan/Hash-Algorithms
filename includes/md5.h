/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:24:50 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/13 23:00:05 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

/*
** DEFINES -----------------------------------------------------
*/

# define FMD5(x, y, z)	((x & y) | ((~x) & z))
# define GMD5(x, y, z)	((x & z) | (y & (~z)))
# define HMD5(x, y, z)	(x ^ y ^ z)
# define IMD5(x, y, z)	(y ^ (x | (~z)))
# define A	(abcd->a)
# define B	(abcd->b)
# define C	(abcd->c)
# define D	(abcd->d)

/*
** STRUCTS  -----------------------------------------------------
*/

typedef struct				s_abcd
{
	unsigned int			a;
	unsigned int			b;
	unsigned int			c;
	unsigned int			d;
}							t_md5;

/*
** FUNCTIONS  -----------------------------------------------------
*/

void						md5(t_glob *glob);
char						*convert_hash(t_md5 *abcd);
void						process(unsigned int *block, t_md5 *abcd);
void						round_1(unsigned int *x, t_md5 *abcd);
void						round_2(unsigned int *x, t_md5 *abcd);
void						round_3(unsigned int *x, t_md5 *abcd);
void						round_4(unsigned int *x, t_md5 *abcd);

#endif
