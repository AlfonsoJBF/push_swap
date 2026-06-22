/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albustos <albustos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 02:24:24 by albustos          #+#    #+#             */
/*   Updated: 2026/05/26 13:32:34 by albustos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c && in_word)
			in_word = 0;
		if (str[i] != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static char	**free_array(char **arr, int i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static void	init_vars(ssize_t *start, int *counter, size_t *finish)
{
	*start = -1;
	*counter = 0;
	*finish = 0;
}

static char	**solve_split(char **arr, char const *s, char c)
{
	ssize_t	start;
	int		j;
	size_t	finish;

	init_vars(&start, &j, &finish);
	while (finish <= ft_strlen(s))
	{
		if (s[finish] != c && start < 0)
			start = finish;
		else if ((s[finish] == c || finish == ft_strlen(s)) && start >= 0)
		{
			arr[j] = ft_substr(s, start, (finish - start));
			if (!arr[j])
				return (free_array(arr, j));
			start = -1;
			j++;
		}
		finish++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	return (solve_split(arr, s, c));
}
