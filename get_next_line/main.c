/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:09:46 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/17 12:45:49 by aursuare         ###   ########.fr       */
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
	int		j;

	if (argc < 2)
	{
		printf("Ha olvidado el fichero.\n");
        return (1);
	}
	i = 1;
	while (index < argc)
	{
		fd = open(argv[i], O_RDONLY);
		printf("Archivo: %s\n", argv[i]);
		j = 0;
		line = get_next_line_bonus(fd);
		while (line != NULL)
		{
			j++;
			printf("line [%02d]: %s", j, line);
			free(line);
			line = get_next_line_bonus(fd);
		}
	close(fd);
	}
	return (0);
}

// Compilar con "cc -Wall -Werror -Wextra -D BUFFER_SIZE=?? get_next_line.c get_next_line_utils.c main.c"
// BONUS "cc -Wall -Werror -Wextra -D BUFFER_SIZE=?? get_next_line_bonus.c get_next_line_utils_bonus.c main.c"

