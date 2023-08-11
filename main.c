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
#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	const char	*file_name = argv[1];
	char		*c_line;
	FILE		*file;
	int			counter;

	if (argc != 2)
	{
		printf("Please, enter a valid file name.\n");
		return (0);
	}
	file = fopen(file_name, "r");

	while ((c_line = get_next_line(file->_fileno)) != NULL)
	{
		printf("Line %i -> %s", counter++, c_line);
		free(c_line);
	}
	fclose(file);
	return (0);
}
