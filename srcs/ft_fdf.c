/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/30 00:59:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		input_key(int key, t_data *d)
{
	if (key == 65307)
		mlx_destroy_window(d->mlx, d->win), exit(0);
	ft_printf("key: %d\n", key);
	return (0);
}

int		main(void)
{
	t_data	data;
	int		x;
	int		y;
	int		y_every;
	int		x_max;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 400, 400, "MLX BITCH");
	x = 100;
	y = 190;
	x_max = 200;
	y_every = 5;

	while (x < x_max)
	{
		if ((x_max - x) % y_every == 0)
			y++;
		mlx_pixel_put(data.mlx, data.win, x, y, 0x00FFFFFF);
		x++;
	}
	ft_printf("x: %d\ny: %d\n", x, y);

	mlx_key_hook (data.win, input_key, (void *)&data);
	mlx_loop(data.mlx);
	return (0);
}
