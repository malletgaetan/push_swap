/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmallet <gmallet@student.42lehavre.fr >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:43:33 by gmallet           #+#    #+#             */
/*   Updated: 2023/06/14 12:43:58 by gmallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fetch_until_endl(int fd, size_t *endl, t_file *f, t_string *line)
{
	ssize_t	rres;
	int		status;

	status = -1;
	while (status == -1)
	{
		if (f->len && gnl_ljoin(line, f->buf + f->offset, f->len - f->offset))
			return (-1);
		rres = read(fd, f->buf, BUFFER_SIZE);
		f->len = (size_t)rres;
		f->offset = 0;
		if (rres == -1)
			return (-1);
		if (rres == 0)
			return (0);
		status = set_endline(endl, f);
	}
	return (0);
}

static int	fill_line(int fd, t_file *f, t_string *line)
{
	size_t	endl;

	if (set_endline(&endl, f) && fetch_until_endl(fd, &endl, f, line))
		return (-1);
	if (line->len == 0 && f->len == 0)
		return (-1);
	if (f->len == 0)
		return (0);
	if (gnl_ljoin(line, f->buf + f->offset, endl + 1))
		return (-1);
	if (f->offset + endl == (size_t)(BUFFER_SIZE - 1))
	{
		f->offset = 0;
		f->len = 0;
	}
	else
	{
		f->offset += (endl + 1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_file	*file;
	t_string		line;
	int				error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line.str = NULL;
	line.len = 0;
	if (!file)
		file = init_file_struct();
	error = fill_line(fd, file, &line);
	if (!(line.str) || error)
	{
		free(line.str);
		free(file->buf);
		free(file);
		file = NULL;
		return (NULL);
	}
	return (line.str);
}
