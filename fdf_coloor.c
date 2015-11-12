/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coloor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:18:23 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:21:57 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

int					ft_color(t_mlx_env *mlx_e)
{
	unsigned int	color;

	if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] > 110)
		color = 0xFFFFFF;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < 100 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= 60)
		color = 0x99512B;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < 60 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= 40)
		color = 0x155732;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < 20 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= 10)
		color = 0x3A9D23;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < 10 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= 0)
		color = 0xDFAF2C;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < 0 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= -20)
		color = 0x1560BD;
	else if (mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] < -20 &&
			mlx_e->int_map[mlx_e->xy[0]][mlx_e->xy[1]] >= -40)
		color = 0x002FA7;
	else
		color = 0x1B019B;
	return (color);
}
