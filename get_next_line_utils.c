/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:06:17 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/09 13:51:32 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void 	*allocated_mem;
	char 	*temp;
	size_t 	full_size;
	size_t 	index;

	full_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (full_size > __INT_MAX__ || full_size / nmemb != size)
		return (NULL);
	allocated_mem = (void *)malloc(full_size);
	if (allocated_mem == NULL)
		return (NULL);
	index = 0;
	temp = (char *)allocated_mem;
	while (index < full_size)
	{
		temp[index] = '\0';
		index++;
	}
	return ((void *)allocated_mem);
}

t_char	*ft_new_node(char c)
{
	t_char	*new_node;

	new_node = (t_char *)ft_calloc(1, sizeof(t_char));
	if (new_node == NULL)
		return (NULL);
	new_node->act_char = c;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_new_list(void)
{
	t_list	*new_list;

	new_list = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->head = NULL;
	return (new_list);
}
