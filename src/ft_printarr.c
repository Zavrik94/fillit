
#include "fillit.h"

void	ft_printarr(char **arr)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!arr)
	{
		return ;
	}
	while(arr[i])
	{
		c = 0;
		while(arr[i][c])
		{
			printf("%c", arr[i][c]);
			c++;
		}
		printf("\n");
		i++;
	}
}
