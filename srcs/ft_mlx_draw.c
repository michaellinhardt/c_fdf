/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 03:06:06 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/10 03:30:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	draw(t_data *d, t_map *m, t_img *i)
{
	if (d)
		m->i += 0;
	if (!(i->img))
		i->img = newi(i, DRAW_X2 - DRAW_X1, DRAW_Y2 - DRAW_Y1, "d->fdf");

	itow(i->img, DRAW_X1, DRAW_Y1, "display fdf");
	loop(0);
}
