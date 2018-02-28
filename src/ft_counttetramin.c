
#include "fillit.h"

int		ft_countTetramin(char *s)
{
	int	i;
	int cword;

	i = -1;
	cword = 0;
	if (!s)
		return (0);
	while (s[++i] != '\0')
		if (s[i] != '\n' && i == 0)
			cword++;
		else if ((s[i] != '\n' && s[i - 1] == '\n' && s[i - 2] == '\n'))
			cword++;
	return (cword);
}
