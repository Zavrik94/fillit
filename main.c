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

int         main()
{
    char    *read;
    char    **res;
    char    ***res2;
    tetra   *tetramin;
    char    **map;
    int     i;

	read = ft_read("test.txt");
    res = ft_strsplit(read);
    if (!(res2 = (char***)malloc(sizeof(char**) * (ft_long2(read) + 1))))
        return (0);
    i = 0;
    while (res[i])
    {
        res2[i] = ft_strsplit2(res[i]);
        i++;
    }
    res2[i] = 0;
    tetramin = filList(res2);
    
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    map = ft_strsplit2(writeMap(ft_long2(read), 1));
    setTetra(map, tetramin);
    ft_printarr(map);
    free(read);
    free(res);
    free(res2);
    free(tetramin);
    free(map);
    return (0);
}