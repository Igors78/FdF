/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:26:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/25 06:32:28 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf d)
{
	int	dx;
	int	dy;
	int	p;

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
