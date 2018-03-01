/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:44:01 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:44:04 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     *ft_coord(char **s)
{
    int     x;
    int     y;
    int     *res;

    x = 0;
    y = 0;
    if (!(res = (int*)malloc(sizeof(int) * 4)))
        return(NULL);
    res[0] = 4;
    res[1] = 4;
    res[2] = 0;
    res[3] = 0;
    while (s[y])
    {
        x = 0;
        while(s[y][x])
        {

            if (s[y][x] == '#')
                {
                    if (x < res[0])
                        res[0] = x;
                    if (y < res[1])
                        res[1] = y;
                    if (x > res[2])
                        res[2] = x;
                    if (y > res[3])
                        res[3] = y;
                }
            x++;
        }
        y++;
    }
    res[2] = res[2] - res[0] + 1;
    res[3] = res[3] - res[1] + 1;
    return (res);
}

int     checkpossible(char **g_map,t_tetra *tet, int xc, int yc)
{
    int     i;
    int     c;
    int     *cord;
    int     x;
    int     y;

    i = 0;
    c = 0;
    x = tet->x;
    y = tet->y;
    cord = (int*)malloc(sizeof(int) * 2);
    cord[1] = (int)xc;
    cord[0] = (int)yc;
    if (((xc + tet->xlong) > ((int)ft_strlen(g_map[0]))) || ((yc + tet->ylong - 1) > ((int)ft_strlen(g_map[0]))))
    {
        return (0);
    }
    while (tet->tetr[y] && i < (tet->ylong))
    {
        x = tet->x;
        cord[1] = (int)xc;
        c = 0;
        while(tet->tetr[x] && c < tet->xlong)
        {
            if (tet->tetr[y][x] == '#' && g_map[cord[0]][cord[1]] != '.')
            {
                free(cord);
                return (0);
            }
            cord[1]++;
            x++;
            c++;
        }
        cord[0]++;
        y++;
        i++;
    }
    free(cord);
    return(1);
}

int     *findstart(char **g_map, t_tetra *tetramin)
{
    int x;
    int y;
    int *res;

    x = 0;
    y = 0;
    if (!(res = (int*)malloc(sizeof(int) * 2)))
        return (0);
    while (g_map[y])
    {
        
        x = 0;
        while (g_map[y][x])
        {
            if (checkpossible(g_map, tetramin, x, y))
            {
                    res[0] = x;
                    res[1] = y;
                    return (res);   
            }
            x++;
        }
        y++;
    }
    free(res);
    return (NULL);
}

int     *currcoord(char **g_map, t_tetra *tetramin)
{
    int     x;
    int     y;
    int     *res;
    int     minx;
    int     miny;

    x = 0;
    y = 0;
    minx = ft_strlen(g_map[0]);
    miny = ft_strlen(g_map[0]);
    if (!(res = (int*)malloc(sizeof(int) * 4)))
        return(NULL);

    while (g_map[y])
    {
        x = 0;
        while(g_map[y][x])
        {
            if (g_map[y][x] == tetramin->letter)
                {
                    if (x < minx)
                        minx = x;
                    if (y < miny)
                        miny = y;
                }
            x++;
        }

        y++;
    }
    res[0] = minx;
    res[1] = miny;
    return (res);
}

int     *findnextstart(char **g_map, t_tetra *tetramin, int *coord)
{
    int     x;
    int     y;
    int     *res;
    int     i;

    x = coord[0] + 1;
    y = coord[1];
    if (!(res = (int*)malloc(sizeof(int) * 4)))
        return(NULL);
    i = 0;
    while (g_map[y])
    {
        if (i != 0)
            x = 0;
        while (g_map[y][x])
        {
            if (checkpossible(g_map, tetramin, x, y))
            {
                    res[0] = x;
                    res[1] = y;
                    return (res);   
            }
            x++;
        }
        i++;
        y++;
    }
    free(res);
    return (NULL);
}
