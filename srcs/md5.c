/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:46:34 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/14 01:05:43 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
**	Function initialize start values and appends message according to the
**	hashing functions requirements.
*/

void				md5(t_glob *glob)
{
	t_md5			abcd;
	unsigned long	i;

	abcd.a = 0x67452301;
	abcd.b = 0xefcdab89;
	abcd.c = 0x98badcfe;
	abcd.d = 0x10325476;
	append_512(glob);
	i = 0;
	while (i < LEN)
	{
		process((unsigned int *)&MSG[i], &abcd);
		i += 64;
	}
	HASH = convert_hash(&abcd);
}

/*
**	Convert hash numbers to the string and stores it in the struct.
*/

char				*convert_hash(t_md5 *abcd)
{
	char			*sum;
	char			*tmp;
	char			*sprint;
	int				n;

	n = 0;
	sum = ft_memalloc(2);
	while (n++ < 4)
	{
		ft_sprintf(&sprint, "%02x%02x%02x%02x", (unsigned char)(abcd->a),
				(unsigned char)(abcd->a >> 8), (unsigned char)(abcd->a >> 16),
				(unsigned char)(abcd->a >> 24));
		tmp = ft_strjoin(sum, sprint);
		free(sum);
		free(sprint);
		sum = tmp;
		if (n == 1)
			abcd->a = abcd->b;
		else if (n == 2)
			abcd->a = abcd->c;
		else
			abcd->a = abcd->d;
	}
	return (sum);
}
