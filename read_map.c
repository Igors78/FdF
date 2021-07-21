/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:39:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/21 14:57:11 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ' w ' for width of the map(initial x)
// ' h ' for height of the map(initial y)
// ' a ' for respective altitude of point of cross(x, y)

static int	get_w(char *map)
{
	char	*line;
	int		fd;
	int		w;

	fd = open(map, O_RDONLY);
	w = 0;
	get_next_line(fd, &line);
	w = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (w);
}

static int	get_h(char *map)
{
	char	*line;
	int		fd;
	int		h;

	fd = open(map, O_RDONLY);
	h = 0;
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
	}
	free(line);
	close(fd);
	return (h);
}

static void	fill_altitude(int *alt_line, char *line)
{
	char	**splits;
	int		i;

	splits = ft_split(line, ' ');
	i = 0;
	while (splits[i])
	{
		alt_line[i] = ft_atoi(splits[i]);
		free (splits[i]);
		i++;
	}
}

void	read_map(char *map, t_fdf d)
{
	char	*line;
	int		fd;
	int		i;

	d->w = get_w(map);
	d->h = get_h(map);
	d->a = (int **)malloc(sizeof(int) * (d->w + 1));
	i = 0;
	while (i <= d->h)
		d->a[i++] = (int *)malloc(sizeof(int) * (d->w + 1));
	fd = open(map, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_altitude(d->a[i], line);
		free(line);
		i++;
	}
	d->a[i] = NULL;
}
