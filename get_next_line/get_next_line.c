/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:38:11 by coh               #+#    #+#             */
/*   Updated: 2022/08/01 16:47:22 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*one_line(char *src)
{
	char	*nomi;
	int		i;

	i = 0;
	if (!src[0])
		return (0);
	while (src[i] && src[i] != '\n')
		i++;
	nomi = (char *)malloc((i + 2) * sizeof(char));
	if (nomi == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		nomi[i] = src[i];
		i++;
		if (src[i - 1] == '\n')
			break ;
	}
	nomi[i] = '\0';
	return (nomi);
}

static char	*find_nl(char *temp, int fd, char **str, ssize_t *nbyte)
{
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	*str = ft_strchr(temp, '\n');
	while (!(*str) && *nbyte)
	{
		*nbyte = read(fd, buf, BUFFER_SIZE);
		if (*nbyte == -1)
		{
			free(buf);
			return (0);
		}
		buf[*nbyte] = '\0';
		if (*nbyte)
			temp = ft_strjoin(temp, buf);
		*str = ft_strchr(temp, '\n');
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	*temp;
	ssize_t		nbyte;

	nbyte = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = find_nl(temp, fd, &str, &nbyte);
	if (!temp)
		return (0);
	line = one_line(temp);
	if (str)
		temp = ft_strdup(str + 1, temp);
	if (!nbyte)
	{
		free(temp);
		temp = 0;
	}
	return (line);
}
