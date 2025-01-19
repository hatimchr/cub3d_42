/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:26:54 by hchair            #+#    #+#             */
/*   Updated: 2025/01/18 21:40:47 by hchair           ###   ########.fr       */
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


int main(int ac, char **av)
{
    int     fd;
    char    *line;
    int     ret;
    
    fd = 0;
    
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
}
