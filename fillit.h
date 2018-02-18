
#ifndef FILLIT_H
# define FILLIT_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct		tetra
{
	int				n;
	int				x;
	int				y;
	int				xlong;
	int				ylong;
	int				iter;
	char			letter;
	char			**tetr;
	struct	tetra	*next;
	struct	tetra	*prev;
}					tetra;

void				setTetra(char **map, tetra *tetramin);
int					*ft_coord(char **s);
int					checkPossible(char **map, tetra *tetramin, int xcoord, int ycoord);
int					*findStart(char **map, tetra *tetramin);
int					*currCoord(char **map, tetra *tetramin);
int					*findNextStart(char **map, tetra *tetramin, int *coord);
tetra				*firstList(tetra *tetramin);
tetra				*filList(char ***res2);
int					ft_checker(char *s);
char				*ft_read(char *file);
char				*writeMap(int count, int iter);

int					ft_error(int error);
char				**ft_strsplit(const char *s);
char				**ft_strsplit2(const char *s);
int					ft_long2(char *s);
void				ft_printarr(char **arr);

#endif
