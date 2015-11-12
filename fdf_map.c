/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:19:10 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:23:00 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

int				***my_tab(int **tab)
{
	int			xy[6];
	int			***t_i;

	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 100;
	xy[4] = 700;
	t_i = (int ***)malloc(sizeof(int **) * (g_mlx_env()->i[1]));
	while (xy[0] < g_mlx_env()->i[1])
	{
		xy[5] = xy[4] + (xy[0] > 0 ? (-10 * xy[0]) : 0);
		xy[3] = xy[2] + (xy[0] > 0 ? (+10 * xy[0]) : 0);
		xy[1] = -1;
		t_i[xy[0]] = (int **)malloc(sizeof(int **) * (g_mlx_env()->i[0]));
		while (++xy[1] < g_mlx_env()->i[0])
		{
			t_i[xy[0]][xy[1]] = (int *)malloc(sizeof(int) * 2);
			t_i[xy[0]][xy[1]][0] = xy[5];
			t_i[xy[0]][xy[1]][1] = xy[3] - tab[xy[0]][xy[1]];
			xy[3] = xy[3] + 10;
			xy[5] = xy[5] + 10;
		}
		xy[0]++;
	}
	return (t_i);
}

void			ft_size_map(char **map, int *y, int *x)
{
	int			xx;
	int			nb_caract;
	size_t		len;

	nb_caract = 0;
	xx = 0;
	len = 0;
	while (map[len][xx] != '\n' && map[len][xx])
	{
		if (ft_isdigit(map[len][xx]) && (map[len][xx + 1] == ' ' ||
										map[len][xx + 1] == '\0'))
			nb_caract++;
		if (c_is_map(map[len][xx]))
			xx++;
		else
			ft_error(1700);
	}
	while (map[len] != NULL)
		len++;
	*y = nb_caract;
	*x = len;
}

int				**convert_map_to_int(t_mlx_env *mlx_e)
{
	char		**line;
	int			i;
	int			j;

	mlx_e->int_map = (int **)malloc(sizeof(int *) * (g_mlx_env()->i[1]));
	i = 0;
	while (i < g_mlx_env()->i[1])
	{
		mlx_e->int_map[i] = (int *)malloc(sizeof(int) * g_mlx_env()->i[0]);
		i++;
	}
	i = 0;
	while (i < g_mlx_env()->i[1])
	{
		line = ft_strsplit(g_mlx_env()->map[i], ' ');
		j = 0;
		while (line[j])
		{
			mlx_e->int_map[i][j] = ft_atoi(line[j]);
			j++;
		}
		i++;
	}
	return (mlx_e->int_map);
}
