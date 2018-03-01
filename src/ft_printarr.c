
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
			write(1, &arr[i][c], 1);
			c++;
		}
		write(1, "\n", 1);
		i++;
	}
}
