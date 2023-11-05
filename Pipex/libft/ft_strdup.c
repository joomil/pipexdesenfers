/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:49:24 by jmilesi           #+#    #+#             */
/*   Updated: 2023/04/12 16:57:21 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	str_len;

	str_len = ft_strlen(s1);
	result = malloc(str_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, str_len + 1);
	return (result);
}
