/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:06:14 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/22 12:02:57 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static char	*ft_fill_buffer(int fd, char *total_buffer);
static char	*ft_get_current_line(char *total_buffer);
static char	*ft_get_buffer_rest(char *total_buffer);

char	*get_next_line(int fd)
{
	static char	*total_buffer;
	char		*current_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	total_buffer = ft_fill_buffer(fd, total_buffer);
	if (total_buffer == NULL)
	{
		return (NULL);
	}
	current_line = NULL;
	current_line = ft_get_current_line(total_buffer);
	total_buffer = ft_get_buffer_rest(total_buffer);
	return (current_line);
}

static char	*ft_fill_buffer(int fd, char *total_buffer)
{
	char	*temp_buffer;
	int		byte_nb;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp_buffer == NULL)
		return (NULL);
	byte_nb = 1;
	while (!(ft_strchr(total_buffer, '\n')) && (byte_nb != 0))
	{
		byte_nb = read(fd, temp_buffer, BUFFER_SIZE);
		if (byte_nb < 0)
		{
			free(temp_buffer);
			free(total_buffer);
			return (NULL);
		}
		temp_buffer[byte_nb] = '\0';
		total_buffer = ft_strjoin(total_buffer, temp_buffer);
	}
	free(temp_buffer);
	return (total_buffer);
}

static char	*ft_get_current_line(char *total_buffer)
{
	char	*current_line;
	char	*newline_position;
	size_t	line_len;

	if (total_buffer[0] == '\0')
		return (NULL);
	newline_position = ft_strchr(total_buffer, '\n');
	if (newline_position != NULL)
	{
		line_len = 0;
		while (&total_buffer[line_len] != newline_position)
			line_len++;
	}
	else
		line_len = ft_strlen(total_buffer);
	current_line = malloc((line_len + 2) * sizeof(char));
	if (current_line == NULL)
		return (NULL);
	current_line = ft_strncpy(current_line, total_buffer, line_len);
	if (newline_position != NULL)
	{
		current_line[line_len++] = '\n';
	}
	current_line[line_len] = '\0';
	return (current_line);
}

static char	*ft_get_buffer_rest(char *total_buffer)
{
	char	*rest;
	char	*newline_position;

	rest = NULL;
	newline_position = ft_strchr(total_buffer, '\n');
	if (newline_position != NULL)
	{
		rest = ft_strdup(newline_position + 1);
	}
	free(total_buffer);
	return (rest);
}
