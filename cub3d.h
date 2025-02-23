/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:25:37 by hchair            #+#    #+#             */
/*   Updated: 2025/02/23 04:25:38 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "GNL/get_next_line.h"
// #include <mlx42.h>

typedef struct  s_map
{
    char        **map;
    int         map_x;
    int         map_y;
}               t_map;

typedef struct  s_info
{
    int 	pl_x;
	int		pl;
	int		elm;
    int		pl_y;
    char	*no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
    int		f;
    int     c;
}            t_info;

#endif