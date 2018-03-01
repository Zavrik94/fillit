/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:45:07 by azavrazh          #+#    #+#             */
/*   Updated: 2018/03/01 17:45:10 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fillit.h"

int         main(int argc, char **argv)
{
    char    *read;
    char    **res;
    char    ***res2;
    t_tetra   *tetramin;
    int     i;

    if (argc != 2)
    {
        write(1, "error\n", 6);
        return (0);
    }
    else
    {
	    read = ft_read(argv[1]);
        //if (ft_checker(read) == 0)
        //{
          //  write(1, "error\n", 6);
            //return (0);
        //}
        //else
        //{
            res = ft_splitinput(read);
            if (!(res2 = (char***)malloc(sizeof(char**) * (ft_counttetramin(read) + 1))))
                return (0);
            i = 0;
            while (res[i])
            {
                res2[i] = ft_splittetra(res[i]);
                i++;
            }
            res2[i] = 0;
            g_ismapchange = 0;
            tetramin = fillist(res2);
            g_map = ft_splittetra(writemap(ft_counttetramin(read), tetramin));
            settetra(tetramin);
            ft_printarr(g_map);
            free(read);
            free(res);
            free(res2);
            free(tetramin);
            free(g_map);
            return (0);
        //}
    }
}
