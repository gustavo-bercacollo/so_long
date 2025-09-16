/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbercaco <gbercaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:38:35 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/15 19:54:24 by gbercaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_mandatory.h"

int	check_ber_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = strlen(filename);
	if (len < 5)
		return (0);
	if (strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

t_map	*validate_and_read_map(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		printf("Usage: ./so_long <map.ber>\n");
		return (NULL);
	}
	if (!check_ber_extension(argv[1]))
	{
		printf("Error\nInvalid file extension. Expected .ber\n");
		return (NULL);
	}
	map = read_map(argv[1]);
	if (!map)
		printf("Error to read the map!\n");
	return (map);
}
