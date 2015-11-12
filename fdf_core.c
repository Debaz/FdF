/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:22:11 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:22:14 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

t_mlx_env				*g_mlx_env(void)
{
	static t_mlx_env	g_env;

	return (&g_env);
}

int						c_is_map(char c)
{
	if ((c >= 48 && c <= 57) || c == '-' || c == '+' || c == '\0' ||
		c == ' ' || c == '\t' || c == '\v' || c == '\n')
		return (1);
	return (0);
}

int						key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void					mlx_draw(t_mlx_env *mlx_e)
{
	mlx_e->int_map = convert_map_to_int(mlx_e);
	g_mlx_env()->tab_i = my_tab(mlx_e->int_map);
	ligne_x(mlx_e, g_mlx_env()->tab_i);
	ligne_y(mlx_e, g_mlx_env()->tab_i);
}
