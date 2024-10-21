/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:30:34 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/12 21:19:51 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_left(int fd, char *content)
{
	char	*buffer;
	int		r_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	r_bytes = 1;
	while (!ft_strchr(content, '\n') && r_bytes != 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r_bytes] = '\0';
		content = ft_strjoin(content, buffer);
	}
	free(buffer);
	return (content);
}

/*
- Mientras no encuentre '\n' en "content" (con strchr) y haya algo que leer,
	lee el archivo "fd" hasta la cantidad maxima de bytes (BUFFER_SIZE)
	almacenando la cantidad de bytes leidos en "r_bytes".

- Se va rellenando "content" concatenando los datos leidos y alamacenados n "buffer"
	con "ft_strjoin"
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	content = read_to_left(fd, content);
	if (!content)
		return (NULL);
	line = ft_get_line(content);
	content = new_content(content);
	return (line);
}

/* 
line:	linea que se lee y se retorna

content:	Mantiene los datos de llamadas anteriores. Al ser estatica, conserva su valor
	aunque llamemos varias veces a la funcion GNL.

read_to_left:	Si no hay datos suficientes en "content", lo rellena con la lectura del fd.
	Devuelve un string con todos los datos leidos, incluido el contenido ya existente.

get_line:	Extrae la primera linea del total leido (content).

new_content:	Actualiza "content" para eliminar la linea ya procesada (el contenido pasado a "line").
	Si ya no hay mas datos, libera la memoria y retorna NULL.
*/


