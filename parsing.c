/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:26:54 by hchair            #+#    #+#             */
/*   Updated: 2025/01/16 22:41:14 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    int     fd;
    char    *line;
    int     ret;
    
    fd = 0;
    
    if (ac != 2)
        printf("Error argument number\n");
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        return (1);
    }
}
