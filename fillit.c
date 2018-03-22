/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:45:07 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/07 18:48:40 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fillit.h"

char		***get_res(char *read)
{
	int		i;
	char	**res;
	char	***res2;

	g_ismapchange = 0;
	if (!(res2 = (char***)malloc(sizeof(char**) * \
					(ft_counttetramin(read) + 1))))
		return (NULL);
	res = ft_splitinput(read);
	i = -1;
	while (res[++i])
		res2[i] = ft_splittetra(res[i]);
	res2[i] = 0;
	freearr((void**)res);
	return (res2);
}

int			main(int argc, char **argv)
{
	char	*read;
	char	***res;
	t_tetra	*tetramin;
	int 	i;
	char	*map;

	if (argc != 2 && write(1, "error\n", 7))
		return (0);
	printf("%zu\n", sizeof(t_tetra));
	read = ft_read(argv[1]);
	if (ft_checker(read) == 0 && write(1, "error\n", 7))
		return (0);
	res = get_res(read);
	if (tetr_check(res) == 0 && write(1, "error\n", 7))
		return (0);
	tetramin = fillist(res);
	map = writemap(ft_counttetramin(read), tetramin);
	g_map = ft_splittetra(map);
	free(map);
	settetra(tetramin);
	ft_printarr(g_map);
	free(read);
	i = -1;
	while(res[++i])
		freearr((void**)res[i]);
	free(res);
	freelist(tetramin);
	freearr((void**)g_map);
	return (0);
}
