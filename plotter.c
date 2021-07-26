/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:26:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/26 10:29:52 by ioleinik         ###   ########.fr       */
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
	int	x;
	int	y;
	int	p;

	//color_zoom(d);
	dx = d->x2 - d->x1;
	dy = d->y2 - d->y1;
	x = d->x1;
	y = d->y1;
	p = 2 * dy - dx;
	while (x < d->x2)
	{
		if (p >= 0)
		{
			put_pix(d, x, y, d->color);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			put_pix(d, x, y, d->color);
			p = p + 2 * dy;
		}
		x++;
	}
}

void	plot(t_fdf d)
{
	// d->x1 = 10;
	// d->y1 = 10;
	// d->x2 = 100;
	// d->y2 = 10;
	// draw_line(d);
	d->x1 = 10;
	d->y1 = 10;
	d->x2 = 50;
	d->y2 = 500;
	put_pix(d, d->x1, d->y1, d->color);
	put_pix(d, d->x2, d->y2, d->color);
	draw_line(d);
}
