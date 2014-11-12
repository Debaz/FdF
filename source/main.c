/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:38:00 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/12 19:15:43 by klescaud         ###   ########.fr       */
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

	if (ABS((b.x - a.x)) >= ABS((b.y - a.y)))
		longueur = ABS((b.x - a.x));
	else
		longueur = ABS((b.y - a.y));
	dx = (b.x - a.x) / longueur;
	dy = (b.y - a.y) / longueur;
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

int		**get_map(char *path)
{
	int		map[10][10];
	int		fd;
	char	**line;
	char	**splited_line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if ((fd = open(path, O_RDONLY)) < 2)
		ft_putendl("ERROR -> Open failed.");
	while (get_next_line(fd, line) < 0)
	{
		splited_line = ft_strsplit(*line, ' ');
		x = 0;
		while (x < 10)
		{
			map[y][x] = ft_atoi(splited_line[x]);
			x++;
		}
		y++;
	}
	return (map);
}

void	print_map(int **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < 10)
	{
		while (x < 10)
		{
			ft_putstr(ft_itoa(map[y][x]));
			ft_putchar(' ');
			x++;
		}
		x = 0;
		y++;
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	t_screen	screen;
	t_point		a;
	t_point		b;
	int			map[10][10];

	b.x = 50;
	b.y = 50;
	a.x = 750;
	a.y = 550;
	if (ac == 1)
	{
		map = get_map(av[1]);
		print_map(map);
		screen = do_fdf();
		draw_segment(screen, a, b);
		sleep(2);
	}
	return (0);
}
