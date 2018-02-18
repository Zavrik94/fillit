
#include "fillit.h"

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
