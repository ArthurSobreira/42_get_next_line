/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .get_next_line_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:32:51 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/17 16:58:02 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_current_line(char *total_buffer);
static char	*ft_get_buffer_rest(char *total_buffer);

// static char	*ft_fill_buffer(int fd, char *total_buffer)
// {
// 	char	*buffer;
// 	int		buffer_len;

// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (buffer == NULL)
// 		return (NULL);
// 	buffer_len = -1;
// 	while ((ft_strchr(total_buffer, NEW_LINE)) == NULL && buffer_len != 0)
// 	{
// 		buffer_len = read(fd, buffer, BUFFER_SIZE);
// 		if (buffer_len < 0)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[buffer_len] = NULL_BYTE;
// 		total_buffer = ft_strjoin(total_buffer, buffer);
// 	}
// 	free(buffer);
// 	return (total_buffer);
// }

char	*get_next_line(int fd)
{
	static char	*total_buffer[1024];
	char		*temp_buffer;
	char		*current_line;
	int			byte_nb;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	temp_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	byte_nb = 1;
	while (!(ft_strchr(total_buffer[fd], NEW_LINE)) && (byte_nb != 0))
	{	
		byte_nb = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_nb == -1)
			return (free(temp_buffer), NULL);
		temp_buffer[byte_nb] = NULL_BYTE;
		total_buffer[fd] = ft_strjoin(total_buffer[fd], temp_buffer);
		if (total_buffer[fd] == NULL)
			return (free(total_buffer[fd]), NULL);
	}
	free(temp_buffer);
	current_line = NULL;
	current_line = ft_get_current_line(total_buffer[fd]);
	total_buffer[fd] = ft_get_buffer_rest(total_buffer[fd]);
	return (current_line);
}

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
		return (free(total_buffer), NULL);
	rest = malloc((ft_strlen(total_buffer) - count_buffer) * sizeof(char));
	if (rest == NULL)
		return (NULL);
	count = 0;
	while (total_buffer[++count_buffer] != NULL_BYTE)
	{
		rest[count] = total_buffer[count_buffer];
		count++;
	}
	rest[count] = NULL_BYTE;
	free(total_buffer);
	return (rest);
}
