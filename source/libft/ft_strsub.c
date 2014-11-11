/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:12:21 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:12:21 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;

	if (s == NULL)
		return (NULL);
	result = ft_strnew(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strncpy(result, &s[start], len);
	return (result);
}
