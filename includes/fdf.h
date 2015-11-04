/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:20:12 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/04 11:10:17 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define ABS(x)			(x >= 0 ? x : -x)
# define MIN(x, y)		(x >= y ? y : x)
# define BUFSIZE		1024
# define WIN_X			2000
# define WIN_Y			1000
# define CSTX			0.65
# define CSTY			0.80
# define CSTZ			0.04

typedef struct		s_point
{
	float		x;
	float		y;
	float		z;
}					t_point;

typedef struct		s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sline;
	int			endian;
	t_point		*map;
	t_point		max;
	t_point		trans;
	t_point		cst;
	float		mult;
	int			map_size;
}					t_mlx;

void		aff_fdf(t_mlx *mlx);
void		get_map(t_mlx *mlx, char *totalbuf);
void		pxl_putimg(t_mlx *mlx, int x, int y, unsigned int color);
void		iso_coord(t_mlx *mlx, int pos, t_point *coord, int is_calc);
int			ft_putstr(char *str);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_atoi(const char *str);
#endif
