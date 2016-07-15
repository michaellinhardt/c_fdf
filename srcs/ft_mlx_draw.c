/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:06:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/15 06:27:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <math.h>

void	prepline(int x1, int y1, int z1, int x2, int y2, int z2)
{
	t_data	*d = data();
	t_map	*m = &d->map;


	y1 = (int)(((double)y1 * cos(m->rx)) + ((double)y1 * sin(m->rx)));
	y2 = (int)(((double)y2 * cos(m->rx)) + ((double)y2 * sin(m->rx)));

	z1 = (int)(((double)z1 * -(sin(m->rx))) + ((double)z1 * cos(m->rx)));
	z2 = (int)(((double)z2 * -(sin(m->rx))) + ((double)z2 * cos(m->rx)));

	line(x1 + m->posx, y1 + z1 + m->posy, x2 + m->posx, y2 + z2 + m->posy);
}

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

void	draw(t_data *d, t_map *m, t_img *i)
{
	int		z;
	int		z2;

	itow(d->bkg.img, 0, 0, "background");
	if (!(i->img))
		i->img = newi(i, WIN_X, WIN_Y, "d->fdf");
	clearimg(i);
	m->y = -1;
	while (++m->y < m->ym && (m->x = -1))
	{
		while (++m->x < m->xm)
		{
			z = (int)((double)m->map[m->y][m->x] * m->heigh) * -1;
			if ((m->x + 1) < m->xm)
			{
				z2 = (int)((double)m->map[m->y][m->x + 1] * m->heigh) * -1;
				m->color = (z2 != 0 || z != 0) ? 1 : 0;
				prepline(m->x * m->size, m->y * m->size, z,
				(m->x + 1) * m->size, m->y * m->size, z2);
				// line(m->x * m->size + m->posx, z + m->y * m->size + m->posy,
				// (m->x + 1) * m->size + m->posx, z2 + m->y * m->size + m->posy);
			}
			if ((m->y + 1) < m->ym)
			{
				z2 = (int)((double)m->map[m->y + 1][m->x] * m->heigh) * -1;
				m->color = (z2 != 0 || z != 0) ? 1 : 0;
				prepline(m->x * m->size, m->y * m->size, z,
				m->x * m->size, (m->y + 1) * m->size, z2);
				// line(m->x * m->size + m->posx, z + m->y * m->size + m->posy,
				// m->x * m->size + m->posx, z2 + (m->y + 1) * m->size + m->posy);
			}
		}
	}
	itow(d->fdf.img, 0 * loop(0), 0, "fdf");
}
