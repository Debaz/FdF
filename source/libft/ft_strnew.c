/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:11:11 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:11:11 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnew(size_t size)
{
	unsigned int	i;
	char			*str;

	if (size == 0)
		return (NULL);
	str = malloc(sizeof(*str) * (size + 1));
	str[size] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
