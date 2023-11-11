/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:09:26 by osg               #+#    #+#             */
/*   Updated: 2023/11/11 19:21:22 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Que pasa cuando apretas W?, pues que
//recoloca al player y hace checks en el mapa
//En el caso de que llegue a EXIT , finaliza el juego

void	ft_wkey(t_game *map)
{
	int	x;
	int	i;
	
	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
	if (map->mapall[i - x] != '1' && map->mapall[i - x] != 'E')
	{
		if (map->mapall[i - x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - x] = 'P';
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
}

void	ft_skey(t_game *map)
{
	int	x;
	int	i;
	
	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
	if (map->mapall[i + x] != '1' && map->mapall[i + x] != 'E')
	{
		if (map->mapall[i + x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + x] = 'P';
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
}

void	ft_dkey(t_game *map)
{
	int	i;
	
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
	if (map->mapall[i + 1] != '1' && map->mapall[i + 1] != 'E')
	{
		if (map->mapall[i + 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + 1] = 'P';
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
}

void	ft_akey(t_game *map)
{
	int	i;
	
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
	if (map->mapall[i - 1] != '1' && map->mapall[i - 1] != 'E')
	{
		if (map->mapall[i - 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - 1] = 'P';
		map->steps++;
		ft_printf("Movimientos: %i\n", map->steps);
	}
}
