/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:23:03 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/09 13:11:55 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	play;

	ft_init_values(&play);
	if (argc == 2)
	{
		ft_play_game(argv[1], &play);
	}
	ft_printf("Error\n");
	return (0);
}
