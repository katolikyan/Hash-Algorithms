/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:12:53 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/14 00:15:16 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int				main(int ac, char **av)
{
	t_glob		*glob;

	glob = ft_memalloc(sizeof(t_glob));
	AV = av;
	AC = ac;
	CRNT = 2;
	if (ac < 2)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	find_alg(glob);
	parce_flags(glob);
	hash_params(glob);
	free(glob);
	return (0);
}

/*
**	Functions reads first arg which is always a hashing algorithm.
**	If there is no such option - error printed, exit programm.
**	If option is exist - stored alg number in struct variable.
**
** 	void	upper(t_glob *glob)
**	Helper function to make output message look like original implementation
*/

void			find_alg(t_glob *glob)
{
	int			i;
	char		*hash[] = {"md5", "sha256", "sha224", "sha512", "sha1"};

	i = 0;
	while (i < ALG_NUM)
	{
		if (ft_strcmp(AV[1], hash[i]) == 0)
		{
			ALG = i;
			break ;
		}
		else
			i++;
	}
	if (i == ALG_NUM)
	{
		ft_printf("%s is not a hashign algorithm or it is not", AV[1]);
		ft_printf("presented in this implementtion yet.\n");
		free(glob);
		exit(0);
	}
	upper(glob);
}

void			upper(t_glob *glob)
{
	int			i;

	i = 0;
	while (AV[1][i])
	{
		if (AV[1][i] <= 'z' && AV[1][i] >= 'a')
			AV[1][i] -= 32;
		i++;
	}
}

/*
** Parsing flags and storing them in struct.
** If -s flag provided - stop parsing.
**
** Note: This implementation egnores flags repeating exept -s
*/

void			parce_flags(t_glob *glob)
{
	while (CRNT < AC && (ft_strlen(AV[CRNT]) == 2))
	{
		if (AV[CRNT][0] == '-' && IS_FLAG)
		{
			if (FLAGS[(int)AV[CRNT][1]] == 1)
				ft_printf("./ft_ssl: flag -%c provided. flag is ignored.\n",
						AV[CRNT][1]);
			FLAGS[(int)AV[CRNT][1]] = 1;
			if (FLAGS['s'] == 1)
			{
				CRNT++;
				break ;
			}
		}
		else
		{
			ft_printf("./ft_ssl: unknown option '-%c'\n", AV[CRNT][1]);
			free(glob);
			exit(0);
		}
		CRNT++;
	}
}

/*
** Loop which applys hash function to all provided files and messages.
*/

void			hash_params(t_glob *glob)
{
	void		(*hash[])(t_glob *glob) = {md5, sha256, sha224, sha512, sha1};

	while (read_message(glob) != -1)
	{
		if (MSG == NULL)
		{
			CRNT++;
			continue ;
		}
		hash[ALG](glob);
		print_hash(glob);
		if (STDIN == 2)
		{
			STDIN = 3;
			continue ;
		}
		CRNT++;
	}
}
