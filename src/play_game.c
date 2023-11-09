/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:42:58 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/09 12:13:14 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//con esta funci'on empieza todo.

void	play_game(char *map, t_game *game)
{
	(void)map;
	(void)game;
	//parsear y filtros para checkear que todo esta ok.
	ft_go(game);
}
