/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:39:50 by ihamani           #+#    #+#             */
/*   Updated: 2025/01/03 14:11:10 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*pop_last(char **last, char *buff, size_t byte)
{
	char	*str;
	char	*tmp;

	if (byte == 0)
	{
		str = *last;
		return (last_eof(last, buff, str));
	}
	str = *last;
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
	static char	*last[1024];
	char		*buff;
	size_t		byte;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc((long long)BUFFER_SIZE + 1 * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (1)
	{
		if (last[fd] != NULL
			&&is_line(last[fd], ft_strlen(last[fd]), '\n') > -1)
			return (get_line_inlast(&last[fd], buff));
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
		if (byte < BUFFER_SIZE)
			return (pop_last(&last[fd], buff, byte));
		tmp = last[fd];
		last[fd] = ft_strjoin(last[fd], buff);
		free(tmp);
	}
	return (last[fd]);
}