/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:31:42 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/12 21:20:17 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char *str)
{
	unsigned long int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

// Busca c (en este caso sera '\n') dentro del str.

char	*ft_strjoin(char *content, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!content)
	{
		content = (char *)malloc(1 * sizeof(char));
		content[0] = '\0';
	}
	if (!content || !buffer)
		return (NULL);
	str = malloc((ft_strlen(content) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (content[i++])
		str[i] = content[i];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(content) + ft_strlen(buffer)] = '\0';
	free(content);
	return (str);
}

/*
Concatena el contenido de "content", que ya se ha leido pero no procesado, y el buffer con los datos
	recien leidos.

- Si no hay nada en "content" (como sucede la primera vez que se llama a GNL), le asignamos memoria para
	contener un string vacio, ya que aun no se ha rellenado, esta todo el contenido en el buffer.

- Reservamos para "str" suficiente memoria para contener "content" y "buffer" + \0.

- Copiamos en "str" el contenido de "content" y despues el de "buffer" e incluimos el nulo final.
*/

char	*ft_get_line(char *content)
{
	int		i;
	char	*str;

	i = 0;
	if (!content[i])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		str[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
	{
		str[i] = content[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Toma el contenido de "content" y extrae la primera linea.

- Reserva memoria para la linea extraida (despues de comprovar la cantidad de caracteres hasta un
	salto de linea). Asigna "i + 2" para dar espacio a la linea + \n + \0.

- Se copia el contenido de "content" en "str" hasta el salto de linea y luego, si es que hay un
	\n, se copia tambien (en el if final).
*/

char	*new_content(char *content)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(content) - i + 1));
	if (!str)
		return (NULL);
	i++;
	// nos saltamos aqui el \n
	j = 0;
	while (content[i])
		str[j++] = content[i++];
	str[j] = '\0';
	free(content);
	return (str);
}

/*
Elimina la linea procesada (e insertada ya en "line") de "content".

- Recorre "content" hasta encontrar un \n, si no lo encuentra libera la variable y retorna NULL
	porque no existen mas lineas.

- Se reverva memoria para el string que contendra lo que quede tras el salto de linea (liongitud de
	"content" - i que contiene lo que hay hasta el salto de linea + \0)

- Copiamos el contenido tras el \n de "content" a "str" + el nulo, y liberamos "content"
	ya que ya no lo necesitamos.
*/
