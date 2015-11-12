/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:17:57 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:21:32 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

void	ft_cake_lie(int dx, int dy, t_mlx_env *mlx_e)
{
	int	e;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (mlx_e->xy[4] < mlx_e->xy[5])
	{
		mlx_pixel_put(mlx_e->mlx, mlx_e->win,
					mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
		if ((e = e - dx) >= 0)
		{
			mlx_e->xy[2]--;
			e = e + dy;
		}
		mlx_e->xy[4]--;
	}
	mlx_pixel_put(mlx_e->mlx, mlx_e->win,
				mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
}

void	ft_cake(int dx, int dy, t_mlx_env *mlx_e)
{
	int	e;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (mlx_e->xy[2] < mlx_e->xy[3])
	{
		mlx_pixel_put(mlx_e->mlx, mlx_e->win,
					mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
		if ((e = e + dy) < 0)
		{
			mlx_e->xy[4]--;
			e = e + dx;
		}
		mlx_e->xy[2]++;
	}
	mlx_pixel_put(mlx_e->mlx, mlx_e->win,
				mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
}

void	ft_gateau_lie(int dx, int dy, t_mlx_env *mlx_e)
{
	int	e;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (mlx_e->xy[4] > mlx_e->xy[5])
	{
		mlx_pixel_put(mlx_e->mlx, mlx_e->win,
					mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
		if ((e = e + dx) > 0)
		{
			mlx_e->xy[2]++;
			e = e + dy;
		}
		mlx_e->xy[4]--;
	}
	mlx_pixel_put(mlx_e->mlx, mlx_e->win,
					mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
}

void	ft_gateau(int dx, int dy, t_mlx_env *mlx_e)
{
	int	e;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (mlx_e->xy[2] < mlx_e->xy[3])
	{
		mlx_pixel_put(mlx_e->mlx, mlx_e->win,
					mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
		if ((e = e - dy) < 0)
		{
			mlx_e->xy[4]++;
			e = e + dx;
		}
		mlx_e->xy[2]++;
	}
	mlx_pixel_put(mlx_e->mlx, mlx_e->win,
				mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
}
