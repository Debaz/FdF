/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:20:12 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/05 13:11:42 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include <libft.h>
# include <fcntl.h>
# include <stdio.h>

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		zoom;
}					t_env;

typedef struct		s_coord
{
	int		x;
	int		y;
	int		point;
}					t_coord;

void		ft_init_mlx(t_env *e, int line, int col, int size);
int			key_hook(int keycode);
int			**read_file_fdf(char *file, int *line, int *col);
int			count_column(char **split);
int			count_line(char *file);
void		draw_grid(int **point, t_env *e, int line, int col);
void		draw_line(t_env *e, t_coord start, t_coord end);
t_coord		**stock_coord(int **point, int line, int coli, t_env *e);
t_coord		*define_coord(int x, int y, int z, t_env *e);
void		define_first_coord(t_coord *pos, int x, int y, int z);
int			ft_sqrt(int nb);
int			ft_pow(int nb, unsigned int p);

#endif
