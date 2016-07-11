/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:06:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/11 11:14:48 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw(t_data *d, t_map *m, t_img *i)
{
	int		z;
	int		z2;

	itow(d->bkg.img, 0 * loop(0), 0, "background");
	if (!(i->img))
		i->img = newi(i, WIN_X, WIN_Y, "d->fdf");
	m->y = -1;
	// itow(i->img, 0, 0, "display fdf");
	while (++m->y < m->ym && (m->x = -1))
	{
		while (++m->x < m->xm)
		{
			(m->map[m->y][m->x] == 0) ? (z = 0) : 1;
			(m->map[m->y][m->x] < 0) ? (z = m->size * 1) : 1;
			(m->map[m->y][m->x] > 0) ? (z = m->size * -1) : 1;
			if ((m->x + 1) < m->xm)
			{
				(m->map[m->y][m->x + 1] == 0) ? (z2 = 0) : 1;
				(m->map[m->y][m->x + 1] < 0) ? (z2 = m->size * 1) : 1;
				(m->map[m->y][m->x + 1] > 0) ? (z2 = m->size * -1) : 1;
				line(m->x * m->size + m->posx, z + m->y * m->size + m->posy,
				(m->x + 1) * m->size + m->posx, z2 + m->y * m->size + m->posy);
			}
			if ((m->y + 1) < m->ym)
			{
				(m->map[m->y + 1][m->x] == 0) ? (z2 = 0) : 1;
				(m->map[m->y + 1][m->x] < 0) ? (z2 = m->size * 1) : 1;
				(m->map[m->y + 1][m->x] > 0) ? (z2 = m->size * -1) : 1;
				line(m->x * m->size + m->posx, z + m->y * m->size + m->posy,
				m->x * m->size + m->posx, z2+ (m->y + 1) * m->size + m->posy);
			}
		}
	}
}
