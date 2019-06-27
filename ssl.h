/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:04:58 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/25 21:58:29 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

/*
** DEFINES ----------------------------------------
*/

# define IS_FLAG (av[i][1] == 'q' || av[i][1] == 'p' || \
					av[i][1] == 'r' || av[i][1] == 's')

/*
** STRUCTS ----------------------------------------
*/

typedef struct			s_abcd
{
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
}						t_md5;

/*
** FUNCTIONS --------------------------------------
*/

void			process(unsigned int *block, t_md5 *abcd);
void			round_1(unsigned int *x, t_md5 *abcd);
void			round_2(unsigned int *x, t_md5 *abcd);
void			round_3(unsigned int *x, t_md5 *abcd);
void			round_4(unsigned int *x, t_md5 *abcd);

unsigned int				f_md5(unsigned int x, unsigned int y, unsigned int z);
unsigned int				g_md5(unsigned int x, unsigned int y, unsigned int z);
unsigned int				h_md5(unsigned int x, unsigned int y, unsigned int z);
unsigned int				i_md5(unsigned int x, unsigned int y, unsigned int z);
#endif
