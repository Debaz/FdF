/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klescaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 12:00:57 by klescaud          #+#    #+#             */
/*   Updated: 2014/09/14 15:28:29 by klescaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_ten(int n)
{
	char	*ret;

	if (n > 0)
	{
		ret = malloc(sizeof(*ret) * 2);
		ret[0] = n + 48;
		ret[1] = '\0';
		return (ret);
	}
	else
	{
		ret = malloc(sizeof(*ret) * 3);
		ret[0] = '-';
		ret[1] = -n + 48;
		ret[2] = '\0';
		return (ret);
	}
}

char	*ft_itoa_zero(void)
{
	char	*ret;

	ret = malloc(sizeof(*ret) * 2);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa_negative(int n)
{
	unsigned int	i;
	unsigned int	length;
	unsigned int	uns_n;
	char			*ret;

	n = n * -1;
	uns_n = (unsigned int)n;
	length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	i = length;
	ret = malloc(sizeof(*ret) * (length + 2));
	while (i != 0)
	{
		ret[i] = uns_n % 10 + 48;
		uns_n = uns_n / 10;
		i--;
	}
	ret[length + 1] = '\0';
	ret[0] = '-';
	return (ret);
}

char	*ft_itoa_positive(int n)
{
	unsigned int	i;
	unsigned int	length;
	unsigned int	uns_n;
	char			*ret;

	uns_n = (unsigned int)n;
	length = 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	i = length;
	ret = malloc(sizeof(*ret) * (length + 1));
	while (i != 0)
	{
		ret[i - 1] = uns_n % 10 + 48;
		uns_n = uns_n / 10;
		i--;
	}
	ret[length] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	if ((n > 0 && n < 10) || (n < 0 && n > -10))
		return (ft_itoa_ten(n));
	else if (n == 0)
		return (ft_itoa_zero());
	else if (n <= -10)
		return (ft_itoa_negative(n));
	else
		return (ft_itoa_positive(n));
}
