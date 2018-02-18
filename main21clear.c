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

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_strsplit.c"
#include "ft_strsplit2.c"
#include "ft_long.c"
#include "ft_printarr.c"

typedef struct tetra
{
    int     n;
    int     x;
    int     y;
    int     xlong;
    int     ylong;
    int     iter;
    char    letter;
    char    **tetr;
    struct tetra   *next;
    struct tetra   *prev;
}               tetra;

int         ft_error(int error)
{
    if (error == 0)
        write(1, "error\n", 6);
    return (0);
}

int         tetr_check(int i, char *s)
{
    int     ckr;

    while (s[i++] != '\0')
    {
        ckr = 0;
        if (s[i] == '#')
        {
            if (s[i - 1] == '#' || s[i + 1] == '#' || s[i - 5] == '#' || \
                s[i + 5] == '#')
                ckr++;
        }
        if (ckr == 0 && s[i] == '#')
            return (ft_error(0));
    }
    return (1);
}

int         ft_checker(char *s)
{
    int     i;
    int     c;
    int     d;

    d = 20;
    c = 4;
    i = 0;
    while (s[++i])
    {
        if ((s[i] != '.' && s[i] != '#') && (i != c && i != d))
            return (ft_error(0));
        else if (i == c)
        {
            if (s[i] != '\n')
                return (ft_error(0));
            c += 5;
        }
        else if (i == d)
        {   
            if (s[i] != '\n')
                return (ft_error(0));
            d += 21;
            c++;
        }
    }
    return (1);
}

int         ft_checker2(char *s)
{
    int     i;
    int     c;
    int     d;

    i = 0;
    c = 0;
    d = 0;
    while (s[i++])
    {
        d++;
        if (s[i + 1] == '#')
            c++;
        else if (d == 21 && c != 4)
            return (ft_error(0)); 
        if (s[i] == '\n' && s[i + 1] == '\n')
        {
            c = 0;
            d = 0;
        }
    }
    return (1);
}

char        *ft_read(char *file)
{
	int     fd;
	char    buff[545];
    char    buffer[1];
    int     i;

	fd = 0;
    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_error(0);
        exit (0);
    }
    while ((read(fd, buffer, 1)))
    {
        buff[i] = buffer[0];
        i++;
        if (i > 545)
        {
            ft_error(0);
            exit (0);
        }
    }
    buff[i] = '\0';
    close(fd);
    return (strdup(buff));
}

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

 void    deleteTetra(char **map,tetra *tetramin)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == tetramin->letter)
                map[y][x] = '.';
            x++;
        }
        y++;
    }
}

