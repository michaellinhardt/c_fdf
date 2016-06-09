/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 10:59:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 18:23:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		*coordret1(enum coord c)
{
	static int			i[6];
	static enum coord	last = INIT;

	if (last == c || (last = c) == INIT)
		return (i);
	(c == MENU) ? C(i, CC{ 522, 175, 522, 175, 671, 204 }, 24) : 0;
	(c == ARROWU) ? C(i, CC{ 686, 181, 686, 181, 715, 208 }, 24) : 0;
	(c == ARROWD) ? C(i, CC{ 686, 520, 686, 520, 715, 548 }, 24) : 0;
	return (i);
}

int		*x(enum coord coord)
{
	if (coord >= MENU && coord <= ARROWD)
		return (coordret1(coord));
	return ((int *)NULL);
}

int		mo(enum coord c)
{
	static int			i[6];
	static enum coord	last = INIT;
	t_data *d;

	if (last != c && ((last = c) || 1))
		C(i, x(c), 24);
	d = data();
	if (d->mx >= i[2] && d->mx <= i[4] && d->my >= i[3] && d->my <= i[5])
		return (1);
	return (0);
}

int		mr(enum coord c, int x1, int y1)
{
	static int			i[6];
	static enum coord	last = INIT;
	t_data *d;

	if (last != c && ((last = c) || 1))
		C(i, x(c), 24);
	d = data();
	if (x1 >= i[2] && x1 <= i[4] && y1 >= i[3] && y1 <= i[5])
		return (1);
	return (0);
}
