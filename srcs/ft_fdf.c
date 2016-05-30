/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/30 06:19:52 by mlinhard         ###   ########.fr       */
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
	ft_printf("MOUSE: X: %d\tY: %d\n", x, y);
	ft_printf("MOUSE: X2: %d\tY2: %d\n", d->x2, d->y2);
	return (0);
}

int		draw(t_data *d, int x2, int y2)
{
	d->y2 = y2;
	d->x2 = x2;
	t_draw	xy;
	int		itv;
	int		itv2;
	ft_bzero(&xy, sizeof(xy));
	xy.start = 1;
	ft_printf("X: %d\tY: %d\n", d->x, d->y);
	ft_printf("X2: %d\tY2: %d\n\n", d->x2, d->y2);


	xy.big2 = ((x2 - d->x) >= (y2 - d->y)) ? x2 : y2;
	xy.big2 = y2;
	xy.big = ((x2 - d->x) > (y2 - d->y)) ? d->x : d->y;
	xy.small2 = ((x2 - d->x) > (y2 - d->y)) ? y2 : x2;
	xy.small = ((x2 - d->x) > (y2 - d->y)) ? d->y : d->x;
	itv =((xy.big2 - xy.big) / (xy.small2 - xy.small));
	itv2 = itv * -1;
	while ((xy.small2 != xy.small) && (xy.big2 !=xy.big))
	{
		d->x = (xy.big2 == d->x2) ? xy.big : xy.small;
		d->y = (xy.big2 == d->y2) ? xy.big : xy.small;
		mlx_pixel_put(d->mlx, d->win, d->x, d->y, 0x00FFFFFF);
		ft_printf("print %d,%d\n", d->x, d->y);
		if (xy.big2 != xy.big && ft_printf("inc big\n"));
			xy.big += (xy.big < xy.big2) ? 1 : -1;
		if (xy.small != xy.small2 && ++itv2 > itv && !(itv2 = 0))
			xy.small += (xy.small < xy.small2) ? 1 : -1;
	}
	d->x = (xy.big2 == d->x2) ? xy.big : xy.small;
	d->y = (xy.big2 == d->y2) ? xy.big : xy.small;
	exit (0);
	return (0);
}

void	mlx_run(t_data *d, int step)
{
	(step == 1) ? (d->mlx = mlx_init()) : (t_data *)NULL;
	(step == 1) ? (d->win = mlx_new_window(d->mlx, 400, 400, "MLX BITCH")) : (t_data *)NULL;
}

int		main(void)
{
	t_data	d;

	d.x = -10;
	d.y = 88;
	mlx_run(&d, 1);

	draw(&d, 20, 200);
	ft_printf("AFTER DRAW: X: %d\tY: %d\n\n", d.x, d.y);
	ft_printf("AFTER DRAW: X2: %d\tY2: %d\n\n", d.x2, d.y2);

	mlx_key_hook (d.win, input_key, (void *)&d);
	mlx_mouse_hook (d.win, input_mouse, (void *)&d);
	mlx_loop(d.mlx);
	return (0);
}
