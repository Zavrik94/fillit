#include "fillit.h"

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
            coord[0]++;
            x++;
            c++;
        }
        coord[1]++;
        y++;
        i++;
    }   
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


int     isMove(char **map, tetra *tetramin)
{
    char    **temp;
    int     x;
    int     y;
    int     *cur;

    x = 0;
    y = 0;
    temp = (char**)malloc(sizeof(char*) * ft_strlen(map[0]) + 1);
    while (map[y])
    {
        temp[y] = (char*)malloc(sizeof(char) * ft_strlen(map[0]) + 1);
        x = 0;
        while (map[y][x])
        {
            temp[y][x] = map[y][x];
            x++;
        }
        temp[y][x] = '\0';
        y++;
    }
    temp[y] = 0;
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

tetra   *move(tetra *tetramin)
{
    int *res;

    if (isMove(map, tetramin) == 0 && tetramin->prev == NULL)
    {
            map = biggerMap(map);
            tetramin = firstList(tetramin);
            return (tetramin->next);
    }
    else if (isMove(map, tetramin) == 0)
    {
        deleteTetra(map, tetramin);
        tetramin = move(tetramin->prev)->prev;
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

void    setTetra(tetra *tetramin)
{
    int     *coord;

    if (tetramin == NULL)
        return ;
    while (findStart(map, tetramin) == NULL)
    {
        tetramin = move(tetramin->prev);
        if (ismapchange == 1)
        {
            tetramin = firstList(tetramin);
            ismapchange = 0;
        }
    }
    coord = findStart(map, tetramin);
    putTetra(map, tetramin, coord);
    setTetra(tetramin->next);
}
