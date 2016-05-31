/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/31 19:30:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	mlx_run(t_data *d, int step)
{
	if (step == 0)
	{
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, 400, 400, "MLX BITCH");
	}
	if (step == 1)
	{
		mlx_key_hook(d->win, input_key, (void *)d);
		mlx_mouse_hook(d->win, input_mouse, (void *)d);
		mlx_loop(d->mlx);
	}
}

int		main(void)
{
	t_data	d;

	d.x = 100;
	d.y = 100;
	mlx_run(&d, 0);

	ft_printf("BEFORE DRAW: X: %d\tY: %d\n", d.x, d.y);
	line(&d, 200, 100);
	line(&d, 200, 200);
	line(&d, 100, 200);
	line(&d, 100, 100);
	ft_printf("AFTER DRAW: X: %d\tY: %d\n", d.x, d.y);
	mlx_run(&d, 1);
	return (0);
}
