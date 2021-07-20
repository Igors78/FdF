/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 11:26:35 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/20 10:04:45 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// < d > stands for data table stored in s_fdf structure

int	main(void)
{
	t_fdf	d;

	ft_printf("FUCKING LIBRARY\n");
	d = (t_fdf)malloc(sizeof(struct s_fdf));
	if (!d)
		ft_terror("Memory allocation failed\n");
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, 500, 500, "TEST");
	mlx_loop(d->mlx);
	return (0);
}
