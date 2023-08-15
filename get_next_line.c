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

static char	*ft_get_lines(int fd, char *memory_str);
static char	*ft_actual_line(char *memory_str, char *line);
static char	*ft_get_rest(char *memory_str);

char	*get_next_line(int fd)
{
	static char	*memory_str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	memory_str = ft_get_lines(fd, memory_str);
	if (memory_str == NULL)
		return (NULL);
	line = NULL;
	line = ft_actual_line(memory_str, line);
	memory_str = ft_get_rest(memory_str);
	return (line);
}

static char	*ft_get_lines(int fd, char *memory_str)
{
	char	*tmp;
	int		tmp_len;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp_len = -1;
	while ((ft_strchr(memory_str, '\n')) == NULL && tmp_len != 0)
	{
		tmp_len = read(fd, tmp, BUFFER_SIZE);
		if (tmp_len < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[tmp_len] = '\0';
		memory_str = ft_strjoin(memory_str, tmp);
	}
	free(tmp);
	return (memory_str);
}

static char	*ft_actual_line(char *memory_str, char *line)
{
	int	count;

	if (memory_str[0] == '\0')
		return (NULL);
	count = 0;
	while (memory_str[count] != '\0' && memory_str[count] != '\n')
		count++;
	if (memory_str[count] == '\0')
		line = malloc((count + 1) * sizeof(char));
	else if (memory_str[count] == '\n')
		line = malloc((count + 2) * sizeof(char));
	if (line == NULL)
		return (NULL);
	count = 0;
	while (memory_str[count] != '\0' && memory_str[count] != '\n')
	{
		line[count] = memory_str[count];
		count++;
	}
	if (memory_str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

static char	*ft_get_rest(char *memory_str)
{
	char	*tmp;
	size_t	count;
	size_t	count_tmp;

	count = 0;
	while (memory_str[count] != '\n' && memory_str[count] != '\0')
		count++;
	count_tmp = count;
	if (memory_str[count_tmp] == '\0' || memory_str[0] == '\0')
	{
		free(memory_str);
		return (NULL);
	}
	tmp = malloc((ft_strlen(memory_str) - count_tmp) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	count = 0;
	while (memory_str[++count_tmp] != '\0')
	{
		tmp[count] = memory_str[count_tmp];
		count++;
	}
	tmp[count] = '\0';
	free(memory_str);
	return (tmp);
}
