/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 10:59:31 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:29:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		*coordret1(enum coord c)
{
	static int			i[6];
	static enum coord	last = INIT;

	if (last == c || (last = c) == INIT)
		return (i);
	(c == ARROWU) ? C(i, CC{ 678, 181, 678, 181, 708, 208 }, 24) : 0;
	(c == ARROWD) ? C(i, CC{ 678, 520, 678, 520, 708, 548 }, 24) : 0;
	return (i);
}

int		*x(enum coord coord)
{
	if (coord >= ARROWU && coord <= ARROWD)
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
