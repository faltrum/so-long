/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:23:03 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 13:32:00 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_values(&game);
	if (argc == 2)
	{
		ft_play_game(argv[1], &game, argv[1]);
	}
	ft_printf("Error\n");
	return (0);
}
