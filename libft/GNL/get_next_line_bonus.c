/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:06:05 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/25 13:40:45 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_free_join(char *stash, char *buffer)
{
	char	*tmp;

	tmp = stash;
	stash = ft_gnl_strjoin(tmp, buffer);
	free (tmp);
	return (stash);
}

static	char	*read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(stash);
		return (NULL);
	}
	bytes = 1;
	while (ft_gnl_strchr(stash, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes] = '\0';
		stash = ft_free_join(stash, buffer);
		if (stash == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t		i;
	char		*line;

	i = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_gnl_substr(stash, 0, i + 1);
	else
		line = ft_gnl_substr(stash, 0, i);
	return (line);
}

static char	*clean_stash(char *stash)
{
	size_t		i;
	char		*new_stash;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_gnl_substr(stash, i + 1, ft_gnl_strlen(stash) - (i + 1));
	free(stash);
	if (new_stash == NULL || new_stash[0] == '\0')
	{
		free(new_stash);
		return (NULL);
	}
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	line = extract_line(stash[fd]);
	if (line == NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
