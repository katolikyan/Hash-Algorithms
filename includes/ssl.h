/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:04:58 by tkatolik          #+#    #+#             */
/*   Updated: 2019/07/14 01:06:22 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
# define SSL_H

# include <fcntl.h>
# include "../libft/inc/libft.h"

/*
** DEFINES ----------------------------------------
*/

# define ALG_NUM 5
# define IS_FLAG (glob->av[glob->crnt][1] == 'q' || \
   		 		glob->av[glob->crnt][1] == 'p' || \
				glob->av[glob->crnt][1] == 'r' || \
				glob->av[glob->crnt][1] == 's')
# define CRNT	(glob->crnt)
# define AV		(glob->av)
# define AC		(glob->ac)
# define FLAGS	(glob->flags)
# define ALG	(glob->hash_alg)
# define MSG	(glob->msg)
# define LEN	(glob->len)
# define HASH	(glob->hashsum)
# define STDIN	(glob->nostdin)
# define FILES	(glob->nofile)
# define FREEIT	(glob->freeit)
# define ERRORFILE "%s: %s: No such file or directory\n"

/*
** STRUCTS ----------------------------------------
*/

/*
** typedef struct		s_glob
** {
** 	int					hash_alg;		// hash algorithm num;
**	char				**av;
**	int					ac;
**	int					crnt;			// current argument index;
**	char				flags[128];		// flags table;
**	char				*msg;			// message to hash;
**	unsigned long		len;			// len of msg after appending;
**	uint8_t				freeit;			// checker if free msg needed;
**	char				*hashsum;		// hash result;
**	char				nofile;			// checker if there is no files yet;
**	char				nostdin;		// checker if stdin was checked;
** }					t_glob;
*/

typedef struct			s_glob
{
	int					hash_alg;
	char				**av;
	int					ac;
	int					crnt;
	char				flags[128];
	char				*msg;
	unsigned long		len;
	uint8_t				freeit;
	char				*hashsum;
	char				nofile;
	char				nostdin;
}						t_glob;

/*
** DEPENDENT INCLUDES -----------------------------
*/

# include "sha.h"
# include "md5.h"

/*
** FUNCTIONS --------------------------------------
*/

/*
** main:
*/

void					find_alg(t_glob *glob);
void					upper(t_glob *glob);
void					parce_flags(t_glob *glob);
void					hash_params(t_glob *glob);
int						read_message(t_glob *glob);
int						read_files(t_glob *glob, int fd);
char					*read_file(int fd);
void					print_hash(t_glob *glob);

/*
** padding:
*/

void					append_512(t_glob *glob);
void					append_1024(t_glob *glob);
void					str_copy(char *dst, char *src, long len);

#endif
