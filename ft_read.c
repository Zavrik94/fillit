
#include "fillit.h"

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
