/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:19:44 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/30 10:59:01 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int ac, char **av)
{
//	t_env	e;
	int		fd;
	char	*file;

//	e.mlx = mlx_init();
//	e.win = mlx_new_window(e.mlx, HEIGHT, LENGTH, TITLE);
//	sleep(5);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		file = fdf_parse(fd);
		ft_putendl(file);
	}
	return (0);
}
