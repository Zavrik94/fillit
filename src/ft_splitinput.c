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

static int		*ft_long(char *s, char ch)
{
	int	i;
	int cword;
	int	*res;

	i = -1;
	cword = 0;
	if (!s)
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] != ch && i == 0)
			cword++;
		else if ((s[i] != ch && s[i - 1] == ch && s[i - 2] == ch))
			cword++;
	if (!(res = (int*)malloc(sizeof(int) * (cword + 1))))
		return (NULL);
	res[0] = cword + 1;
	while (cword != 0)
		res[cword--] = 20;
	return (res);
}

static char		*ft_write(char *s, int i, int c)
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

char			**ft_splitinput(const char *s)
{
	int		i;
	int		*c;
	int		*res;
	char	**rch;
	char	ch;

	if (!(c = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	c[0] = 0;
	ch = '\n';
	res = ft_long((char*)s, ch);
	if (!res || !(rch = (char **)malloc(sizeof(char *) * (res[0] + 1))))
		return (NULL);
	i = -1;
	while (s[++i])
	{
		c[1] = c[0] + 1;
		if (s[i] != ch && i == 0)
			rch[c[0]++] = ft_write((char *)s, i, res[c[1]]);
		else if ((s[i] != ch && s[i - 1] == ch && s[i - 2] == ch))
			rch[c[0]++] = ft_write((char *)s, i, res[c[1]]);
	}
	rch[c[0]] = 0;
	free(c);
	free(res);
	return (rch);
}
