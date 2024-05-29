/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzanchi <uzanchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:59:25 by uzanchi           #+#    #+#             */
/*   Updated: 2024/05/30 00:13:51 by uzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_archive(char **archive)
{
	if (*archive)
	{
		free(*archive);
		*archive = NULL;
	}
	return (NULL);
}

static void	join_archive_and_buffer(char **archive, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*archive, buffer);
	free_archive(archive);
	*archive = temp;
}

static char	*extract_line(char **archive)
{
	size_t	length;
	char	*line;
	char	*temp;

	if (ft_strchr(*archive, '\n'))
		length = ft_strchr(*archive, '\n') - *archive + 1;
	else
		length = ft_strlen(*archive);
	line = malloc((length + 1) * sizeof (char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *archive, length + 1);
	if (ft_strchr(*archive, '\n'))
	{
		temp = ft_strjoin(ft_strchr(*archive, '\n') + 1, "");
		free_archive(archive);
		*archive = temp;
	}
	else
		free_archive(archive);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*archive[FD_MAX] = NULL;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!archive[fd])
			archive[fd] = ft_strjoin("", buffer);
		else
			join_archive_and_buffer(&archive[fd], buffer);
		if (ft_strchr(archive[fd], '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1 || !archive[fd] || !*archive[fd])
		return (free_archive(&archive[fd]));
	return (extract_line(&archive[fd]));
}
