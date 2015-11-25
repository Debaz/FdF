/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ligne.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:18:58 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:22:47 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

void		ligne_y(t_mlx_env *mlx_e, int ***tab_i)
{
	mlx_e->xy[0] = 0;
	mlx_e->xy[1] = 0;
	while (mlx_e->xy[0] < g_mlx_env()->i[1])
	{
		mlx_e->xy[1] = 0;
		while (mlx_e->xy[1] + 1 < g_mlx_env()->i[0])
		{
			mlx_e->xy[4] = tab_i[mlx_e->xy[0]][mlx_e->xy[1]][0];
			mlx_e->xy[2] = tab_i[mlx_e->xy[0]][mlx_e->xy[1]][1];
			mlx_e->xy[5] = tab_i[mlx_e->xy[0]][mlx_e->xy[1] + 1][0];
			mlx_e->xy[3] = tab_i[mlx_e->xy[0]][mlx_e->xy[1] + 1][1];
			my_algo(mlx_e);
			mlx_e->xy[1]++;
		}
		mlx_e->xy[0]++;
	}
}

void		ligne_x(t_mlx_env *mlx_e, int ***tab_i)
{
	mlx_e->xy[0] = 0;
	mlx_e->xy[1] = 0;
	while (mlx_e->xy[1] < g_mlx_env()->i[0])
	{
		mlx_e->xy[0] = 0;
		while (mlx_e->xy[0] + 1 < g_mlx_env()->i[1])
		{
			mlx_e->xy[4] = tab_i[mlx_e->xy[0]][mlx_e->xy[1]][0];
			mlx_e->xy[2] = tab_i[mlx_e->xy[0]][mlx_e->xy[1]][1];
			mlx_e->xy[5] = tab_i[mlx_e->xy[0] + 1][mlx_e->xy[1]][0];
			mlx_e->xy[3] = tab_i[mlx_e->xy[0] + 1][mlx_e->xy[1]][1];
			my_algo(mlx_e);
			mlx_e->xy[0]++;
		}
		mlx_e->xy[1]++;
	}
}
