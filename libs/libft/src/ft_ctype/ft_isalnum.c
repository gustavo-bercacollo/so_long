/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:23:30 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:09:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if a character is alphanumeric (letter or digit).
** Returns 1 if it is a letter (A-Z, a-z) or digit (0-9), otherwise 0.
*/

#include "ft_ctype.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
