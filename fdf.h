/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:29:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/26 18:37:50 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define RESET   "\x1b[0m"

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>

typedef struct s_fdf
{
	int		w;
	int		h;
	int		**a;
	int		x;
	float	x1;
	float	x2;
	int		y;
	float	y1;
	float	y2;
	int		z1;
	int		z2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	int		color;
	int		zoom;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				*t_fdf;

void	read_map(char *map, t_fdf d);
void	draw_line(t_fdf d);
void	put_pix(t_fdf d, int x, int y, int color);
void	plot(t_fdf d);

#endif