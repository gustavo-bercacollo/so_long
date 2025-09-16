/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:32:10 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 23:19:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_non_standard/get_next_line_bonus.h"

static void	*free_buff(void *buf)
{
	if (buf)
		free(buf);
	return (NULL);
}

static void	*free_buf_and_stock(void *buf, char **stock)
{
	if (buf)
		free(buf);
	if (stock && *stock)
	{
		free(*stock);
		*stock = NULL;
	}
	return (NULL);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*extract_line(char **stock)
{
	int		len;
	char	*line;
	char	*new_stock;

	if (*stock == NULL || **stock == '\0')
		return (NULL);
	len = 0;
	while ((*stock)[len] && (*stock)[len] != '\n')
		len++;
	if ((*stock)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *stock, len);
	line[len] = '\0';
	new_stock = ft_strdup(*stock + len);
	free(*stock);
	*stock = new_stock;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock[STOCK_MAX];
	char		*buf;
	ssize_t		bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stock[fd], '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes > 0)
		{
			buf[bytes] = '\0';
			stock[fd] = ft_strjoin_free(stock[fd], buf);
			if (!stock[fd])
				return (free_buff(buf));
		}
	}
	if (bytes < 0 || (bytes == 0 && (!stock[fd] || *stock[fd] == '\0')))
		return (free_buf_and_stock(buf, (&stock[fd])));
	free(buf);
	return (extract_line(&stock[fd]));
}
