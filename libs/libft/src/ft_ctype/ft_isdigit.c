/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:11:37 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:09:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if the given character is a decimal digit (0 to 9).
** Returns 1 if it is a number, otherwise returns 0.
*/

#include "ft_ctype.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
