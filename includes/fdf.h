/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:06:55 by klescaud          #+#    #+#             */
/*   Updated: 2014/11/11 13:20:39 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>

# define SIZE_X 800
# define SIZE_Y 600
# define TITLE "Visualisateur Fil de Fer - by Debaz"

typedef struct			s_screen
{
	void		*mlx_ptr;
	void		*win_ptr;
}						t_screen;

#endif
