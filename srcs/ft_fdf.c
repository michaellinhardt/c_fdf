/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/30 00:25:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		y_every;
	int		x_max;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "MLX BITCH");
	x = 0;
	y = 190;
	x_max = 100;
	y_every = 10;



	while (x < x_max)
	{
		if ((x_max - x) % y_every == 0)
			y++;
		mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
		x++;
	}
	ft_printf("x: %d\ny: %d\n", x, y);
	mlx_loop(mlx);
	return (0);
}
