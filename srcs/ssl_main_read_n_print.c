/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_main_read_n_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:12:53 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/14 00:26:53 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

/*
**	Reding file.
**	If -q privided or there is no files try to
**	read STDOUT or STDIN depends.
**
**	read_message checks STDIN & STDOUT;
**	read_files then checks and try to read provided files.
*/

int				read_message(t_glob *glob)
{
	int			fd;
	static int	frst_check = 1;

	fd = 0;
	if ((FLAGS['p'] || CRNT == AC) && STDIN == 0 && frst_check)
	{
		if (!(MSG = read_file(0)))
			MSG = read_file(1);
		if (FLAGS['p'])
		{
			ft_printf("%s", MSG);
			FLAGS['p'] = 0;
		}
		STDIN = 1;
		FREEIT = 1;
		return (1);
	}
	else if (CRNT < AC)
	{
		frst_check = 0;
		return (read_files(glob, fd) == 1 ? 1 : 0);
	}
	return (-1);
}

int				read_files(t_glob *glob, int fd)
{
	if (FLAGS['s'])
	{
		MSG = AV[CRNT];
		return (1);
	}
	else if (FILES == 0 && AV[CRNT][0] == '-' && AV[CRNT][1] == 's')
	{
		FLAGS['s'] = 1;
		AV[CRNT] += 2;
		MSG = AV[CRNT];
		return (1);
	}
	else
	{
		if ((fd = open(AV[CRNT], O_RDONLY)) == -1)
		{
			ft_printf(ERRORFILE, AV[0], AV[CRNT]);
			MSG = NULL;
			return (0);
		}
		MSG = read_file(fd);
		FILES = 1;
		FREEIT = 1;
		return (1);
	}
}

/*
**	Read file function.
**	Reads and stores message from arg to string in struct;
*/

char			*read_file(int fd)
{
	int			n;
	char		str[1024 + 1];
	char		*result;
	char		*tmp;

	result = ft_memalloc(1);
	while ((n = read(fd, str, 1024)) > 0)
	{
		str[n] = '\0';
		tmp = ft_strjoin(result, str);
		free(result);
		result = tmp;
	}
	if (n == -1)
	{
		if (fd != 0)
		{
			ft_printf("./ft_ssl: read failed\n");
			exit(0);
		}
		return (NULL);
	}
	return (result);
}

/*
**	Print hashsum in STDOUT.
**	Organisation of message depends on flags provided.
*/

void			print_hash(t_glob *glob)
{
	if (STDIN == 1)
	{
		ft_printf("%s\n", HASH);
		STDIN = 2;
	}
	else
	{
		if (FLAGS['q'] == 0)
		{
			if (FLAGS['s'] == 0)
				FLAGS['r'] ? ft_printf("%s %s\n", HASH, AV[CRNT]) :
					ft_printf("%s (%s) = %s\n", AV[1], AV[CRNT], HASH);
			else
				FLAGS['r'] ? ft_printf("%s \"%s\"\n", HASH, AV[CRNT]) :
					ft_printf("%s (\"%s\") = %s\n", AV[1], AV[CRNT], HASH);
		}
		else
			ft_printf("%s\n", HASH);
	}
	if (FLAGS['s'] && (STDIN == 3 || STDIN == 0))
		FLAGS['s'] = 0;
	free(MSG);
	free(HASH);
	FREEIT = 0;
}
