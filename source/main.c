/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:38:00 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/11 16:04:44 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_screen	do_fdf(void)
{
	t_screen	screen;

	if ((screen.mlx_ptr = mlx_init()) == NULL)
		ft_putendl("ERROR -> mlx_ptr == NULL.");
	if ((screen.win_ptr = mlx_new_window(screen.mlx_ptr,
										 SIZE_X, SIZE_Y, TITLE)) == NULL)
		ft_putendl("ERROR -> win_ptr == NULL.");
	mlx_loop(screen.mlx_ptr);
	ft_putendl("Tout va bien.");
	return (screen);
}

void		draw_segment(t_screen screen, t_point a, t_point b)
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	int			i;
	double		longueur;

	if (ABS(b.x - a.x) >= ABS(b.y - a.y))
		longueur = ABS(b.x - a.x);
	else
		longueur = ABS(b.y - a.y);
	dx = b.x - a.x;
	dy = b.y - a.y;
	x = a.x + 0.5;
	y = a.y + 0.5;
	i = 1;
	while (i <= longueur)
	{
		mlx_pixel_put(screen.mlx_ptr, screen.win_ptr,
					  (int)round(x), (int)round(y), WHT);
		x = x + dx;
		y = y + dy;
		i++;
	}
}

#include <stdio.h>

int		main(int ac, char **av)
{
	t_screen	screen;
	t_point		a;
	t_point		b;

	a.x = 100;
	a.y = 100;
	b.x = 200;
	b.y = 200;
	if (ac == 1)
	{
		av[0] = av[0];
		screen = do_fdf();
		draw_segment(screen, a, b);
	}
	return (0);
}
