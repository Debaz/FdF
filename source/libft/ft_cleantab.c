/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleantab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/12 20:42:37 by klescaud          #+#    #+#             */
/*   Updated: 2014/10/12 20:42:38 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_cleantab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			ft_strdel(&(tab[i++]));
		free(tab);
		tab = NULL;
	}
}
