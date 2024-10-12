/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:32:04 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/07 18:31:40 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char				*get_next_line(int fd);
char				*read_to_left(int fd, char *left_str);

char				*get_line(char *left_str);
char				*new_left_str(char *left_str);

unsigned long int	ft_strlen(char *str);
char				*ft_strchr(char *str, int c);
char				*ft_strjoin(char *left_str, char *buffer);

#endif
