/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 02:57:10 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/14 10:50:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		zoomzin(t_data *d, t_map *m)
{
	m->heigh += m->heigh2 * 0.30;
	d->loopstop = loop(1) * 40;
	return (1);
}

int		zoomzout(t_data *d, t_map *m)
{
	m->heigh -= m->heigh2 * 0.30;
	d->loopstop = loop(1) * 40;
	return (1);
}

int		zoomin(t_data *d, t_map *m, int x, int y)
{
	m->posx -= ((x <= 0) ? 0 : (x - m->posx));
	m->posy -= ((y <= 0) ? 0 : (y - m->posy));
	m->size *= (m->size == 1) ? 2 : ZOOM_SPEED;
	m->heigh *= ZOOM_SPEED;
	d->loopstop = loop(1) * 40;
	return (1);
}

int		zoomout(t_data *d, t_map *m, int x, int y)
{
	m->posx += ((x <= 0) ? 0 : (x - m->posx) / 2);
	m->posy += ((y <= 0) ? 0 : (y - m->posy) / 2);
	m->size /= ZOOM_SPEED;
	m->heigh /= ZOOM_SPEED;
	if (m->size < 1)
		m->size = 1;
	d->loopstop = loop(1) * 40;
	return (1);
}
