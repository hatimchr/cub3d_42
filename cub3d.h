/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:25:37 by hchair            #+#    #+#             */
/*   Updated: 2025/02/15 22:15:48 by hchair           ###   ########.fr       */
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

#endif