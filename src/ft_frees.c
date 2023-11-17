/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:46:34 by osg               #+#    #+#             */
/*   Updated: 2023/11/17 12:11:02 by mcatalan@st      ###   ########.fr       */
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

int	ft_free_map2d(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map2d)
		return (1);
	while (game->map2d[i])
	{
		free(game->map2d[i]);
		i++;
	}
	free(game->map2d);
	if (game->mlx)
		free(game->mlx);
	return (0);
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
