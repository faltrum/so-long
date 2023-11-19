/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:56:54 by osg               #+#    #+#             */
/*   Updated: 2023/11/19 17:20:14 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//ESta funcion concatena 2 strings
// Anyade un NULL check y cierra el juego
//si hay algun error.

char	*ft_strjoin_sub(char *s1, char *s2)
{
	char	*new;
	char	*tmp;

	if (s1 == NULL)
		return (ft_strtrim(s2, "\n"));
	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	new = ft_strtrim(tmp, "\n");
	free(tmp);
	return (new);
}

//Esta funcion  checkea que todo sea legal en el juego

void	ft_check_map(t_game *map)
{
	int	i;
	int	j;

	i = map->width;
	while (i > -1)
	{
		if (map->mapall[i] != '1')
			ft_error("Mapa no valido 1!\n", map);
		i--;
	}
	i = map->width;
	j = ft_strlen(map->mapall);
	while (i > -1)
	{
		if (map->mapall[j - 1] != '1')
			ft_error("Mapa no valido 2!\n", map);
		j--;
		i--;
	}
	if (map->width > 30 || map->heigth > 20)
		ft_error("Mapa no cabe en la ventana\n", map);
}

//Funcion que checkea top and bottom del mapa

int	ft_check_line_sub(t_game *map, char **line, int i)
{
	if ((*line)[i] != '1')
	{
		free(*line);
		ft_error("Not walled!\n", map);
	}
	return (1);
}

//Funcion que checkea el mapa todo ok y el width del mismo

int	ft_check_line(t_game *map, char **line, int fd)
{
	int		i;
	char	*tmp;

	i = ft_check_line_sub(map, line, 0);
	while ((*line)[i + 1] != '\n' && (*line)[i + 1])
	{
		if ((*line)[i] != '1' && (*line)[i] != '0' && (*line)[i] != 'C'
				&& (*line)[i] != 'E' && (*line)[i] != 'P')
		{
			free(*line);
			ft_error("Other characters\n", map);
		}
		i++;
	}
	i = i + ft_check_line_sub(map, line, i);
	tmp = map->mapall;
	map->mapall = ft_strjoin_sub(tmp, *line);
	free(tmp);
	free(*line);
	if (i != map->width && map->width != 0)
		ft_error("No rectangular, deforme\n", map);
	*line = get_next_line(fd);
	map->heigth++;
	return (i);
}

//Esta funcion lee el mapa con GNL.
//Después hace checkeos para ver si el mapa es valido
void	parse_map(int fd, t_game *game)
{
	int		i = 0;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Mapa no valido! 6\n", game);
	while (line != NULL)
		game->width = ft_check_line(game, &line, fd);
	close(fd);
	ft_check_map(game);
	fd = 0;
	while (game->mapall[fd])
	{
		if (game->mapall[fd] == 'C')
			game->max_score++;
		if (game->mapall[fd] == 'P')
			game->players++;
		if (game->mapall[fd] == 'E')
			i++;
		fd++;
	}
	if ((game->width == game->heigth) || game->players != 1
		|| i != 1 || game->max_score == 0)
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
}
