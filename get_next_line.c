/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nero <nero@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:39:50 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/07 20:31:29 by nero             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_line(const char *str, size_t size, char c)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line_inlast(char **last, char *buff)
{
	char	*str;
	char	*tmp;

	str = *last;
	*last = ft_strdup(*last + is_line(*last, ft_strlen(*last), '\n') + 1);
	tmp = str;
	str = ft_substr(str, 0, is_line(str, ft_strlen(str), '\n') + 1);
	free(tmp);
	free(buff);
	return (str);
}

char	*last_eof(char **last, char *buff, char *str)
{
	*last = NULL;
	if (str != NULL && *str == '\0')
	{
		free(str);
		str = NULL;
	}
	free(buff);
	return (str);
}

char	*pop_last(char **last, char *buff, ssize_t byte)
{
	char	*str;
	char	*tmp;

	str = *last;
	if (byte == 0)
		return (last_eof(last, buff, str));
	*last = ft_strjoin(*last, buff);
	free(str);
	str = *last;
	if (is_line(str, ft_strlen(str), '\n') > -1)
	{
		*last = ft_strdup(*last + is_line(*last, ft_strlen(*last), '\n') + 1);
		tmp = str;
		str = ft_substr(str, 0, is_line(str, ft_strlen(str), '\n') + 1);
		free(tmp);
	}
	else if (is_line(str, ft_strlen(str), '\n') == -1 && str[0] != '\0')
		*last = NULL;
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*buff;
	ssize_t		byte;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(last), last = NULL, NULL);
	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (free(last), last = NULL, NULL);
	while (1)
	{
		if (last != NULL && is_line(last, ft_strlen(last), '\n') > -1)
			return (get_line_inlast(&last, buff));
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte >= 0)
			buff[byte] = '\0';
		if (byte < BUFFER_SIZE)
			return (pop_last(&last, buff, byte));
		tmp = last;
		last = ft_strjoin(last, buff);
		free(tmp);
	}
	return (last);
}
