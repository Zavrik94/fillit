/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:55:00 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/15 21:37:50 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		countintetra(char *s, char ch, int i)
{
	int c;

	c = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != ch)
	{
		c++;
		i++;
	}
	return (c);
}

static int		*ft_longtetra(char *s, char ch)
{
	int	i;
	int cword;
	int	c;
	int	*res;

	i = -1;
	cword = 0;
	c = 1;
	if (!s)
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] != ch && i == 0)
			cword++;
		else if ((s[i] != ch && s[i - 1] == ch))
			cword++;
	if (!(res = (int*)malloc(sizeof(int) * (cword + 2))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] == ch && s[i + 1] != ch)
			res[c++] = countintetra(s, ch, i + 1);
		else if (i == 0 && s[i] != ch)
			res[c++] = countintetra(s, ch, 0);
	res[0] = cword;
	return (res);
}

static char		*ft_writetetra(char *s, int i, int c)
{
	char	*res;
	int		j;

	j = 0;
	if (!(res = (char *)malloc(c * sizeof(char) + 1)) || !s)
		return (NULL);
	while (j <= c - 1)
	{
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

char			**ft_splittetra(const char *s)
{
	int		i;
	int		*c;
	int		*res;
	char	**rch;

	if (!(c = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	c[0] = 0;
	res = ft_longtetra((char*)s, '\n');
	if (!res || !(rch = (char **)malloc(sizeof(char *) * (res[0] + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
	{
		c[1] = c[0] + 1;
		if (s[i] != '\n' && i == 0)
			rch[c[0]++] = ft_writetetra((char *)s, i, res[c[1]]);
		else if ((s[i] != '\n' && s[i - 1] == '\n'))
			rch[c[0]++] = ft_writetetra((char *)s, i, res[c[1]]);
	}
	rch[c[0]] = 0;
	free(res);
	free(c);
	return (rch);
}
