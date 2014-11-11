/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:38:00 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/11 13:28:30 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	do_fdf(void)
{
	t_screen	screen;

	if ((screen.mlx_ptr = mlx_init()) == NULL)
		ft_putendl("ERROR -> mlx_ptr == NULL.");
	if ((screen.win_ptr = mlx_new_window(screen.mlx_ptr, SIZE_X, SIZE_Y, TITLE)) == NULL)
		ft_putendl("ERROR -> win_ptr == NULL.");
	mlx_loop(screen.mlx_ptr);
	ft_putendl("Tout va bien.");
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		av[0] = av[0];
		do_fdf();
	}
	return (0);
}
