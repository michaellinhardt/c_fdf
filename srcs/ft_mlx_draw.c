/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:06:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/10 08:38:48 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw(t_data *d, t_map *m, t_img *i)
{
	int		z;
	int		z2;

	if (d)
		m->i += 0;
	if (!(i->img))
		i->img = newi(i, DRAW_X2 - DRAW_X1, DRAW_Y2 - DRAW_Y1, "d->fdf");
	m->y = -1;
	itow(i->img, DRAW_X1, DRAW_Y1, "display fdf");
	while (++m->y < m->ym && (m->x = -1))
	{
		while (++m->x < m->xm)
		{
			ft_printf("Coord: %d,%d\n", m->x, m->y);
			(m->map[m->y][m->x] == 0) ? (z = 0) : 1;
			(m->map[m->y][m->x] < 0) ? (z = m->size * 1) : 1;
			(m->map[m->y][m->x] > 0) ? (z = m->size * -1) : 1;
			if ((m->x + 1) < m->xm)
			{
				(m->map[m->y][m->x + 1] == 0) ? (z2 = 0) : 1;
				(m->map[m->y][m->x + 1] < 0) ? (z2 = m->size * 1) : 1;
				(m->map[m->y][m->x + 1] > 0) ? (z2 = m->size * -1) : 1;
				line(m->x * m->size + (DRAW_X1 + m->size * 1), z + m->y * m->size + (DRAW_Y1 + m->size * 1),
				(m->x + 1) * m->size + (DRAW_X1 + m->size * 1), z2 + m->y * m->size + (DRAW_Y1 + m->size * 1));
			}
			if ((m->y + 1) < m->ym)
			{
				(m->map[m->y + 1][m->x] == 0) ? (z2 = 0) : 1;
				(m->map[m->y + 1][m->x] < 0) ? (z2 = m->size * 1) : 1;
				(m->map[m->y + 1][m->x] > 0) ? (z2 = m->size * -1) : 1;
				line(m->x * m->size + (DRAW_X1 + m->size * 1), z + m->y * m->size + (DRAW_Y1 + m->size * 1),
				m->x * m->size + (DRAW_X1 + m->size * 1), z2+ (m->y + 1) * m->size + (DRAW_Y1 + m->size * 1));
			}
		}
	}
	loop(0);
}
