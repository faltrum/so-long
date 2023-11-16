/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:46:34 by osg               #+#    #+#             */
/*   Updated: 2023/11/16 12:42:30 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//liberacion de valores mapall y mlx

void	ft_free_map(t_game *map)
{
	free(map->mapall);
	if (map->mlx)
		free(map->mlx);
}

// Funcion que cierra ventana y libera lo anterior
int	ft_close(t_game *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_map(map);
	exit(EXIT_SUCCESS);
}

void	*free_str(void *str)
{
	free(str);
	return (NULL);
}
