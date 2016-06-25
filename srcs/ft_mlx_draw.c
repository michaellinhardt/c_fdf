/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:14:09 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/26 00:04:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		abs(int i)
{
	return ((i < 0) ? i * -1 : i);
}

void	line(int x1, int y1, int x2, int y2)
{
	static t_data	*d = NULL;
	t_line	l;

	(!d) ? d = data() : (t_data *)NULL;
	l.dx = abs(x2 - x1);
	l.sx = x1 < x2 ? 1 : -1;
	l.dy = abs(y2 - y1);
	l.sy = y1 < y2 ? 1 : -1;
	l.err = (l.dx > l.dy ? l.dx : -l.dy) / 2;
	while (42)
	{
		mlx_pixel_put(d->mlx, d->win, x1, y1, 0x00FFFFFF);
		if (x1 == x2 && y1 == y2)
			break ;
		l.e2 = l.err;
		if (l.e2 > -l.dx && ((l.err -= l.dy) || 1))
			x1 += l.sx;
		if (l.e2 < l.dy && ((l.err += l.dx) || 1))
			y1 += l.sy;
	}
}
