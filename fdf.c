/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/24 20:35:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// < d > stands for data table stored in s_fdf structure

void	my_mlx_pixel_put(t_fdf d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_event(int button, int x, int y, void *param)
{
	t_fdf	d;

	(void)x;
	(void)y;
	d = param;
	mlx_pixel_put(d->mlx, d->win, 640 / 2, 360 / 2, 0xFF0000);
	ft_putnbr_fd(button, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	d;

	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	ft_terror("Correct format: ./fdf map.fdf\n");
	d = (t_fdf)malloc(sizeof(struct s_fdf));
	if (!d)
		ft_terror("Memory allocation failed\n");
	// read_map(argv[1], d);
	free(d->a);
	free(d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 1420, 980, "Hello world!");
	d->img = mlx_new_image(d->mlx, 1420, 980);
	d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel), &(d->line_length),
			&(d->endian));
	my_mlx_pixel_put(d, 1420 >> 1, 980 >> 1, 0x00FF0000);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	// mlx_mouse_hook(d->win, &mouse_event, d);
	mlx_loop(d->mlx);
	return (0);
}
