/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:19:41 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/17 11:16:52 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_valid_move(t_game *game, int row, int col)
{
	int	numrows;
	int	numcols;

	numcols = game->width;
	numrows = game->heigth;
	if ((row >= 0 && row < numrows && col >= 0 && col < numcols)
		&& (game->map2d[row][col] == 'C' || game->map2d[row][col] == 'E'
			|| game->map2d[row][col] == '0'))
	{
		if (game->map2d[row][col] == 'C')
			game->gift++;
		else if (game->map2d[row][col] == 'E')
			game->exit = (void *)true;
		return (true);
	}
	return (false);
}

bool	find_path(t_game *game, int row, int col)
{
	game->map2d[row][col] = '.';
	if (is_valid_move(game, row - 1, col))
	{
		if (find_path(game, row - 1, col))
			return (true);
	}
	if (is_valid_move(game, row + 1, col))
	{
		if (find_path(game, row + 1, col))
			return (true);
	}
	if (is_valid_move(game, row, col - 1))
	{
		if (find_path(game, row, col - 1))
			return (true);
	}
	if (is_valid_move(game, row, col + 1))
	{
		if (find_path(game, row, col + 1))
			return (true);
	}
	game->map2d[row][col] = 'X';
	return (false);
}

void	init_and_use_map2d(t_game *game, size_t *s_row, size_t *s_col)
{
	size_t	size_x;
	size_t	size_y;
	size_t	i;
	size_t	j;

	size_x = game->width;
	size_y = game->heigth;
	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (game->map2d[i][j] == 'P')
			{
				*s_row = i;
				*s_col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	checker(t_game *game)
{
	size_t	start_row;
	size_t	start_col;

	init_and_use_map2d(game, &start_row, &start_col);
	find_path(game, start_row, start_col);
	if (game->exit && game->item == game->max_gift)
		ft_printf("\n");
	else
		msg("The map has no solution\n");
}

