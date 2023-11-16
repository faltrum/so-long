/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:39:53 by osg               #+#    #+#             */
/*   Updated: 2023/11/13 10:18:43 by oseivane         ###   ########.fr       */
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
