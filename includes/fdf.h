/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:20:12 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/31 15:59:45 by Debaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <mlx.h>
# include <fcntl.h>

# define HEIGHT 500
# define LENGTH 500
# define TITLE "Debaz\'s fdf"

typedef struct		s_env{
	void	*mlx;
	void	*win;
}					t_env;

typedef struct		s_point{
	int		x;
	int		y;
	int		color;
	int		value;
}					t_point;

char	*fdf_parse(int fd);

#endif
