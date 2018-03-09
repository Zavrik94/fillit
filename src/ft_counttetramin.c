/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counttetramin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 19:49:23 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/07 19:49:25 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_counttetramin(char *s)
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
