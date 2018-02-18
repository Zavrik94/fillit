
#include "fillit.h"

int         ft_error(int error)
{
    if (error == 0)
        write(1, "error\n", 6);
    return (0);
}

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
            return (ft_error(0));
    }
    return (1);
}

int         ft_check1(char *s)
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
            return (ft_error(0)); 
        if (s[i] == '\n' && s[i + 1] == '\n')
        {
            c = 0;
            d = 0;
        }
    }
    return (1);
}

int     ft_checker(char *s)
{
    if (tetr_check(s) == 1 && ft_check1(s) == 1 && ft_check2(s) == 1)
    {
        return (1);
    }
    return (0);
}
