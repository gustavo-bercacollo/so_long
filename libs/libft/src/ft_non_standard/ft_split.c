/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:52:22 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:21:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"

static int	count_words(const char *s, char c)
{
	int	n_words;

	n_words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			n_words++;
		s++;
	}
	return (n_words);
}

static char	*split_word(const char *start, const char *end)
{
	char	*word;
	int		size;
	int		i;

	size = end - start;
	word = malloc(size + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

static char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char		**splited;
	const char	*start;
	int			i;

	splited = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			splited[i] = split_word(start, s);
			if (!splited[i])
				return (free_split(splited));
			i++;
		}
		else
			s++;
	}
	splited[i] = NULL;
	return (splited);
}
