/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:05:45 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 13:04:11 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map_copy(t_game *game)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	i = 0;
	cols = game->width;
	rows = game->heigth;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_printf("%c", game->map2d[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	create_map_length(char *area, t_game *game, int i)
{
	int	j;

	j = 0;
	game->map2d[i] = (char *)malloc(sizeof(char) * (9999));
	while (area[j])
	{
		if (area[j] == '\n')
			break ;
		game->map2d[i][j] = area[j];
		j++;
	}
	game->map2d[i][j] = '\0';
}

void	create_map_line(t_game *game, int fd)
{
	char	*area;
	int		i;

	game->map2d = (char **)ft_calloc(sizeof(char *), (9999));
	//fd = open(fd, O_RDONLY);
	i = 0;
	while (i <= game->heigth)
	{
		area = get_next_line(fd);
		if (area == NULL)
			break ;
		create_map_length(area, game, i);
		free_str(area);
		i++;
	}
	game->map2d[i] = NULL;
	close(fd);
}

void	ft_check_map2(t_game *game, int fd)
{
	(void)game;
	(void)fd;
	// char	*mapcopy;


	printf("Que no apre la fiesta");
	create_map_line(game, fd);
	print_map_copy(game);
	// mapcopy = ft_strdup(map->mapall);
	// printf("Que no apre la fiesta");
	// // while (!mapcopy)
	// // {
	// // }
}
