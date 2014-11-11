/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:11:38 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:11:38 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	str = (char*)s;
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == (char)c)
			return (&str[i]);
	}
	return (NULL);
}
