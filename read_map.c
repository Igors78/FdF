/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:39:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 11:14:04 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_altitude(int *alt_line, char *line, int y, t_fdf d)
{
	char	**splits;
	int		i;

	splits = ft_split(line, ' ');
	i = 0;
	while (splits[i])
	{
		alt_line[i] = ft_atoi(splits[i]);
		if (strchr(splits[i], ','))
		{
			d->c[y][i] = ft_atoi_base(strchr(splits[i], ',') + 3, HEXUPP);
		}
		free (splits[i]);
		i++;
	}
	free(splits);
}

static void	parse_map(char *map, t_fdf d)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_terror("Cannot open file\n");
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_altitude(d->a[i], line, i, d);
		free(line);
		i++;
	}
	free(line);
	close(fd);
}

static int	get_width(char *map)
{
	char	*line;
	int		fd;
	size_t	width;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_terror("Cannot open file\n");
	width = 0;
	get_next_line(fd, &line);
	width = ft_wordcount(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (width != ft_wordcount(line, ' '))
			ft_terror("Invalid map format\n");
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}

static int	get_height(char *map)
{
	char	*line;
	int		fd;
	size_t	height;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_terror("Cannot open file\n");
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

// ' w ' for width of the map(initial maximum x)
// ' h ' for height of the map(initial maximum y)
// ' a ' for respective altitude of point of cross(x, y)

void	read_map(char *map, t_fdf d)
{
	int		i;

	d->w = get_width(map);
	d->h = get_height(map);
	init_colors(d);
	d->a = (int **)malloc(sizeof(int *) * (d->h + 1));
	if (NULL == d->a)
		ft_terror("Memory allocation failed\n");
	i = 0;
	while (i < d->h)
	{
		d->a[i] = NULL;
		d->a[i] = (int *)malloc(sizeof(int) * (d->w));
		if (NULL == d->a[i])
			ft_terror("Memory allocation failed\n");
		i++;
	}
	parse_map(map, d);
	d->a[i] = NULL;
	if (MAX_X / d->w < MAX_Y / d->h)
		d->zoom = MAX_X / d->w;
	else
		d->zoom = MAX_Y / d->h;
}
