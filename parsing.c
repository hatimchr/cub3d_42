/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:26:54 by hchair            #+#    #+#             */
/*   Updated: 2025/01/24 17:07:14 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	check_name_map(char *argv)
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
			valid = 1;
	}
	if (valid == 0)
	{
		printf("\033[91mError:\033[0m\n");
		exit(printf("Map name is invalid!!! try tu use example.cub\n"));
	}
}

int valid_directions(char *line)
{
    
}
int main(int ac, char **av)
{
    int     fd;
    char    *line;
    int     ret;
    t_map   map;
    
    fd = 0;
    map.map_x = 0;
    map.map_y = 0;
    if (ac != 2)
    {
        printf("Error argument number\n");
        return (1);    
    }
    check_name_map(av[1]);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error oppening file\n");
        return (1);
    }
    line = get_next_line(fd);
    while (line)
    {
        map.map[map.map_x] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
        map.map_x++;
    }
    map.map[map.map_x] = NULL;
    // print map
    for (int i = 0; map.map[i]; i++)
    {
        printf("%s\n", map.map[i]);
    }
}
