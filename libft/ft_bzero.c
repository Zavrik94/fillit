/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:33:31 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/07 18:33:34 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t num)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < num)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}