/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:46:03 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:09:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if the given character is an alphabetic letter.
** Returns 1 if it is a letter (uppercase or lowercase), otherwise returns 0.
*/

#include "ft_ctype.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
