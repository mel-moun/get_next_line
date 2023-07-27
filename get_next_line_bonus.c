/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:44:08 by mel-moun          #+#    #+#             */
/*   Updated: 2022/12/11 10:46:50 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *) malloc (count * size);
	if (p == NULL)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*optimize(char **save, int fd)
{
	int			r;
	char		buff[BUFFER_SIZE + 1];

	r = 1;
	buff[0] = '\0';
	while (r > 0 && !checknl(buff))
	{
		r = read (fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(save[fd]);
			save[fd] = NULL;
			return (NULL);
		}
		buff[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
	}
	return (save[fd]);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	save[fd] = optimize(save, fd);
	if (!save[fd])
		return (NULL);
	line = beforenl(save[fd]);
	save[fd] = afternl(save[fd]);
	return (line);
}
