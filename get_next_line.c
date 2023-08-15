/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:06:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/09 10:06:15 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;
	int			byte_nb;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (rest == NULL)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		byte_nb = 1;
		while (byte_nb > 0)
		{
			byte_nb = read(fd, buffer, BUFFER_SIZE);
			if (!(byte_nb <= 0))
			{
				buffer[byte_nb] = '\0';
				rest = buffer;
			}
		}
	}

	t_list *list;
    t_char *current_node;

	list = ft_new_list();
	current_node = NULL;
    
    while (*rest != '\n')
    {
        if (list->head == NULL)
        {
            list->head = ft_new_node(*rest);
            current_node = list->head;
        }
        else
        {
            current_node->next = ft_new_node(*rest);
            current_node = current_node->next;
        }
        rest++;
    }
    
    if (*rest == '\n')
	{
        rest++;
	}
	
	/* int node_count = 0;
    current_node = list->head;
    while (current_node != NULL)
    {
        node_count++;
		//printf("%c", current_node->act_char);
        current_node = current_node->next;
    }
	printf("%d\n", node_count); */
    // line = (char *)malloc((node_count + 1) * sizeof(char));
    // if (line == NULL)
    //     return (NULL);

    // current_node = list->head;
    // int i = 0;
    // while (current_node != NULL)
    // {
    //     line[i++] = current_node->act_char;
    //     t_char *temp = current_node;
    //     current_node = current_node->next;
    //     free(temp);
    // }
    // line[i] = '\0';
    // list->head = NULL;

    // return (line);
}
