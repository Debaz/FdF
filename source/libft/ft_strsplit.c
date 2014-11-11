/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:11:52 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 12:11:52 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		word_number(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			count++;
		}
		else
		{
			while (s[i] != c && s[i])
				i++;
		}
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

char	**word_write(char const *s, int c, char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			tab[k][j] = s[i];
			i++;
			j++;
		}
		if ((int)k < word_number(s, c))
			tab[k][j] = '\0';
		k++;
		j = 0;
	}
	tab[k] = '\0';
	return (tab);
}

int		*word_length(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	int				*length;

	i = 0;
	j = 0;
	length = malloc(sizeof(*length) * word_number(s, c));
	while (s[i])
	{
		count = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		length[j] = count;
		j++;
	}
	return (length);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	char			**tab;
	int				*length;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		tab = malloc(sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	tab = malloc(sizeof(char*) * (word_number(s, c) + 1));
	length = word_length(s, c);
	i = 0;
	while ((int)i < word_number(s, c))
	{
		tab[i] = malloc(sizeof(char) * (length[i] + 1));
		i++;
	}
	tab[i] = malloc(sizeof(char));
	tab = word_write(s, c, tab);
	return (tab);
}
