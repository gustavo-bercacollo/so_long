/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:06:19 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:09:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_isprint - Checks if the character is printable.
**
** @param c: The character to check.
** @return: 1 if 'c' is between 32 and 126 (inclusive), else 0.
**
** Printable characters include letters, digits, symbols, and space.
*/

#include "ft_ctype.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}
