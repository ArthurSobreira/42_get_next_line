/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:01:34 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/09 10:05:11 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

# include <unistd.h>
# include <stdlib.h>
 
typedef struct s_node
{
	char			act_char;
	struct s_node	*next;
}					t_char;

typedef struct s_list
{
	t_char	*head;
}			t_list;

t_char	*ft_new_node(char c);
t_list	*ft_new_list(void);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif