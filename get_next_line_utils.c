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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	index = 0;
	while (index < s1_len)
	{
		new_str[index] = s1[index];
		index++;
	}
	index = 0;
	while (index < s2_len)
	{
		new_str[s1_len + index] = s2[index];
		index++;
	}
	free((char *)s1);
	return (new_str);
}

char	*ft_strchar(char *s, int c)
{
	size_t	index;
	char	*first_occ;

	index = 0;
	first_occ = NULL;
	while (index <= ft_strlen(s))
	{
		if (s[index] == (unsigned char) c)
		{
			first_occ = (char *)&s[index];
			return (first_occ);
		}
		index++;
	}
	return (first_occ);
}