/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 10:05:43 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/06 10:07:51 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	draw_reload(e);
	return (0);
}

void	display_controls(void)
{
	ft_putstr("\
____________________________\n\
CONTROLES:\n\
Translation:\n\
	Y: Touche: HAUT, BAS\n\
	X: Touche: GAUCHE, DROITE\n\
\n\
Rotation:\n\
	X: Numpad: 1, 4\n\
	Y: Numpad: 2, 5\n\
	Z: Numpad: 3, 6\n\
\n\
Zoom:\n\
	IN: Numpad: +\n\
	OUT: Numpad: -\n\
____________________________\n\
");
}

int		main(int argc, char **argv)
{
	t_env	*e;
	t_map	*map;

	if (argc == 2)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			fdf_malloc_error();
		map = ft_parse_map(argv, 0);
		if (map->len == 0 || map->lines[0]->len == 0)
			fdf_map_error();
		e->map = map;
		get_center(e);
		display_controls();
		draw_windows("Debaz's Fdf", WINDOW_SIZE_W, WINDOW_SIZE_H, e);
		adapt_map(e);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, 2, 3, key_hook, e);
		mlx_loop(e->mlx);
	}
	else
		fdf_arg_error();
	return (0);
}
