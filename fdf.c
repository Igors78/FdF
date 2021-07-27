/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 19:30:49 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// < d > stands for data table stored in s_fdf structure

static void	clean_up(t_fdf d)
{
	int	i;

	i = 0;
	while (i < d->h)
	{
		free(d->a[i]);
		free(d->c[i]);
		i++;
	}
	free(d->a);
	free(d->c);
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free(d);
	exit(0);
}

static void	init_data(t_fdf d)
{
	d->w = 0;
	d->h = 0;
	d->a = NULL;
	d->c = NULL;
	d->x = 0;
	d->x1 = 0;
	d->x2 = 0;
	d->y = 0;
	d->y1 = 0;
	d->y2 = 0;
	d->z = 0;
	d->zoom = 0;
	d->color = 0xFFFFFF;
}

static int	key_event(int button, void *param)
{
	t_fdf	d;

	d = param;
	if (button == 65307)
		clean_up(d);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	d;

	if (argc != 2)
		ft_terror("Correct format: ./fdf map.fdf\n");
	d = (t_fdf)malloc(sizeof(struct s_fdf));
	if (!d)
		ft_terror("Memory allocation failed\n");
	init_data(d);
	read_map(argv[1], d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, MAX_X, MAX_Y, "FdF");
	d->img = mlx_new_image(d->mlx, MAX_X, MAX_Y);
	d->addr = mlx_get_data_addr(d->img, &(d->bits_per_pixel), &(d->line_length),
			&(d->endian));
	plot(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_key_hook(d->win, &key_event, d);
	mlx_loop(d->mlx);
	return (0);
}