int     checkPossible(char **map, tetra *tetramin, int xcoord, int ycoord)
{
    int     i;
    int     c;
    int     *cord;
    int     x;
    int     y;

    i = 0;
    c = 0;
    x = tetramin->x;
    y = tetramin->y;
    cord = (int*)malloc(sizeof(int) * 2);
    cord[1] = (int)xcoord;
    cord[0] = (int)ycoord;
    if (((xcoord + tetramin->xlong) > ((int)strlen(map[0]))) || ((ycoord + tetramin->ylong - 1) > ((int)strlen(map[0]))))
    {
        return (0);
    }
    while (tetramin->tetr[y] && i < (tetramin->ylong))
    {
        x = tetramin->x;
        cord[1] = (int)xcoord;
        c = 0;
        while(tetramin->tetr[x] && c < tetramin->xlong)
        {
            if (tetramin->tetr[y][x] == '#' && map[cord[0]][cord[1]] != '.')
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

int     *findStart(char **map, tetra *tetramin)
{
    int x;
    int y;
    int *res;

    x = 0;
    y = 0;
    if (!(res = (int*)malloc(sizeof(int) * 2)))
        return (0);
    while (map[y])
    {
        
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '.' && checkPossible(map, tetramin, x, y))
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

int     *currCoord(char **map, tetra *tetramin)
{
    int     x;
    int     y;
    int     *res;
    int     minx;
    int     miny;

    x = 0;
    y = 0;
    minx = strlen(map[0]);
    miny = strlen(map[0]);
    if (!(res = (int*)malloc(sizeof(int) * 4)))
        return(NULL);
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == tetramin->letter)
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

int     *findNextStart(char **map, tetra *tetramin, int *coord)
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
    while (map[y])
    {
        if (i != 0)
            x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '.' && checkPossible(map, tetramin, x, y))
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

char    *writeMap(int count,int iter)
{
        int     i;
        int     sq;
        char    *s;
        int     c;
        int     lng;

        i = -1;
        sq = 0;
        while (sq < (count * 4))
        {
            ++i;
            sq = i * i;
        }
        i += iter;
        c = i;
        lng = i * i;
        lng = lng + i;
        s = (char*)malloc(sizeof(char) * (lng + 1));
        sq = 0;
        while (sq != lng)
        {
            if (sq == c)
            {
                s[sq] = '\n';
                c = c + i + 1;
            }
            else
                s[sq] = '.';
            sq++;
        }
        s[sq] = '\0';
        return(s);

}

tetra   *firstList(tetra *tetramin)
{
    while (tetramin->prev != NULL)
        tetramin = tetramin->prev;
    return (tetramin);
}

tetra   *filList(char ***res2)
{
    int     i;
    tetra   *tetramin;
    tetra   *temp;

    tetramin = (tetra*)malloc(sizeof(tetra));
    tetramin->prev = NULL;
    i = -1;
    while (res2[++i])
    {
        tetramin->n = i;
        tetramin->x = ft_coord(res2[i])[0];
        tetramin->y = ft_coord(res2[i])[1];
        tetramin->xlong = ft_coord(res2[i])[2];
        tetramin->ylong = ft_coord(res2[i])[3] + 1;
        tetramin->tetr = res2[i];
        tetramin->next = NULL;
        tetramin->letter = i + 65;
        temp = tetramin;
        tetramin->next = (tetra*)malloc(sizeof(tetra));
        tetramin = tetramin->next;
        tetramin->prev = temp;
    }
    tetramin = tetramin->prev;
    tetramin->next = NULL;
    tetramin = firstList(tetramin);
    return (tetramin);
}

void    putTetra(char **map, tetra *tetramin, int   *coord)
{
    int     i;
    int     c;
    int     x;
    int     y;
    int     reserv;

    i = 1;
    c = 0;
    x = tetramin->x;
    y = tetramin->y;
    reserv = coord[0];
    while (tetramin->tetr[y] && i < tetramin->ylong)
    {
        x = tetramin->x;
        coord[0] = reserv;
        c = 0;
        while(tetramin->tetr[x] && c < tetramin->xlong)
        {
            if (tetramin->tetr[y][x] == '#')
                map[coord[1]][coord[0]] = 65 + tetramin->n;
            //else if (tetramin.tetr[y][x] == '.')
            //    map[coord[1]][coord[0]] = ' ';
            coord[0]++;
            x++;
            c++;
        }
        coord[1]++;
        y++;
        i++;
    }   
}

int     isMove(char **map, tetra *tetramin)
{
    char    **temp;
    int     x;
    int     y;
    int     *cur;

    x = 0;
    y = 0;
    temp = (char**)malloc(sizeof(char*) * strlen(map[0]));
    while (map[y])
    {
        temp[y] = (char*)malloc(sizeof(char) * strlen(map[0]));
        x = 0;
        while (map[y][x])
        {
            temp[y][x] = map[y][x];
            x++;
        }
        y++;
    }
    cur = currCoord(temp, tetramin);
    deleteTetra(temp, tetramin);
    if (findNextStart(temp, tetramin, cur) == NULL)
    {
        free(temp);
        return (0);
    }
    free(temp);
    return (1);
}

tetra   *move(char **map, tetra *tetramin)
{
    int *res;


    if (isMove(map, tetramin) == 0)
    {
        deleteTetra(map, tetramin);
        tetramin = move(map, tetramin->prev)->prev;

    }
    else
    {
        res = currCoord(map, tetramin);
        deleteTetra(map, tetramin);
        res = findNextStart(map, tetramin, res);
        putTetra(map, tetramin, res);
    }

    return (tetramin->next);
}

void    setTetra(char **map,tetra *tetramin)
{
    int     *coord;

    if (tetramin == NULL)
        return ;
    while (findStart(map, tetramin) == NULL)
    {
        tetramin = move(map, tetramin->prev);
        if (tetramin == NULL)
            return ;
    }
    coord = findStart(map, tetramin);
    putTetra(map, tetramin, coord);
    setTetra(map, tetramin->next);
}


int         main()
{
    char    *read;
    char    **res;
    char    ***res2;
    tetra   *tetramin;
    char    **map;
    int     i;

	read = ft_read("test.c");
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
    map = ft_strsplit2(writeMap(ft_long2(read), 0));
    setTetra(map, tetramin);
    ft_printarr(map);
    free(read);
    free(res);
    free(res2);
    free(tetramin);
    free(map);
    return (0);
}