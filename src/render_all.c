/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:13 by osg               #+#    #+#             */
/*   Updated: 2023/11/23 10:47:56 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Esta imagen renderiza las imagenes una por una
//para el juego si falta algo.

void	ft_img_r(t_game *map)
{
	int	i;

	i = 100;
	map->wall = mlx_xpm_file_to_image(map->mlx, "textures/wall.xpm", &i, &i);
	map->exit = mlx_xpm_file_to_image(map->mlx, "textures/exit.xpm", &i, &i);
	map->item = mlx_xpm_file_to_image(map->mlx, "textures/item.xpm", &i, &i);
	map->player = mlx_xpm_file_to_image(map->mlx,
			"textures/player.xpm", &i, &i);
	map->space = mlx_xpm_file_to_image(map->mlx, "textures/space.xpm", &i, &i);
	if (!map->wall || !map->exit || !map->item || !map->player || !map->space)
	{
		free(map->win);
		free(map->mlx);
		ft_printf("Error\n");
		ft_putstr_fd("Archivo imagen falta!\n", 1);
		exit(EXIT_FAILURE);
	}
}

//Esta funcion renderiza el juego

void	ft_map_r(t_game *map, int i)
{
	int		x;
	int		y;
	char	*s;

	y = -1;
	while (y++ < map->heigth)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->mapall[i] == '1')
				s = map->wall;
			if (map->mapall[i] == '0')
				s = map->space;
			if (map->mapall[i] == 'C')
				s = map->item;
			if (map->mapall[i] == 'P')
				s = map->player;
			if (map->mapall[i] == 'E')
				s = map->exit;
			mlx_put_image_to_window(map->mlx, map->win, s, x * 100, y * 100);
			i++;
			x++;
		}
	}
}
