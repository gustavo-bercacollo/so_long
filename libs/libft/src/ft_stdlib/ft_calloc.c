/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:28 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 21:28:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for an array of 'nmemb' elements of 'size' bytes each.
** Initializes all bytes in the allocated memory to zero.
** Returns a pointer to the allocated memory, or NULL if the allocation fails
** or if an overflow occurs during the multiplication of 'nmemb' by 'size'.
*/

#include "ft_stdlib.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
