/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:52:38 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:21:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"

static int	in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimmed;
	int		start;
	int		end;
	int		size;
	int		i;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	size = end - start;
	str_trimmed = malloc(size + 1);
	if (!str_trimmed)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str_trimmed[i] = s1[start];
		start++;
		i++;
	}
	str_trimmed[i] = '\0';
	return (str_trimmed);
}
