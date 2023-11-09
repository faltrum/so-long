/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:35:34 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/09 12:48:48 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*wall;
	void	**mapall;
	void	*item;
	void	*exit;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
	int		width;
	int		heigth;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
}	t_game;

void	ft_play_game(char *argv, t_game *a);
void	ft_init_values(t_game *game);
void	play_game(char *map, t_game *game);
void	ft_go(t_game *map);

#endif