/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:12:06 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:12:06 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*check_str(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ptr;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i] != s2[j] && s1[i])
			i++;
		ptr = i;
		while (s1[i] == s2[j] && s1[i])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)&s1[ptr]);
		ptr = 0;
		j = 0;
	}
	return (NULL);
}

char	*ft_strstr(const char *s1, const char *s2)
{
	if (s2 == NULL)
		return (NULL);
	if (s2[0] == '\0')
		return ((char*)s1);
	return (check_str(s1, s2));
}
