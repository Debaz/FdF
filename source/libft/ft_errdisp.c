/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errdisp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/12 20:43:20 by klescaud          #+#    #+#             */
/*   Updated: 2014/10/12 20:43:21 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_errdisp(char *message)
{
	ft_putstr("\033[31mError: ");
	if (message)
		ft_putendl_fd(message, 2);
	ft_putstr("\033[0m");
	_exit(EXIT_FAILURE);
}
