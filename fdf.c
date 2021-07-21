/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/21 15:07:27 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// < d > stands for data table stored in s_fdf structure

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
	int		i;
	int		j;

	if (argc != 2)
		ft_terror("Correct format: ./fdf map.fdf\n");
	d = (t_fdf)malloc(sizeof(struct s_fdf));
	if (!d)
		ft_terror("Memory allocation failed\n");
	read_map(argv[1], d);
	i = 0;
	while (i < d->h)
	{
		j = 0;
		while (j < d->w)
		{
			ft_printf("%3d ", d->a[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}

	// d->mlx = mlx_init();
	// d->win = mlx_new_window(d->mlx, 640, 360, "TEST");
	// mlx_mouse_hook(d->win, &mouse_event, d);
	// mlx_loop(d->mlx);
	return (0);
}
