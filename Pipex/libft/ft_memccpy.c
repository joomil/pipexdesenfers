/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:09:09 by jmilesi           #+#    #+#             */
/*   Updated: 2023/04/12 16:31:51 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	*d = (unsigned char *)dest;
	*s = (const unsigned char *)src;
	while (n > 0)
	{
		*d++ = *s++;
		if (*s == (unsigned char)c)
		{
			*d++ = *s++;
			return (d);
		}
		n--;
	}
	return (NULL);
}
