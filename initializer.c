/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:03:22 by hchair            #+#    #+#             */
/*   Updated: 2025/03/07 22:48:23 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    init_map(t_map *map)
{
    map->map = NULL;
    map->map_x = 0;
    map->map_y = 0;
}

void    init_rgb(t_map *map)
{
    map->flr = (int *)malloc(sizeof(int) * 3);
    map->ceal = (int *)malloc(sizeof(int) * 3);
    map->flr[0] = -1;
    map->flr[1] = -1;
    map->flr[2] = -1;
    map->ceal[0] = -1;
    map->ceal[1] = -1;
    map->ceal[2] = -1;
}

void    init(t_map *map)
{
    map->no = NULL;
    map->so = NULL;
    map->we = NULL;
    map->ea = NULL;
    map->map = NULL;
    map->pl_x = 0;
    map->pl_y = 0;
    map->elm = 6;
    init_map(map);
    init_rgb(map);
}
