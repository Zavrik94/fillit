
#include "fillit.h"

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
