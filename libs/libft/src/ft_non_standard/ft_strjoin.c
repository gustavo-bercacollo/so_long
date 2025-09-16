/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:15:13 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:21:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/ft_non_standard.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	char	*temp;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	temp = new_str;
	if (!new_str)
		return (NULL);
	while (*s1)
		*new_str++ = *s1++;
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	return (temp);
}
