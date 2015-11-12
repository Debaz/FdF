/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 11:19:33 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/12 11:23:07 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "libft/includes/libft.h"

int				expose_hook(t_mlx_env *mlx_e)
{
	mlx_draw(mlx_e);
	return (0);
}

int				ft_core(void)
{
	t_mlx_env	mlx_e;

	mlx_e.mlx = mlx_init();
	mlx_e.win = mlx_new_window(mlx_e.mlx, Y_WIN, X_WIN, "FdF");
	mlx_key_hook(mlx_e.win, key_hook, &mlx_e);
	mlx_expose_hook(mlx_e.win, expose_hook, &mlx_e);
	mlx_loop(mlx_e.mlx);
	return (0);
}

char			**ft_open(char *av)
{
	char		buf[33];
	char		**map;
	char		*file;
	int			fd;
	int			ret;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error_bc("file not opened");
	file = ft_strnew(1);
	while ((ret = read(fd, buf, 32)) >= 0)
	{
		buf[ret] = '\0';
		file = ft_strjoin(file, buf);
		if (ret < 32)
			break ;
	}
	if (ret == -1)
		ft_error_bc("file not reading");
	close(fd);
	map = ft_strsplit(file, '\n');
	free(file);
	file = NULL;
	return (map);
}

int				main(int ac, char **av)
{
	char		**map;
	int			i[2];

	ft_error(ac);
	if (ac == 2)
	{
		map = ft_open(av[1]);
		if (*map == NULL)
			ft_error(4242);
		g_mlx_env()->map = map;
		ft_size_map(g_mlx_env()->map, &i[0], &i[1]);
		g_mlx_env()->i[0] = i[0];
		g_mlx_env()->i[1] = i[1];
		ft_core();
	}
	return (0);
}
