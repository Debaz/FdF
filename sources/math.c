/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 12:54:07 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/05 12:54:26 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_sqrt(int nb)
{
	int		i;

	i = 0;
	while (1)
	{
		if ((i * i) >= nb)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_pow(int nb, unsigned int p)
{
	int		buffer;

	if (p == 0)
		return (1);
	buffer = nb;
	while (p > 1)
	{
		buffer = buffer * nb;
		p--;
	}
	return (buffer);
}
