/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:03:28 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:03:28 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_pow(int nb, unsigned int p)
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
