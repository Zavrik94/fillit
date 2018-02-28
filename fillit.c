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

#include "src/fillit.h"

int         main(int argc, char **argv)
{
    char    *read;
    char    **res;
    char    ***res2;
    tetra   *tetramin;
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
            res = ft_splitInput(read);
            if (!(res2 = (char***)malloc(sizeof(char**) * (ft_countTetramin(read) + 1))))
                return (0);
            i = 0;
            while (res[i])
            {
                res2[i] = ft_splitTetra(res[i]);
                i++;
            }
            res2[i] = 0;
            isMapChange = 0;
            tetramin = filList(res2);
            map = ft_splitTetra(writeMap(ft_countTetramin(read), tetramin));
            setTetra(tetramin);
            ft_printarr(map);
            free(read);
            free(res);
            free(res2);
            free(tetramin);
            free(map);
            return (0);
        //}
    }
}