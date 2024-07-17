/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:43:14 by marvin            #+#    #+#             */
/*   Updated: 2022/07/11 11:43:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	word_count(char const *s, char c);
char		**ft_split(char const *s, char c);
static void	cpy(char *dst, char const *s, char c);
static int	split(char **arr, char const *s1, char c, int word);

static int	ft_cmp(char s1, char set)
{
	if (s1 == set || s1 == '\0')
		return (-1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	const int		count = word_count(s, c);
	char			**arr;
	int				idx;
	int				i;

	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (0);
	idx = split(arr, s, c, 0);
	i = 0;
	if (idx != -1)
	{
		while (i < idx)
		{
			free(arr[i]);
			arr[i] = 0;
			i++;
		}
		free(arr);
		arr = 0;
	}
	arr[count] = 0;
	return (arr);
}

static int	word_count(char const *s, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (ft_cmp(s[i], c) == 1 && ft_cmp(s[i + 1], c) == -1)
			word++;
		i++;
	}
	return (word);
}

static int	split(char **arr, char const *s1, char c, int word)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		if (ft_cmp(s1[i], c) == -1)
			i++;
		else
		{
			j = 0;
			while (ft_cmp(s1[i + j], c) == 1)
				j++;
			arr[word] = (char *)malloc((j + 1) * sizeof(char));
			if (!arr[word])
				return (word);
			cpy(arr[word], s1 + i, c);
			word++;
			i += j;
		}
	}
	return (-1);
}

static void	cpy(char *dst, char const *s, char c)
{
	int	i;

	i = 0;
	while (ft_cmp(s[i], c) == 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
}
