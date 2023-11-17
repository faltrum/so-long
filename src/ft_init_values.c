/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:21:52 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/17 11:15:52 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Inicializar la variables de la estructura

void	ft_init_values(t_game *game)
{
	game->wall = NULL;
	game->mapall = NULL;
	game->map2d = NULL;
	game->item = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->space = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->heigth = 0;
	game->players = 0;
	game->gameover = 0;
	game->steps = 0;
	game->gift = NULL;
	game->max_gift = NULL;
	game->score = 0;
	game->max_score = 0;
}
