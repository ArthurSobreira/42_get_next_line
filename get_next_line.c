/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:06:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/17 19:15:33 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_current_line(char *total_buffer);
static char	*ft_get_buffer_rest(char *total_buffer);
//static char	*ft_fill_buffer(int fd, char *total_buffer);

char	*get_next_line(int fd)
{
	static char	*total_buffer;
	char		*temp_buffer;
	char		*current_line;
	int			byte_nb;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (temp_buffer == NULL)
		return (NULL);
	byte_nb = -1;
	while (!(ft_strchr(total_buffer, NEW_LINE)) && (byte_nb != 0))
	{	
		byte_nb = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_nb < 0)
			return (free(temp_buffer), NULL);
		temp_buffer[byte_nb] = NULL_BYTE;
		total_buffer = ft_strjoin(total_buffer, temp_buffer);
	}
	free(temp_buffer);
	current_line = NULL;
	current_line = ft_get_current_line(total_buffer);
	total_buffer = ft_get_buffer_rest(total_buffer);
	return (current_line);
}

// char	*get_next_line(int fd)
// {
// 	static char	*total_buffer;
// 	char		*current_line;

// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	total_buffer = ft_fill_buffer(fd, total_buffer);
// 	if (total_buffer == NULL)
// 		return (NULL);
// 	current_line = NULL;
// 	current_line = ft_get_current_line(total_buffer);
// 	total_buffer = ft_get_buffer_rest(total_buffer);
// 	return (current_line);
// }

static char	*ft_get_current_line(char *total_buffer)
{
	char		*line;
	int			count;

	if (total_buffer[0] == NULL_BYTE)
		return (NULL);
	count = 0;
	while ((total_buffer[count] != NULL_BYTE) && \
			(total_buffer[count] != NEW_LINE))
		count++;
	if (total_buffer[count] == NEW_LINE)
		line = malloc((count + 2) * sizeof(char));
	else if (total_buffer[count] == NULL_BYTE)
		line = malloc((count + 1) * sizeof(char));
	count = 0;
	while ((total_buffer[count] != NULL_BYTE) && \
			(total_buffer[count] != NEW_LINE))
	{
		line[count] = total_buffer[count];
		count++;
	}
	if (total_buffer[count] == NEW_LINE)
		line[count++] = NEW_LINE;
	line[count] = NULL_BYTE;
	return (line);
}

static char	*ft_get_buffer_rest(char *total_buffer)
{
	char	*rest;
	size_t	count;
	size_t	count_buffer;

	count = 0;
	while ((total_buffer[count] != NEW_LINE) && \
			(total_buffer[count] != NULL_BYTE))
		count++;
	count_buffer = count;
	if ((total_buffer[count_buffer] == NULL_BYTE) || \
		(total_buffer[0] == NULL_BYTE))
	{
		free(total_buffer);
		return (NULL);
	}
	rest = malloc((ft_strlen(total_buffer) - count_buffer) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	count = 0;
	while (total_buffer[++count_buffer] != NULL_BYTE)
		rest[count++] = total_buffer[count_buffer];
	rest[count] = NULL_BYTE;
	free(total_buffer);
	return (rest);
}

// static char	*ft_fill_buffer(int fd, char *total_buffer)
// {
// 	char	*temp_buffer;
// 	int		buffer_len;

// 	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (temp_buffer == NULL)
// 		return (NULL);
// 	buffer_len = -1;
// 	while (!(ft_strchr(total_buffer, NEW_LINE)) && (buffer_len != 0))
// 	{
// 		buffer_len = read(fd, temp_buffer, BUFFER_SIZE);
// 		if (buffer_len < 0)
// 		{
// 			free(temp_buffer);
// 			return (NULL);
// 		}
// 		temp_buffer[buffer_len] = NULL_BYTE;
// 		total_buffer = ft_strjoin(total_buffer, temp_buffer);
// 	}
// 	free(temp_buffer);
// 	return (total_buffer);
// }
