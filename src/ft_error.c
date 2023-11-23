/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:39:53 by osg               #+#    #+#             */
/*   Updated: 2023/11/23 10:32:22 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Funcion que imprime error, sale del juego y hace frees

void	ft_error(char *str, t_game *game)
{
	if (game->mapall)
		free(game->mapall);
	ft_printf("Error\n");
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

int	msg(char *str)
{
	ft_printf("%s", str);
	exit (0);
}

void	ft_error_map(t_game *game, int i)
{
	if (game->width == game->heigth)
		ft_error("Mapa cuadrado\n", game);
	else if (game->players != 1)
	{
		if (game->players == 0)
			ft_error("No hay player\n", game);
		else
			ft_error("Más de 1 player\n", game);
	}
	else if (i != 1)
	{
		if (i == 0)
			ft_error("No hay salida\n", game);
		else
			ft_error("Hay más de una salida\n", game);
	}
	else
		ft_error("¡Mapa sin colectibles!\n", game);
}
