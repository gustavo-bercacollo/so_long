/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:23:46 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 21:28:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts a string to an integer (int).
** Skips whitespace, handles '+' or '-' signs,
** and processes only consecutive digit characters.
*/

#include "ft_stdlib.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9
			&& nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
