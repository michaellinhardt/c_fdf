/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:09:39 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:51:54 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		red_cross(void)
{
	t_data *d;

	d = data();
	exit1(0, d, "by clic on red cross");
	return (0);
}

void	mlx_handler(t_data *d, int step)
{
	if (step == 0)
	{
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, WIN_X, WIN_Y, WIN_TITLE);
		l(1, "d->mlx", "mlx_init();");
		l(1, "d->win", "mlx_new_window();");
	}
	if (step == 1)
	{
		mlx_hook(d->win, 2, (1L<<0), keyp_hook, d);
		mlx_hook(d->win, 3, (1L<<1), keyr_hook, d);
		mlx_hook(d->win, 4, (1L<<2), mousep_hook, d);
		mlx_hook(d->win, 5, (1L<<3), mouser_hook, d);
		mlx_hook(d->win, 6, (1L<<0), mousem_hook, d);
		mlx_hook(d->win, 17, (1L<<17), &red_cross, d);
		mlx_loop_hook(d->mlx, loop_hook, d);
		l3(0);
		l(10, "LOOP START", "mlx_loop();");
		mlx_loop(d->mlx);
	}
}
