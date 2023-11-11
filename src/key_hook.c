/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:03:08 by osg               #+#    #+#             */
/*   Updated: 2023/11/11 19:08:14 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Esta funcion detecta que bton presiona el usuario
// Bton ESC, W, A, D, S. Interesante funcion.

int	ft_key_hook(int keycode, t_game *map)
{
	if (keycode == 53)
		map->gameover++;
	else if (keycode == 13)
		ft_wkey(map);
	else if (keycode == 1)
		ft_skey(map);
	else if (keycode == 2)
		ft_dkey(map);
	else if (keycode == 0)
		ft_akey(map);
	if (map->gameover > 0)
		ft_close(map);
	mlx_clear_window(map_mlx, map->win);
	ft_map_render(map, 0);
	return (0);
}