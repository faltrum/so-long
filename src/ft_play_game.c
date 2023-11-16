/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:02 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 11:59:59 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Aqui empieza el reparto de faena en el juego

void	ft_play_game(char *map, t_game *game)
{
	int	fd;

	if (!ft_format_ber(map))
		ft_error("Formato de mapa erroneo!\n", game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("No hay fichero o directorio!\n", game);
	ft_check_map2(game, fd);
	parse_map(fd, game);
	ft_go(game);
}
