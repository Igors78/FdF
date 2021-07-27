/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:26:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 10:40:14 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	color_zoom(t_fdf d)
// {
	// d->z1 = d->a[d->y1][d->x1];
	// d->z2 = d->a[d->y2][d->x2];
// 	d->x1 *= d->zoom;
// 	d->y1 *= d->zoom;
// 	d->x2 *= d->zoom;
// 	d->y2 *= d->zoom;
	// if (d->z1 > 0)
	// 	d->color = 0xFF0000;
	// else
	// 	d->color = 0xFFFFFF;
// }

static int	maxmodule(t_fdf d)
{
	float	x_step;
	float	y_step;

	x_step = fabs(d->x2 - d->x1);
	y_step = fabs(d->y2 - d->y1);
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

void	put_pix(t_fdf d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_fdf d)
{
	float	x_step;
	float	y_step;
	int		max;

	d->z = d->a[d->y][d->x];
	if (d->c[d->y][d->x])
		d->color = d->c[d->y][d->x];
	else if (d->z)
		d->color = 0xFF0000;
	else
		d->color = 0xFFFFFF;
	x_step = d->x2 - d->x1;
	y_step = d->y2 - d->y1;
	max = maxmodule(d);
	x_step /= max;
	y_step /= max;
	while ((int)(d->x1 - d->x2) || (int)(d->y1 - d->y2))
	{
		put_pix(d, d->x1, d->y1, d->color);
		d->x1 += x_step;
		d->y1 += y_step;
	}
}

void	plot(t_fdf d)
{
	while (d->y < d->h)
	{
		d->x = 0;
		while (d->x < d->w)
		{
			if (d->x < d->w - 1)
			{
				d->x1 = d->x * d->zoom;
				d->x2 = (d->x + 1) * d->zoom;
				d->y1 = d->y * d->zoom;
				d->y2 = d->y * d->zoom;
				draw_line(d);
			}
			if (d->y < d->h - 1)
			{
				d->x1 = d->x * d->zoom;
				d->x2 = d->x * d->zoom;
				d->y1 = d->y * d->zoom;
				d->y2 = (d->y + 1) * d->zoom;
				draw_line(d);
			}
			(d->x)++;
		}
		(d->y)++;
	}
}
