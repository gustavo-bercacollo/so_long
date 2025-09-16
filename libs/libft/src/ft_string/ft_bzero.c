/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:29:13 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 21:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets the first 'n' bytes of the memory area pointed to by 's'
** to zero (0), clearing the memory.
*/

#include "ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
