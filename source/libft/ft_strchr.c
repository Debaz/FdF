/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:07:03 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:07:04 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char*)s;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		else
			i++;
	}
	return (NULL);
}
