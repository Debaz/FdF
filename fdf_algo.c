/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:17:41 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:21:10 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

void		ft_partie1_b(int dx, int dy, t_mlx_env *mlx_e)
{
	if ((mlx_e->dy = mlx_e->xy[5] - mlx_e->xy[4]) != 0)
	{
		if (mlx_e->dy > 0)
		{
			if (-mlx_e->dx >= mlx_e->dy)
				ft_gateau_lieb(dy, dx, mlx_e);
			else
				ft_cakeb(dy, dx, mlx_e);
		}
	}
}

void		ft_partie1_a(int dx, int dy, t_mlx_env *mlx_e)
{
	if (mlx_e->dy > 0)
	{
		if (mlx_e->dx >= mlx_e->dy)
			ft_gateau(dx, dy, mlx_e);
		else
			ft_gateaub(dy, dx, mlx_e);
	}
	else if (mlx_e->dx > 0 && mlx_e->dy < 0)
	{
		if (mlx_e->dx >= -mlx_e->dy)
			ft_cake(dx, dy, mlx_e);
		else
			ft_gateau_lie(dx, dy, mlx_e);
	}
}

void		ft_partie1(int dx, int dy, t_mlx_env *mlx_e)
{
	if (mlx_e->dx > 0)
		ft_partie1_a(dx, dy, mlx_e);
	else if (mlx_e->dy == 0 && mlx_e->dx > 0)
		while (++mlx_e->xy[2] < mlx_e->xy[3])
			mlx_pixel_put(mlx_e->mlx, mlx_e->win,
						mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
	else if (mlx_e->dx < 0)
		ft_partie1_b(dx, dy, mlx_e);
	else if (mlx_e->dy < 0 && (mlx_e->dx < 0))
	{
		if (mlx_e->dx <= mlx_e->dy)
			ft_cake(dx, dy, mlx_e);
		else
			ft_cake_lie(dx, dy, mlx_e);
	}
}

void		my_algo_next(t_mlx_env *mlx_e)
{
	if ((mlx_e->dy = (mlx_e->xy[5] - mlx_e->xy[4])) != 0)
	{
		if (mlx_e->dy > 0)
			while (mlx_e->xy[4]++ != mlx_e->xy[5])
				mlx_pixel_put(mlx_e->mlx, mlx_e->win, mlx_e->xy[4],
							mlx_e->xy[2], ft_color(mlx_e));
		else if (mlx_e->dy < 0 && (mlx_e->dx == 0))
			while (mlx_e->xy[4]-- != mlx_e->xy[5])
				mlx_pixel_put(mlx_e->mlx, mlx_e->win, mlx_e->xy[4],
							mlx_e->xy[2], ft_color(mlx_e));
	}
	mlx_pixel_put(mlx_e->mlx, mlx_e->win, mlx_e->xy[4], mlx_e->xy[2],
							ft_color(mlx_e));
}

void		my_algo(t_mlx_env *mlx_e)
{
	mlx_e->dx = mlx_e->xy[3] - mlx_e->xy[2];
	mlx_e->dy = mlx_e->xy[5] - mlx_e->xy[4];
	if (mlx_e->dx != 0)
		ft_partie1(mlx_e->dx, mlx_e->dy, mlx_e);
	else if (mlx_e->dy == 0 && (mlx_e->dx < 0))
		while (mlx_e->xy[2]-- != mlx_e->xy[3])
			mlx_pixel_put(mlx_e->mlx, mlx_e->win,
						mlx_e->xy[4], mlx_e->xy[2], ft_color(mlx_e));
	else if (mlx_e->dx == 0)
		my_algo_next(mlx_e);
}
