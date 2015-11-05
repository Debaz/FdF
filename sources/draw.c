/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 12:55:16 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/05 12:56:43 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				define_first_coord(t_coord *pos, int x_c, int y_c, int z)
{
	pos->x = x_c;
	pos->y = y_c;
	if (z != 0)
		pos->y -= z;
}

t_coord				*define_coord(int x, int y, int z, t_env *e)
{
	t_coord		*pos;
	int			x_c;
	int			y_c;

	x_c = 5;
	y_c = 5;
	z = z * e->zoom / 10;
	pos = (t_coord *) malloc(sizeof(t_coord));
	if (x == 0 && y == 0)
		define_first_coord(pos, x_c, y_c, z);
	else if (x > 0)
	{
		pos->x = x_c + e->zoom * x;
		pos->y = y_c + e->zoom * y;
		if (z != 0)
			pos->y -= z;
	}
	else if (y > 0 && x == 0)
	{
		pos->x = x_c - e->zoom * x;
		pos->y = y_c + e->zoom * y;
		if (z != 0)
			pos->y -= z;
	}
	return (pos);
}

t_coord				**stock_coord(int **point, int line, int col, t_env *e)
{
	int			x;
	int			y;
	t_coord		*tmp;
	t_coord		**point_c;

	point_c = (t_coord **) malloc(sizeof(t_coord *) * line);
	y = 0;
	while (y < line)
	{
		point_c[y] = (t_coord *) malloc(sizeof(t_coord) * col);
		x = 0;
		while (x < col)
		{
			tmp = define_coord(x, y, point[y][x], e);
			point_c[y][x].x = tmp->x;
			point_c[y][x].y = tmp->y;
			point_c[y][x].point = point[y][x];
			x++;
		}
		y++;
	}
	return (point_c);
}

void				draw_line(t_env *e, t_coord start, t_coord end)
{
	float		i;
	int			len;

	len = ft_sqrt(ft_pow(end.x - start.x, 2) + ft_pow(end.y + start.y, 2));
	i = 0;
	while (i < len)
	{
		if ((start.point != 0 || end.point != 0) && start.point == end.point)
		{
			mlx_pixel_put(e->mlx, e->win, i * (end.x - start.x) / len + start.x,
						  i * (end.y - start.y) / len + start.y, 0x00FF00);
		}
		else if (start.point != end.point)
		{
			mlx_pixel_put(e->mlx, e->win, i * (end.x - start.x) / len + start.x,
						  i * (end.y - start.y) / len + start.y, 0x008000);
		}
		else
		{
			mlx_pixel_put(e->mlx, e->win, i * (end.x - start.x) / len + start.x,
						  i * (end.y - start.y) / len + start.y, 0x004000);
		}
		i++;
	}
}

void				draw_grid(int **point, t_env *e, int line, int col)
{
	int			x;
	int			y;
	t_coord		**point_c;

	point_c = stock_coord(point, line, col, e);
	y = 0;
	while (y < line)
	{
		x = 0;
		while (x < col)
		{
			if (y < (line - 1))
				draw_line(e, point_c[y][x], point_c[y + 1][x]);
			if (x < (col - 1))
				draw_line(e, point_c[y][x], point_c[y][x + 1]);
			x++;
		}
		y++;
	}
}
