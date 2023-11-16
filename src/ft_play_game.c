/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:02 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 13:43:42 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Aqui empieza el reparto de faena en el juego

void	ft_play_game(char *map, t_game *game, char *str)
{
	int	fd;

	if (!ft_format_ber(map))
		ft_error("Formato de mapa erroneo!\n", game);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("No hay fichero o directorio!\n", game);
	parse_map(fd, game);
	ft_check_map2(game, str);
	ft_go(game);
}
