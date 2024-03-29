/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:44:28 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/03 22:55:56 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t			ft_strlen(const char *s)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[n])
	{
		n++;
		i++;
	}
	return (i);
}
