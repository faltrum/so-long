/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:50:50 by oseivane          #+#    #+#             */
/*   Updated: 2023/11/09 12:10:27 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_number_size(unsigned long long number)
{
	unsigned long long	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}
