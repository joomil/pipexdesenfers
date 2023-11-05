/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:07:16 by jmilesi           #+#    #+#             */
/*   Updated: 2023/04/18 17:21:48 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	word_len(char const *s, char c);
static char	**free_strs(char **strs, int i);
static char	**copy_words(char **strs, char const *s, char c, int nbr_words);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		nbr_words;

	if (!s)
		return (NULL);
	nbr_words = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!strs)
		return (NULL);
	strs = copy_words(strs, s, c, nbr_words);
	if (!strs)
		return (NULL);
	strs[nbr_words] = NULL;
	return (strs);
}

static int	count_words(char const *s, char c)
{
	int		nbr_words;
	int		i;

	nbr_words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nbr_words++;
		i++;
	}
	return (nbr_words);
}

static int	word_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static char	**free_strs(char **strs, int i)
{
	while (i--)
		free(strs);
	free(strs);
	return (NULL);
}

static char	**copy_words(char **strs, char const *s, char c, int nbr_words)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < nbr_words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		strs[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!strs)
			return (free_strs(strs, i));
		j = 0;
		while (j < len)
			strs[i][j++] = *s++;
		strs[i++][j] = '\0';
	}
	return (strs);
}
