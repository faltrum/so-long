/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:35:34 by oseivane          #+#    #+#             */
/*   Updated: 2023/10/19 14:28:40 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"

typedef struct s_game
{
	void	*wall;
	void	*mapall;
	void	*item;
	void	*exit;
	void	*player;
}	t_game;

void	ft_play_game(char *argv, t_game *a);
void	ft_init_values(t_game *game);

#endif