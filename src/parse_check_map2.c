/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:05:45 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 14:53:47 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	create_map_line(t_game *game, char *str)
{
	int		fd;
	char	*area;
	int		i;

	game->map2d = (char **)ft_calloc(sizeof(char *), (9999));
	fd = open(str, O_RDONLY);
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

void	ft_check_map2(t_game *game, char *str)
{
	create_map_line(game, str);
	checker(game);
	print_map_copy(game);
}
