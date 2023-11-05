/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:42:01 by jmilesi           #+#    #+#             */
/*   Updated: 2023/04/18 19:06:59 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char s[]);
size_t	ft_nbrlen(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
		sign = -1;
	i = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = (n % 10) * sign + '0';
		n /= 10;
		i--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

void	ft_strrev(char s[])
{
	int	c;
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

size_t	ft_nbrlen(int n)
{
	size_t	len;
	int		sign;

	len = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len + (sign == -1));
}
