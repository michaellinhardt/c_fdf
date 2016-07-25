/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:06:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/25 20:04:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	clearimg(t_img *i)
{
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 0;
		i->str[i->i + 1] = 0;
		i->str[i->i + 2] = 0;
		i->str[i->i + 3] = 255;
	}
}

void	verifline(t_map *m)
{
	m->mat.lock = 0;
	m->mat.x1 = m->x * m->size;
	m->mat.y1 = m->y * m->size;
	m->mat.z1 = (int)((double)m->map[m->y][m->x] * m->heigh) * -1;
	if ((m->x + 1) < m->xm)
	{
		m->mat.x2 = (m->x + 1) * m->size;
		m->mat.y2 = m->y * m->size;
		m->mat.z2 = (int)((double)m->map[m->y][m->x + 1] * m->heigh) * -1;
		m->color = (m->mat.z2 != 0 || m->mat.z1 != 0) ? 1 : 0;
		addmatrice(m);
		line(m->mat.x1 + m->posx, (m->mat.y1 + m->posy) + m->mat.z1
			, m->mat.x2 + m->posx, (m->mat.y2 + m->posy) + m->mat.z2);
	}
	if ((m->y + 1) < m->ym)
	{
		m->mat.x2 = m->x * m->size;
		m->mat.y2 = (m->y + 1) * m->size;
		m->mat.z2 = (int)((double)m->map[m->y + 1][m->x] * m->heigh) * -1;
		m->color = (m->mat.z2 != 0
		|| ((int)((double)m->map[m->y][m->x] * m->heigh) * -1) != 0) ? 1 : 0;
		addmatrice(m);
		line(m->mat.x1 + m->posx, (m->mat.y1 + m->posy) + m->mat.z1
			, m->mat.x2 + m->posx, (m->mat.y2 + m->posy) + m->mat.z2);
	}
}

void	draw(t_data *d, t_map *m, t_img *i)
{
	itow(d->bkg.img, 0, 0, "background");
	if (!(i->img))
		i->img = newi(i, WIN_X, WIN_Y, "d->fdf");
	clearimg(i);
	m->y = -1;
	while (++m->y < m->ym && (m->x = -1))
		while (++m->x < m->xm)
			verifline(m);
	itow(d->fdf.img, 0 * loop(0), 0, "fdf");
}
