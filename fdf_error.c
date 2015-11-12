/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:18:48 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:28:04 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

void		ft_error_bc(char *s)
{
	perror(s);
	exit(-1);
}

void		ft_error(int ac)
{
	if (ac == 1)
		ft_putendl("Error : No map.");
	else if (ac == 4242)
		ft_putendl("Error : Map does not exist.");
	else if (ac == 1700)
		ft_putendl("Error : Invalid map file.");
	else if (ac >= 3)
		ft_putendl("Error : Too many arguments.");
	else
		return ;
	exit(1);
}
