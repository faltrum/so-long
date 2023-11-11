/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:27:31 by osg               #+#    #+#             */
/*   Updated: 2023/11/11 17:33:50 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Esta funcion checkea el formato del fichero mapa .ber

int	ft_format_ber(char *map_f)
{
	int		i;
	char	*file_ber;

	file_ber = ".ber";
	i = 0;
	while (ft_strlen(map_f) != 4 && map_f)
		map_f++;
	if (!map_f || *map_f == '\0')
		return (0);
	while (map_f[i])
	{
		if (map_f[i] != file_ber[i])
			return (0);
		i++;
	}
	return (1);
}