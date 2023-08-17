/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:06:17 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/17 09:56:23 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s[lenght] != NULL_BYTE)
	{
		lenght++;
	}
	return (lenght);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*first_occ;

	if (s == NULL)
		return (NULL);
	index = 0;
	first_occ = NULL;
	while (s[index] != NULL_BYTE)
	{
		if (s[index] == (unsigned char)c)
		{
			first_occ = (char *)&s[index];
			return (first_occ);
		}
		index++;
	}
	if ((unsigned char)c == NULL_BYTE)
	{
		first_occ = (char *)&s[index];
	}
	return (first_occ);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_mem;
	char	*temp;
	size_t	full_size;
	size_t	index;

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
		temp[index] = NULL_BYTE;
		index++;
	}
	return ((void *)allocated_mem);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		result_index;
	int		index;
	char	*result;

	if (s1 == NULL)
		s1 = ft_calloc(1, sizeof(char));
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result_index = 0;
	index = 0;
	while (s1[index])
	{
		result[result_index++] = s1[index++];
	}
	index = 0;
	while (s2[index])
	{
		result[result_index++] = s2[index++];
	}
	result[result_index] = NULL_BYTE;
	free((char *)s1);
	return (result);
}
