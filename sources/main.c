/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 10:50:00 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/04 11:03:23 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_key(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

static int 		get_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

char			*ft_perror(const char *str)
{
	perror(str);
	return (NULL);
}

char			*parse_arg(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUFSIZE];
	char	*totalbuf;

	totalbuf = NULL;
	if (ac != 2)
	{
		ft_putstr("usage : ./FdF file1\n");
		return (NULL);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_perror("FdF"));
	while ((ret = read(fd, buf, BUFSIZE)) > 0)
	{
		buf[ret] = 0;
		totalbuf = ft_strjoin(totalbuf, buf);
	}
	if (ret == -1 || close(fd) == -1)
		return (ft_perror("FdF"));
	if (!totalbuf)
		ft_putstr("FdF : map is empty\n");
	return (totalbuf);
}

int				main(int ac, char **av)
{
	t_mlx	mlx;
	char	*totalbuf;

	if ((totalbuf = parse_arg(ac, av)) == NULL)
		return (1);
	if ((mlx.ptr = mlx_init()) == NULL)
		return (ft_putstr("FdF: mlx_init failed\n"));
	if ((mlx.img = mlx_new_image(mlx.ptr, WIN_X, WIN_Y)) == NULL)
		return (ft_putstr("FdF: mlx_new_image failed\n"));
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sline, &mlx.endian);
	get_map(&mlx, totalbuf);
	if ((mlx.win = mlx_new_window(mlx.ptr, WIN_X,
								  WIN_Y, "Debaz\'s FdF")) == NULL)
		return (ft_putstr("FdF: mlx_new_window fail to work\n"));
	aff_fdf(&mlx);
	mlx_key_hook(mlx.win, &get_key, &mlx);
	mlx_expose_hook(mlx.win, &get_expose, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
