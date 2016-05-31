/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:14:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/31 19:14:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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
