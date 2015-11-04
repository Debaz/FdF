/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 12:11:25 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/04 12:12:27 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			ft_put_help(t_coord *e, int m_x, int m_y)
{
	int		tmp_x;
	int		tmp_y;
	int		x;
	int		y;

	x = e->sqr_x;
	y = e->sqr_y;
	tmp_x = e->sqr_x;
	tmp_y = e->sqr_y;
	while (x != m_x)
		ft_put_px(e, (x++ - e->move_x), (y - e->move_y));
	while (y != m_y)
		ft_put_px(e, (x - e->move_x), (y++ - e->move_y));
	while (x != tmp_x)
		ft_put_px(e, (x-- - e->move_x), (y - e->move_y));
	while (y != tmp_y)
		ft_put_px(e, (x - e->move_x), (y-- - e->move_y));
}

void			ft_write_op(t_coord *e)
{
	mlx_string_put(e->mlx, e->win, 35, 35, 0xAFAFAF, "Quit = esc");
	mlx_string_put(e->mlx, e->win, 35, 55, 0xFFFFFF, "Move up = ^");
	mlx_string_put(e->mlx, e->win, 35, 75, 0xFFFFFF, "Move down = v");
	mlx_string_put(e->mlx, e->win, 35, 95, 0xFFFFFF, "Move left = <");
	mlx_string_put(e->mlx, e->win, 35, 115, 0xFFFFFF, "Move right = >");
	mlx_string_put(e->mlx, e->win, 35, 135, 0xAFAFAF, "Zoom +: + / scroll up");
	mlx_string_put(e->mlx, e->win, 35, 155, 0xAFAFAF, "Zoom -: - / scroll dwn");
}
