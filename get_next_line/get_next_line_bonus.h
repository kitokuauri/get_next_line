/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aursuare <aursuare@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:32:04 by aursuare          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:05 by aursuare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char				*get_next_line(int fd);
char				*ft_read_to_left(int fd, char *content);

char				*ft_get_line(char *content);
char				*new_content(char *content);

unsigned long int	ft_strlen(char *str);
char				*ft_strchr(char *str, int c);
char				*ft_strjoin(char *content, char *buffer);

#endif
