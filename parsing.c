/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:26:54 by hchair            #+#    #+#             */
/*   Updated: 2025/03/07 16:35:19 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	check_name_map(char *argv)
{
	int			i;
	int			j;
	int			tmp;
	char		*ptr;
	static int	valid;

	ptr = ".cub";
	i = -1;
	while (argv[++i])
	{
		j = 0;
		tmp = i;
		while (argv[tmp] == ptr[j] && ptr[j])
		{
			tmp++;
			j++;
		}
		if (ptr[j] == '\0' && argv[tmp] == '\0')
			valid = 1; return (0);
	}
	if (valid == 0)
        return (printf("Error: Invalid map file\n"));
}

int valid_walls(char *line)
{
    int i;
    
    i = 0;
    while ( line[i] != '\0')
    {
        if (line[i] == '0')
        {
            printf("Error: Invalid character in map\n");
            return (1);
        }
        i++;
    }
    return (0);    
}

int	not_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' 
				&& line[i + 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A'))
			return (0);
		else if (line[i] == 'F' || line[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

void    load_textures(t_map *map, char *line)
{
    int i;
    
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == 'N' && line[i + 1] == 'O')
        {
            map->no = ft_strdup(&line[i + 2]);
            i += 2;
        }
        else if (line[i] == 'S' && line[i + 1] == 'O')
        {
            map->so = ft_strdup(&line[i + 2]);
            i += 2;
        }
        else if (line[i] == 'W' && line[i + 1] == 'E')
        {
            map->we = ft_strdup(&line[i + 2]);
            i += 2;
        }
        else if (line[i] == 'E' && line[i + 1] == 'A')
        {
            map->ea = ft_strdup(&line[i + 2]);
            i += 2;
        }
    }
}

void    load_map(t_map *map, char *av)
{
    int     fd;
    char    *line;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error oppening file\n");
        return ;
    }
    line = get_next_line(fd);
    map->map = (char **)malloc(sizeof (t_map));
    while (line)
    {
        if (not_map(line) == 0)
            load_textures(map, line);
        map->map[map->map_x] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        map->map_x++;
    }
    map->map[map->map_x] = NULL;
    close(fd);
}

int    check_map(t_map *map)
{
    int     j;
    
    // Check first and last rows
    for (j = 0; map->map[0][j] != '\0'; j++)
    {
        if (map->map[0][j] != '1' && map->map[0][j] != '\n')
        {
            printf("Error: Map is not surrounded bay walls at /%d/\n", j);
            return (1);
        }
    }
    j = 0;
    for (j = 0; map->map[map->map_x - 1][j] != '\0'; j++)
    {
        if (map->map[0][j] != '1' && map->map[0][j] != '\n')
        {
            printf("Error: Map is not surrounded by waalls\n");
            return (1);
        }
    }
    for (j = 0; j < map->map_x; j++)
    {
        if (map->map[j][0] != '1' || map->map[j][ft_strlen(map->map[j]) - 2] != '1')
        {
            printf("Error: Map is not surrounded by walls at [%d] [%ld]\n", j, ft_strlen(map->map[j]) - 1);
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int     j;
    t_map   *map;
    
    init(map);
    if (ac != 2)
    {
        printf("Error argument number\n");
        return (1);    
    }
    if (check_name_map(av[1]) == 0)
    {
        load_map(map, av[1]);
        if (check_map(map) == 0)
            return (1);
    }
    // check map is valid 
    // Check first and last columns
    // check 0 is not touching spaces
    map->map_x = 0;
    while (map->map[map->map_x] != NULL)
    {
        map->map_y = 0;
        while (map->map[map->map_x][map->map_y] != '\0')
        {
            if (map->map[map->map_x][map->map_y] == '0'
                || map->map[map->map_x][map->map_y] == 'N'
                || map->map[map->map_x][map->map_y] == 'S'
                || map->map[map->map_x][map->map_y] == 'E'
                || map->map[map->map_x][map->map_y] == 'W')
            {
                if (map->map[map->map_x][map->map_y + 1] == ' ' 
                    || map->map[map->map_x][map->map_y - 1] == ' ' 
                    || map->map[map->map_x + 1][map->map_y] == ' ' 
                    || map->map[map->map_x - 1][map->map_y] == ' ')
                {
                    printf("Error: element is touching space at x: %d y:%d\n", map->map_x, map->map_y);
                    return (1);
                }
            }
            map->map_y++;
        }
        map->map_x++;
    }
    printf("\033[0;32m Map is valid\n \033[0m");
    return (0);
}
