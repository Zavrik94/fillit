/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:39:06 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/09 13:34:54 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_tetra
{
	int				x;
	int				y;
	int				xlong;
	int				ylong;
	int				iter;
	char			letter;
	char			**tetr;
	struct s_tetra	*next;
	struct s_tetra	*prev;
}					t_tetra;

char				**g_map;
int					g_ismapchange;

void				ft_printarr(char **arr);
int					ft_checker(char *read);
int					tetr_check(char ***res);
void				settetra(t_tetra *tetramin);
int					*ft_coord(char **s);
void				freearr(void **arr);
void				freelist(t_tetra *list);
int					checkpossible(char **map, t_tetra *tet, int xc, int yc);
int					*findstart(char **map, t_tetra *tetramin);
int					*currcoord(char **map, t_tetra *tetramin);
int					*findnextstart(char **map, t_tetra *tetramin, int *coord);
t_tetra				*firstlist(t_tetra *tetramin);
t_tetra				*fillist(char ***res2, int i);
char				*ft_read(char *file);
char				*writemap(int count, t_tetra *tetramin);
char				**biggermap(int i);
int					iffree(int *res, int *cur, char **temp);
char				**ft_splitinput(const char *s);
char				**ft_splittetra(const char *s);
int					ft_counttetramin(char *s);
int					*initres(void);

#endif
