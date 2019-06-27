/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 10:12:53 by tkatolik          #+#    #+#             */
/*   Updated: 2019/06/26 16:33:12 by tkatolik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"
#include "../libft_github/inc/libft.h"

int				pars_flags(int ac, char **av, char *flags, int i);
void			md_5(int ac, char **av, int i, char *flags);

int				main(int ac, char **av)
{
	char		flags[ac];
	static int	i = 0;

	if (ac < 2) 
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (0);
	}
	if (ac > 2)
		i = pars_flags(ac, av, flags, i);
	if (!(ft_strcmp(av[1], "md5")))
		md_5(ac, av, i, flags);
	else if (!(ft_strcmp(av[1], "sha256")))
		return (0); //sha_256;
	else
		ft_printf("invalid command");
//	system("leaks a.out");
	return (0);
}

int				pars_flags(int ac, char **av, char *flags, int i)
{
	int			n;

	n = 0;
	i = 2;
	while (i < ac && av[i][0] == '-')
	{
		if (av[i][2] == '\0' && IS_FLAG)
			flags[n++] = av[i][1];
		else
		{
			ft_printf("unknown option '-%c'\n", av[i][1]);
			exit (0);
		}
	}
	flags[n] = '\0';
	return (i);
}

/*
int				main()
{
	t_md5		abcd;
	unsigned char	 *block;
	unsigned int	 block_int[16];


	unsigned int test[65] = {0, 0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, \
						0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501, \
						0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, \
						0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, \
						0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, \
						0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8, \
						0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, \
						0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a, \
						0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, \
						0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, \

						0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, \
						0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665, \
						0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, \
						0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1, \
						0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, \
						0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};
	abcd.t = test;

	abcd.a = 0x67452301;   //A
	abcd.b = 0xefcdab89;   //B
	abcd.c = 0x98badcfe;   //C
	abcd.d = 0x10325476;   //D

*
	unsigned int t[] = { 3614090360, 3905402710, 606105819, 3250441966,
  						4118548399, 1200080426, 2821735955, 4249261313,
						1770035416, 2336552879, 4294925233, 2304563134,
						1804603682, 4254626195, 2792965006, 1236535329,
						4129170786, 3225465664, 643717713, 3921069994,
						3593408605, 38016083, 3634488961, 3889429448,
						568446438, 3275163606, 4107603335, 1163531501,
						2850285829, 4243563512, 1735328473, 2368359562,
						4294588738, 2272392833, 1839030562, 4259657740,
						2763975236, 1272893353, 4139469664, 3200236656,
						681279174, 3936430074, 3572445317, 76029189,
						3654602809, 3873151461, 530742520, 3299628645,
						4096336452, 1126891415, 2878612391, 4237533241,
						1700485571, 2399980690, 4293915773, 2240044497,
						1873313359, 4264355552, 2734768916, 1309151649,
						4149444226, 3174756917, 718787259, 3951481745 };

	abcd.a = 1732584193;   //A
	abcd.b = 4023233417;   //B
	abcd.c = 2562383102;   //C
	abcd.d = 271733878;   //D

	block = ft_memalloc(sizeof(char) * 64);

	block[0] = 'H';
	block[1] = 'e';
	block[2] = 'l';
	block[3] = 'l';
	block[4] = 'o';
	block[5] = (unsigned char)(1 << 7);
	block[56] = 40;

	int	nn;
	nn = 0;
	for(int n = 0; n < 64; n += 4)
	{
		block_int[nn++] = ((int)block[n + 3] << 24) + ((int)block[n + 2] << 16) + ((int)block[n + 1] << 8) + (int)block[n];
	}

	for (int i = 0; i < 16; i++)
		printf("%u\n", block_int[i]);
	//int		i;
	//i = ('l' << 24) + ('l' << 16) + ('e' << 8) + 'H';
//	printf("\n%i\n", i);
	process(block_int, &abcd);

//	abcd.a = (tmp << 24) + ((abcd.a << 16) & 0xFF0000) + ((tmp << 8) & 0xFF00) + (abcd.a & 0xFF);
//	abcd.b = (abcd.b << 24) + ((abcd.b << 16) & 0xFF0000) + ((abcd.b << 8) & 0xFF00) + (abcd.b & 0xFF);
//	abcd.c = (abcd.c << 24) + ((abcd.c << 16) & 0xFF0000) + ((abcd.c << 8) & 0xFF00) + (abcd.c & 0xFF);
//	abcd.d = (abcd.d << 24) + ((abcd.d << 16) & 0xFF0000) + ((abcd.d << 8) & 0xFF00) + (abcd.d & 0xFF);
	//printf("Hello: %x%x%x%x\n", abcd.a, abcd.b, abcd.c, abcd.d);
	//
	// little endian princip;
	printf("Hello: %x%x\n", (unsigned char)(abcd.a), (unsigned char)(abcd.a >> 8));
}
*/


