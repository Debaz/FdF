/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:06:55 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/12 18:56:53 by klescaud         ###   ########.fr       */
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
# define SCALE 20

# define BLK 0000000000
# define WHT 0255255255
# define RED 0255000000
# define BLU 0000000255
# define YEL 0255255000
# define GRN 0000255000
# define PPL 0160032240
# define PNK 0238130238
# define ORG 0255165000
# define BWN 0139101008
# define GRY 0112128144

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
