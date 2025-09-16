/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:20:29 by gbercaco          #+#    #+#             */
/*   Updated: 2025/09/02 21:24:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_box;

	new_box = malloc(sizeof(t_list));
	if (!new_box)
		return (NULL);
	new_box->content = content;
	new_box->next = NULL;
	return (new_box);
}
