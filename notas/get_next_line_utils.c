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

char	*ft_strjoin(char *left_str, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buffer)
		return (NULL);
	str = malloc((ft_strlen(left_str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (left_str[++i])
		str[i] = left_str[i];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[ft_strlen(left_str) + ft_strlen(buffer)] = '\0';
	free(left_str);
	return (str);
}

/*
Concatena el contenido de "left_str", que ya se ha leido pero no procesado, y el buffer con los datos
	recien leidos.

- Si no hay nada en "left_str" (como sucede la primera vez que se llama a GNL), le asignamos memoria para
	contener un string vacio, ya que aun no se ha rellenado, esta todo el contenido en el buffer.

- Reservamos para "str" suficiente memoria para contener "left_str" y "buffer" + \0.

- Copiamos en "str" el contenido de "left_str" y despues el de "buffer" e incluimos el nulo final.
*/

char	*get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
Toma el contenido de "left_str" y extrae la primera linea.

- Reserva memoria para la linea extraida (despues de comprovar la cantidad de caracteres hasta un
	salto de linea). Asigna "i + 2" para dar espacio a la linea + \n + \0.

- Se copia el contenido de "left_str" en "str" hasta el salto de linea y luego, si es que hay un
	\n, se copia tambien (en el if final).
*/

char	*new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	// nos saltamos aqui el \n
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

/*
Elimina la linea procesada (e insertada ya en "line") de "left_str".

- Recorre "left_str" hasta encontrar un \n, si no lo encuentra libera la variable y retorna NULL
	porque no existen mas lineas.

- Se reverva memoria para el string que contendra lo que quede tras el salto de linea (liongitud de
	"left_str" - i que contiene lo que hay hasta el salto de linea + \0)

- Copiamos el contenido tras el \n de "left_str" a "str" + el nulo, y liberamos "left_str"
	ya que ya no lo necesitamos.
*/
