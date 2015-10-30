/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 10:40:34 by klescaud          #+#    #+#             */
/*   Updated: 2015/10/30 10:55:06 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	*fdf_parse(int fd)
{
	char	*file;
	char	*tmp;

	file = ft_strnew(0);
	tmp = ft_strnew(0);
	while (read(fd, tmp, 1))
	{
		file = ft_strjoin(file, tmp);
		free(tmp);
		tmp = ft_strnew(0);
	}
	return (file);
}
