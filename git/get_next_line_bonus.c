/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouram <abouram@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:59:30 by abouram           #+#    #+#             */
/*   Updated: 2022/11/18 18:59:34 by abouram          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line_with_n(char *line_n)
{
	char	*return_v;
	int		i;

	i = 0;
	while (line_n[i] && line_n[i] != '\n')
		i++;
	if (line_n[i] == '\n')
		i++;
	return_v = ft_calloc(i + 1, 1);
	i = 0;
	while (line_n[i] && line_n[i] != '\n')
	{
		return_v[i] = line_n[i];
		i++;
	}
	if (line_n[i] && line_n[i] == '\n')
		return_v[i] = line_n[i];
	if (!return_v[0])
	{
		free(return_v);
		return (NULL);
	}
	return (return_v);
}

char	*get_line_with_out_n(char *line_n)
{
	char	*clean_line;
	int		i;

	i = 0;
	while (line_n[i] && line_n[i] != '\n')
		i++;
	clean_line = ft_calloc(ft_strlen(line_n) - i + 1, 1);
	if (!clean_line)
		return (NULL);
	if (line_n[i] && line_n[i] == '\n')
		i++;
	if (line_n[i])
		clean_line = ft_strjoin(clean_line, &line_n[i]);
	free(line_n);
	if (!clean_line[0])
	{
		free(clean_line);
		return (NULL);
	}
	return (clean_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line_n[OPEN_MAX];
	char		*return_v;
	ssize_t		int_to_read;

	int_to_read = 1;
	if (fd < 0 || read(fd, 0, 0))
	{
		free(line_n[fd]);
		line_n[fd] = NULL;
		return (NULL);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line_n[fd])
		line_n[fd] = ft_calloc(1, 1);
	while (int_to_read >= 1 && !(ft_strchr(buffer, '\n')))
	{
		int_to_read = read(fd, buffer, BUFFER_SIZE);
		buffer[int_to_read] = '\0';
		line_n[fd] = ft_strjoin(line_n[fd], buffer);
	}
	free(buffer);
	return_v = get_line_with_n(line_n[fd]);
	line_n[fd] = get_line_with_out_n(line_n[fd]);
	return (return_v);
}
