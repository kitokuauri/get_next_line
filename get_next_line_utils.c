/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:31:42 by aursuare          #+#    #+#             */
/*   Updated: 2024/09/30 18:13:04 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char *str)
{
	unsigned long int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == NULL)
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
// Busca la primera aparicion de "c" en "str"

char	*ft_strjoin(char *left_str, char *buffer)
{
	char 	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	str = malloc((ft_strlen(left_str) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	else
	{
		i = -1;
		while (left_str[++i]);
			str[i] = left_str[i];
		j = 0;
		while (buffer[j])
			str[i++] = buffer[j++];
		str[i] = '\0';
		free(left_str);
		return (str);
	}

}

char	*get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != "\n")
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == "\n")
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = "\0";
	return (str);
}

char	*new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != "\n")
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if(!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = "\0";
	free(left_str);
	return (str);
}
