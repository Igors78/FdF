/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 08:20:00 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 09:58:08 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zero_colors(t_fdf d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d->h)
	{
		x = 0;
		while (x < d->w)
		{
			d->c[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	init_colors(t_fdf d)
{
	int	i;

	d->c = (int **)malloc(sizeof(int *) * (d->h + 1));
	if (NULL == d->c)
		ft_terror("Memory allocation failed\n");
	i = 0;
	while (i < d->h)
	{
		d->c[i] = NULL;
		d->c[i] = (int *)malloc(sizeof(int) * (d->w));
		if (NULL == d->c[i])
			ft_terror("Memory allocation failed\n");
		i++;
	}
	d->c[i] = NULL;
	zero_colors(d);
}
