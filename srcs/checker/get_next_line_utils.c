/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:43:27 by gmallet           #+#    #+#             */
/*   Updated: 2023/06/14 12:44:01 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)(dst))[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

int	set_endline(size_t	*endl, t_file *file)
{
	size_t	i;

	i = file->offset;
	while (i < file->len)
	{
		if (file->buf[i] == '\n')
		{
			*endl = (i - file->offset);
			return (0);
		}
		i++;
	}
	if (i != file->offset)
		*endl = (i - 1 - file->offset);
	return (-1);
}

t_file	*init_file_struct(void)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!file->buf)
	{
		free(file);
		return (NULL);
	}
	file->len = 0;
	file->offset = 0;
	return (file);
}

int	gnl_ljoin(t_string *line, char *buf, size_t stop)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (stop == 0 && line->len != 0)
		return (0);
	str = malloc(sizeof(char) * (line->len + stop + 1));
	if (!str)
		return (-1);
	ft_memcpy(str, line->str, line->len);
	i = line->len;
	j = 0;
	while (j < stop)
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	free(line->str);
	line->str = str;
	line->len += j;
	return (0);
}
