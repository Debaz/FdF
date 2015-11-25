/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:19:24 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:24:47 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# define Y_WIN 1920
# define X_WIN 1220
# include <errno.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

/*
** =============================  t y p e d e f ===============================
*/

typedef struct s_mlx_env	t_mlx_env;
typedef struct s_coloor		t_coloor;

/*
** ===========================  s t r u c t u r e =============================
**xy[0] =x;
**xy[1] =y;
**xy[2] =x1;
**xy[3] =x2;
**xy[4] =y1;
**xy[5] =y2;
*/

struct		s_mlx_env
{
	void	*mlx;
	void	*win;
	char	**map;
	int		**int_map;
	int		***tab_i;
	int		xy[6];
	int		dx;
	int		dy;
	int		i[2];
};

/*
** ===========================  p r o t o t y p e =============================
*/
t_mlx_env	*g_mlx_env();
char		**ft_open(char *av);
int			**convert_map_to_int(t_mlx_env *mlx_e);
int			ft_color(t_mlx_env *mlx_e);
int			ft_core(void);
int			expose_hook(t_mlx_env *mlx_e);
int			key_hook(int keycode);
int			***my_tab(int **tab);
void		ft_error_bc(char *s);
void		ft_error(int ac);
void		mlx_draw(t_mlx_env *mlx_e);
void		ft_size_map(char **map, int *y, int *x);
void		ft_partie1_b(int dx, int dy, t_mlx_env *mlx_e);
void		ft_partie1_a(int dx, int dy, t_mlx_env *mlx_e);
void		ft_partie1(int dx, int dy, t_mlx_env *mlx_e);
void		my_algo(t_mlx_env *mlx_e);
void		my_algo_next(t_mlx_env *mlx_e);
void		ligne_x(t_mlx_env *mlx_e, int ***tab_i);
void		ligne_y(t_mlx_env *mlx_e, int ***tab_i);
void		ft_cake_lieb(int dy, int dx, t_mlx_env *mlx_e);
void		ft_cakeb(int dy, int dx, t_mlx_env *mlx_e);
void		ft_gateau_lieb(int dy, int dx, t_mlx_env *mlx_e);
void		ft_gateaub(int dy, int dx, t_mlx_env *mlx_e);
void		ft_cake_lie(int dx, int dy, t_mlx_env *mlx_e);
void		ft_cake(int dx, int dy, t_mlx_env *mlx_e);
void		ft_gateau_lie(int dx, int dy, t_mlx_env *mlx_e);
void		ft_gateau(int dx, int dy, t_mlx_env *mlx_e);
int			c_is_map(char c);
#endif
