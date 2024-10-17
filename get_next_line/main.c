/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:21:01 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/17 11:19:35 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(int argc, char *argv[])
{
	char	*line;
	int		i;
	int		fd;

	if (argc < 2)
	{
		printf("Ha olvidado el fichero.\n");
        return (1);
	}
	fd = open(argv[FOPEN_MAX], O_RDONLY);
	i = 0;
	line = get_next_line_bonus(fd);
	while (line != NULL)
	{
		i++;
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line_bonus(fd);
	}
	close(fd);
	return (0);
}

// Compilar con "cc -Wall -Werror -Wextra -D BUFFER_SIZE=?? get_next_line.c get_next_line_utils.c main.c"
