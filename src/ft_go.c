/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:55:37 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/11 17:38:44 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//

void	ft_go(t_game *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx,
				100 * map->width, 100 * map->heigth, "oseivane SO_LONG");
	ft_img_r(map);
	ft_map_r(map, 0);
	mlx_hook(map->win, 17, 0, ft_close, map);
	mlx_key_hook(map->win, ft_key_hook, map);
	mlx_loop(map->mlx);
}
