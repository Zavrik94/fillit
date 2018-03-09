/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanoilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:29:19 by vmanoilo          #+#    #+#             */
/*   Updated: 2017/12/26 17:29:21 by vmanoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetr_check(int i, char *s)
{
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 3] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
				i += 5;
			else if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 11] == '#')
				i += 11;
			else if (s[i + 5] == '#' && s[i + 9] == '#' && s[i + 10] == '#')
				i += 10;
			else if (s[i + 1] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
				i += 10;
			else if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 3] == '#')
				i += 3;
			else if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 7] == '#')
				i += 7;
			else if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 5] == '#')
				i += 5;
			else if (s[i + 1] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
				i += 6;
			else if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
				i += 7;
			else if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 6] == '#')
				i += 6;
			else if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 10] == '#')
				i += 10;
			else if (s[i + 1] == '#' && s[i + 2] == '#' && s[i + 6] == '#')
				i += 6;
			else if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 10] == '#')
				i += 10;
			else if (s[i + 1] == '#' && s[i + 6] == '#' && s[i + 7] == '#')
				i += 7;
			else if (s[i + 4] == '#' && s[i + 5] == '#' && s[i + 9] == '#')
				i += 9;
			else if (s[i + 5] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
				i += 11;
			else if (s[i + 1] == '#' && s[i + 4] == '#' && s[i + 5] == '#')
				i += 5;
			else if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 15] == '#')
				i += 15;
			else if (s[i + 1] == '#' && s[i + 6] == '#' && s[i + 11] == '#')
				i += 11;
			else if (s[i] == '.' || s[i] == '\n')
				tetr_check(i, s);
			else
				return (0);
		}
		i++;
	}
	return (1);
}


int		ft_checker(char *read)
{
	int	i;
	int	s;
	int	d;
	int	t;
	int	n;

	t = 0;
	i = 0;
	s = 0;
	d = 0;
	n = 0;
	if (read[i] == 0)
		return(0);
	while (read[i] != '\0')
	{
		if (read[i] == '.')
			d++;
		else if (read[i] == '#')
			s++;
		else if (read[i] == '\n' || read[i + 1] == '\0')
		{
			n++;
			if(read[i + 1] == '\n' && read [i + 2] == '\0')
				return(0);
			if (d + s == 4 || d + s == 8 || d + s == 12 || d + s == 16)
			{
				if ((d == 0 || s == 0) && d + s == 16)
					return(0);
				if (d + s == 16 && s != 4)
					 return(0);
				if (d + s == 16 && read[i + 1] == '\0')
					return(1);
				if (d + s == 16 && read[i + 1] != '\n')
					return(0);
				if (read[i + 1] == '\n')
					i++;
			}
			else
				return (0);
			if (d == 12 && s == 4 && d + s == 16)
			{
				if (d == 0 || s == 0)
					return(0);
				d = 0;
				s = 0;
				t++;
			}
		}
		else
				return(0);
		i++;
	}
	if (n/t != 4)
		return(0);
	else
		return (1);
}

int         ft_check(char *read)
{
	int i;

	i = 0;
	if (ft_checker(read) == 1)
	{
			if (tetr_check(i, read) == 1)
				return(1);
			else
				return(0);
	}
	else
		return(0);
	return (0);
}
