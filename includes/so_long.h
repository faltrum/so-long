/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:35:34 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/16 13:02:43 by oseivane         ###   ########.fr       */
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
	char	**map2d;
	char	*mapall;
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

void	ft_play_game(char *argv, t_game *game);
void	ft_init_values(t_game *game);
void	ft_go(t_game *map);
int		ft_format_ber(char *map_f);
void	ft_error(char *str, t_game *game);
void	ft_free_map(t_game *map);
void	*free_str(void *str);
int		ft_close(t_game *map);
void	parse_map(int fd, t_game *game);
int		ft_check_line(t_game *map, char **line, int fd);
int		ft_check_line_sub(t_game *map, char **line, int i);
void	ft_check_map(t_game *map);
void	ft_check_map2(t_game *game, int fd);
void	create_map_line(t_game *game, int fd);
void	create_map_length(char *area, t_game *game, int i);
char	*ft_strjoin_sub(char *s1, char *s2);
void	ft_map_r(t_game *map, int i);
void	ft_img_r(t_game *map);
int		ft_key_hook(int keycode, t_game *map);
void	ft_wkey(t_game *map);
void	ft_skey(t_game *map);
void	ft_dkey(t_game *map);
void	ft_akey(t_game *map);

#endif