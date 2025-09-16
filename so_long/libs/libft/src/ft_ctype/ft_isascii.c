/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:56:43 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:09:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if the given character is part of the standard ASCII table.
** Returns 1 if the value is between 0 and 127 (inclusive), otherwise returns 0.
*/

#include "ft_ctype.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}
