/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:26:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/25 16:49:27 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	color_zoom(t_fdf d)
// {
// 	// d->z1 = d->a[d->y1][d->x1];
// 	// d->z2 = d->a[d->y2][d->x2];
// 	d->x1 *= d->zoom;
// 	d->y1 *= d->zoom;
// 	d->x2 *= d->zoom;
// 	d->y2 *= d->zoom;
// 	// if (d->z1 > 0)
// 	// 	d->color = 0xFF0000;
// 	// else
// 	// 	d->color = 0xFFFFFF;
// }

void	put_pix(t_fdf d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_fdf d)
{
	int	dx;
	int	dy;
	int	p;

	//color_zoom(d);
	dx = d->x2 - d->x1;
	dy = d->y2 - d->y1;
	d->x = d->x1;
	d->y = d->y1;
	p = (dy << 1) - dx;
	while (d->x < d->x2)
	{
		if (p >= 0)
		{
			put_pix(d, d->x, d->y, d->color);
			d->y = d->y + 1;
			p = p + (dy << 1) - (dx << 1);
		}
		else
		{
			put_pix(d, d->x, d->y, d->color);
			p = p + (dy << 1);
		}
		(d->x)++;
	}
}

void	plot(t_fdf d)
{
	d->y1 = 0;
	d->y2 = 0;
	while (d->y1 < d->h)
	{
		d->x1 = 0;
		d->x2 = 0;
		while (d->x1 < d->w)
		{
			if (d->x1 < d->w - 1)
			{
				draw_line(d);
				(d->x2)++;
			}
			if (d->y1 < d->h - 1)
			{
				draw_line(d);
				(d->y2)++;
			}
			(d->x1)++;
		}
		(d->y1)++;
	}
}
