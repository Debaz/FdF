/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:08:13 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:08:13 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(sizeof(*str) * (ft_strlen(s1)) + 1);
	while (i < (ft_strlen(s1) + 1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
