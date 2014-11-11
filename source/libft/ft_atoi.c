/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 11:58:39 by klescaud          #+#    #+#             */
/*   Updated: 2014/04/23 11:58:49 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_nbrlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int		ft_additionner(const char *str, int sign)
{
	int		i;
	int		ret;
	int		len;

	i = 0;
	ret = 0;
	len = ft_nbrlen(str);
	while (i < len)
	{
		ret = ret + sign * (str[len - 1 - i] - '0') * ft_pow(10, i);
		i++;
	}
	return (ret);
}

int				ft_atoi(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] >= 0 && str[i] <= 32)
		i++;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (0);
	if (str[i] == '-')
		return (ft_additionner(str + i + 1, -1));
	if (str[i] == '+')
		return (ft_additionner(str + i + 1, 1));
	return (ft_additionner(str + i, 1));
}
