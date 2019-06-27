/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:46:34 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/26 20:24:00 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include "../libft_github/inc/libft.h"
#include "fcntl.h"

void			print_hash(t_md5 *abcd, char *source, int fd);
char			*read_file(int fd);
void			append_split_blocks_mixer(char *str, t_md5 *abcd);
unsigned int	*block_to_int(unsigned char *block);

void			md_5(int ac, char **av, int i, char *flags)
{
	int			fd;
	int			out;
	char		*str;
	t_md5		abcd;

	out = 1;
	flags += 0;
//	if (ft_strchr(flags, 'p'))
//		str = read_file(1);
//	else
//	{
		while (i < ac)
		{
			abcd.a = 0x67452301;
			abcd.b = 0xefcdab89;
			abcd.c = 0x98badcfe;
			abcd.d = 0x10325476;
			if (out)
			{
				out = 0;
				i--;
				fd = 0;
			}
			else if ((fd = open(av[i], O_RDONLY)) == -1)
			{
				ft_printf("%s: No such file or directory\n", av[i++]);
				continue ; 
			}
			if (!(str = read_file(fd)))
			{
				i++;
				continue ;
			}
			append_split_blocks_mixer(str, &abcd);
			print_hash(&abcd, av[i], fd);
			i++;
		}
//	}

}

char			*read_file(int fd)
{
	int			n;
	char		str[1024 + 1];
	char		*result;
	char		*tmp;

	result = ft_memalloc(1);
	while((n = read(fd, str, 1024)) > 0)
	{
		str[n] = '\0';
		tmp = ft_strjoin(result, str);
		free(result);
		result = tmp;
	}
	if (n == -1)
	{
		ft_printf("read failed\n");
		return (NULL);
	}
	return (result);
}

void				append_split_blocks_mixer(char *str, t_md5 *abcd)
{
	unsigned long	len;
	int				i;
	unsigned char	block[64];
	unsigned int	*block_int;
	char			*remember;
	int				check;

	check = 1;
	remember = str;
	len = (long)ft_strlen(str) * 8;
	while (1)
	{
		i = -1;
		while (++i < 64 && str[i])
			block[i] = str[i];
		str = &str[i];
		if (i == 64)
		{
			block_int = (unsigned int *)block;
			/*
			for (int i = 0; i < 16; i++)
				ft_printf("%u\n", block_int[i]);
			*/
			process(block_int, abcd);
		}
		else if (i < 54)
		{
			if (check)
				block[i++] = 128;
			while (i < 58 )
				block[i++] = 0;
			((unsigned long *)block)[7] = len;
			block_int = (unsigned int *)block;
			/*
			for (int i = 0; i < 16; i++)
				ft_printf("%u\n", block_int[i]);
			*/
			process(block_int, abcd);
			break ;
		}
		else if  (i >= 54)
		{
			block[i++] = 128;
			check = 0;
			while (i < 64)
				block[i++] = 0;
			block_int = (unsigned int *)block;
			/*
			for (int i = 0; i < 16; i++)
				ft_printf("%u\n", block_int[i]);
			*/
			process(block_int, abcd);
		}
	}
	free(remember);
}
/*
unsigned int		*block_to_int(unsigned char *block)
{
	int				n;
	unsigned int	*block_int;

	n = 0;
	block_int = ft_memalloc(sizeof(int) * 16);
	while(n < 16)
	{
		block_int[n] = ((int)block[n + 3] << 24) + ((int)block[n + 2] << 16)
		   	+ ((int)block[n + 1] << 8) + (int)block[n];
		n++;
	}
	////
	for (int i = 0; i < 16; i++)
		ft_printf("%u\n", block_int[i]);
	//
	return (block_int);
}
*/
void				print_hash(t_md5 *abcd, char *source, int fd)
{
//	ft_printf("A: %x, B: %x, C: %x, D: %x\n", abcd->a, abcd->b, abcd->c, abcd->d);
//	little endian princip;
 	if (fd >= 3)
 		ft_printf("MD5(%s)= ", source);
	ft_printf("%02x%02x%02x%02x", (unsigned char)(abcd->a), (unsigned char)(abcd->a >> 8), 
			(unsigned char)(abcd->a >> 16), (unsigned char)(abcd->a >> 24));
	ft_printf("%02x%02x%02x%02x", (unsigned char)(abcd->b), (unsigned char)(abcd->b >> 8), 
			(unsigned char)(abcd->b >> 16), (unsigned char)(abcd->b >> 24));
	ft_printf("%02x%02x%02x%02x", (unsigned char)(abcd->c), (unsigned char)(abcd->c >> 8), 
			(unsigned char)(abcd->c >> 16), (unsigned char)(abcd->c >> 24));
	ft_printf("%02x%02x%02x%02x\n", (unsigned char)(abcd->d), (unsigned char)(abcd->d >> 8), 
			(unsigned char)(abcd->d >> 16), (unsigned char)(abcd->d >> 24));
//	system("openssl md5 test_2.txt");
}
