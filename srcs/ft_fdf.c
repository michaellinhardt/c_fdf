/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/31 04:54:33 by mlinhard         ###   ########.fr       */
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

int		input_mouse(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSE: X.: %d\t\tY.: %d\n", x, y);
	return (0);
}

int		abs(int i)
{
	return ((i < 0) ? i * -1 : i);
}

void line(t_data *d, int x2, int y2)
{
	t_line	l;

	l.dx = abs(x2 - d->x);
	l.sx = d->x < x2 ? 1 : -1;
	l.dy = abs(y2 - d->y);
	l.sy = d->y < y2 ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (42)
	{
		mlx_pixel_put(d->mlx, d->win, d->x, d->y, 0x00FFFFFF);
		if (d->x == x2 && d->y == y2)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx && ((l.err -= l.dy) || 1))
			d->x += l.sx;
		if (l.e2 < l.dy && ((l.err += l.dx) || 1))
			d->y += l.sy;
	}
}

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

	d.x = 221;
	d.y = 303;
	mlx_run(&d, 0);

	ft_printf("BEFORE DRAW: X: %d\tY: %d\n", d.x, d.y);
	line(&d, 43, 108);
	ft_printf("AFTER DRAW: X: %d\tY: %d\n", d.x, d.y);
	mlx_run(&d, 1);
	return (0);
}
