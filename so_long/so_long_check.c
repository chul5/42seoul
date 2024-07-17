/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:25:26 by coh               #+#    #+#             */
/*   Updated: 2023/01/26 18:44:00 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char c, t_data *data)
{
	if (c == 'C')
		(data->char_num).c++;
	if (c == 'P')
		(data->char_num).p++;
	if (c == 'E')
		(data->char_num).e++;
	if (c == 'C' || c == 'E' || c == 'P' || c == '0' || c == '1')
		return (0);
	return (-1);
}

void	check_rectangle(char *filename, t_data *temp)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		print_msg("empty file!");
	temp->wid = ft_strlen(line) - 1;
	len = temp->wid;
	while (line)
	{
		free(line);
		temp->hei++;
		line = get_next_line(fd);
		if (line)
			len += check_len(line);
	}
	if (len != (temp->wid) * (temp->hei))
		print_msg("rectangle error!");
	close(fd);
}

void	check_char_error(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->hei)
	{
		j = 0;
		while (j < d->wid)
		{
			if ((i == 0 || i == d->hei - 1 || j == 0 || j == d->wid - 1) \
			&& d->array[i][j] != '1')
				char_err(d);
			else if (check_char(d->array[i][j], d) == -1)
				char_err(d);
			if (d->array[i][j] == 'P')
				position_init(d, i, j);
			j++;
		}
		i++;
	}
	if ((d->char_num).c < 1 || (d->char_num).p != 1 || \
	(d->char_num).e != 1)
		char_err(d);
}

int	check_len(char *line)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			len++;
		i++;
	}
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
			j++;
		if (needle[j] == 0 && !haystack[i + j])
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (0);
}
