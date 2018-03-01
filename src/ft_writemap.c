
#include "fillit.h"


int     minMap(tetra *tetramin)
{
    int res;

    res = 0;
    while (tetramin)
    {
        if (tetramin->xlong > res)
            res = tetramin->xlong;
        if ((tetramin->ylong - 1) > res)
            res = tetramin->ylong - 1;
        tetramin = tetramin->next;
    }
    return (res);
}

char    *writeMap(int count, tetra *tetramin)
{  
        int     i;
        int     b;
        int     sq;
        char    *s;
        int     c;
        int     lng;

        i = -1;
        b = count * 4;
        sq = 0;
        while (sq < b)
        {
            ++i;
            sq = i * i;
        }
        if (i < minMap(tetramin))
            i = minMap(tetramin);
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

char    **biggerMap(char **map)
{
    int     x;
    int     y;
    char    **temp;
    int     i;

    x = 0;
    y = 0;
    i = ft_strlen(map[0]) + 1;
    temp = (char**)malloc(sizeof(char*) * i);
    while (x < i)
    {
        temp[x] = (char*)malloc(sizeof(char) * i);
        x++;
    }

    x = 0;
    while(y < i)
    {
        x = 0;
        while (x < i)
        {
            temp[y][x] = '.';
            x++;
        }
        temp[y][x] = '\0';
        y++;
    }
    temp[y] = 0;
    ismapchange = 1;
    return (temp);

}