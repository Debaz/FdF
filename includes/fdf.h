/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/29 12:20:12 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/30 10:58:42 by klescaud         ###   ########.fr       */
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

char	*fdf_parse(int fd);

#endif
