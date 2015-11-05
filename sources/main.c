/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 12:50:25 by klescaud          #+#    #+#             */
/*   Updated: 2015/11/05 12:53:34 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					count_line(char *file)
{
	char		str;
	int			fd;
	int			nb_line;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &str, 1))
	{
		if (str == '\n')
			nb_line++;
	}
	close(fd);
	return (nb_line);
}

int					count_column(char **split)
{
	int			i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

int					**read_file_fdf(char *file, int *line, int *col)
{
	int			fd;
	char		**str;
	char		**split;
	int			**point;

	str = (char **) malloc(sizeof(char *));
	point = (int **) malloc(sizeof(int *) * count_line(file));
	fd = open(file, O_RDONLY);
	*line = 0;
	while (get_next_line(fd, str))
	{
		split = ft_strsplit(*str, ' ');
		point[*line] = (int *) malloc(sizeof(int) * count_column(split));
		*col = 0;
		while (split[*col] != NULL)
		{
			point[*line][*col] = ft_atoi(split[*col]);
			(*col)++;
		}
		(*line)++;
	}
	close(fd);
	return (point);
}

void				ft_init_mlx(t_env *e, int line, int col, int siz)
{
	int			width;
	int			height;

	width = col * siz - siz + 11;
	height = line * siz - siz + 11;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, width, height, "42");
}

int					main(int argc, char **argv)
{
	int			line;
	int			col;
	t_env		e;
	int			**point;

	if (argc < 2)
		return (0);
	point = read_file_fdf(argv[1], &line, &col);
	e.zoom = 25;
	if (argv[2] == NULL)
		ft_init_mlx(&e, line, col, e.zoom);
	else if (ft_atoi(argv[2]) >= 1 && ft_atoi(argv[2]) <= 100)
	{
		e.zoom = ft_atoi(argv[2]);
		ft_init_mlx(&e, line, col, e.zoom);
	}
	else
	{
		ft_putstr("Please enter a second argument between 1 and 100.\n");
		exit(-1);
	}
	draw_grid(point, &e, line, col);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
