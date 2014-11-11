/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:06:55 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/11 13:54:50 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>

# define SIZE_X 800
# define SIZE_Y 600
# define TITLE "Visualisateur Fil de Fer - by Debaz"
# define ABS(x) ((( x ) < 0 ) ? - ( x ) : ( x ))

typedef struct			s_screen
{
	void		*mlx_ptr;
	void		*win_ptr;
}						t_screen;

typedef struct			s_point
{
	int		x;
	int		y;
}						t_point;

void		draw_segment(t_screen screen, t_point a, t_point b);

#endif
