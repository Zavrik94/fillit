
#include "fillit.h"

int         tetr_check(char *s)
{
    int     ckr;
    int     i;

    i = 0;
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
            return (0);
    }
    return (1);
}

int         ft_check1(char *s)
{
    int     i;
    int     c;
    int     d;
    int     cn;
    int     dies;

    d = 20;
    c = 4;
    i = 0;
    cn = 0;
    dies = 0;
    while (s[++i])
    {
        if (s[i] == '#')
            dies++;
        if ((s[i] != '.' && s[i] != '#') && (i != c && i != d))
            return (0);
        else if (i == c)
        {
            if (s[i] != '\n')
                return (0);
            c += 5;
            cn++;
        }
        else if (i == d)
        {   
            if (s[i] != '\n')
                return (0);
            if (dies != 4)
                return (0);

        if (dies != 4)
            return (0);
            d += 21;
            c++;
            cn = 0;
            dies = 0;
        }
    }
    if (cn != 0 && cn != 4)
        return (0);
    return (1);
}

int         ft_check2(char *s)
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
            return (0); 
        if (s[i] == '\n' && s[i + 1] == '\n')
        {
            c = 0;
            d = 0;
        }
    }
    //printf("%c %c\n", s[strlen(s) - 1], s[strlen(s) - 2]);
    if ((s[ft_strlen(s) - 1]) != '\n' && ((s[ft_strlen(s) - 2]) != '.' || (s[ft_strlen(s) - 2]) != '#'))
        return (0);
    return (1);
}

int     ft_checker(char *s)
{
    if (tetr_check(s) == 1 && ft_check1(s) == 1 && ft_check2(s) == 1)
    {

    //printf("%d %d %d\n", tetr_check(s), ft_check1(s), ft_check2(s));
        return (1);
    }
    //printf("%d %d %d\n", tetr_check(s), ft_check1(s), ft_check2(s));
    return (0);
}
