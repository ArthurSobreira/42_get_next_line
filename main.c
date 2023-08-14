/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:41:02 by arsobrei          #+#    #+#             */
/*   Updated: 2023/08/09 19:29:33 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	const char	*file_name = "teste2.txt";
	char		*c_line;
	int			file_descriptor;
	int			counter;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
	{
		printf("Error opening file %s\n", file_name);
		return (1);
	}
	while ((c_line = get_next_line(file_descriptor)) != NULL)
	{
		printf("Line %i -> %s", counter++, c_line);
		free(c_line);
	}
	close(file_descriptor);
	return (0);
}
