/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:09:29 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:09:30 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strlcat_concatenate(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	char			*src2;
	size_t			n;

	src2 = (char*)src;
	n = size;
	i = 0;
	j = 0;
	while (n - 1 > 0 && dst[i])
	{
		n--;
		i++;
	}
	while (n - 1 > 0 && src2[j])
	{
		dst[i] = src2[j];
		n--;
		i++;
		j++;
	}
	dst[i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	length;

	length = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	else if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
		ft_strlcat_concatenate(dst, src, size);
	return (length + ft_strlen(src));
}
