/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/20 17:54:08 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// < d > stands for data table stored in s_fdf structure

int	mouse_event(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	ft_putnbr_fd(button, 1);
	return (0);
}

int	main(void)
{
	t_fdf	d;

	ft_printf("FUCKING LIBRARY\n");
	d = (t_fdf)malloc(sizeof(struct s_fdf));
	if (!d)
		ft_terror("Memory allocation failed\n");
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 640, 360, "TEST");
	mlx_pixel_put(d->mlx, d->win, 640 / 2, 360 / 2, 0xFF0000);
	mlx_mouse_hook(d->win, &mouse_event, 0);
	mlx_loop(d->mlx);
	return (0);
}
