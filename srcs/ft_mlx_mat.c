/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 17:19:56 by mlinhard          #+#    #+#             */
/*   Updated: 2016/08/04 18:37:00 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <math.h>

void	maty(t_map *m, t_mat *r)
{
	// if (!r->lock)
	// 	r->x1 = (int)(((double)r->x1 * cos(m->ry)) + ((double)r->x1 * -(sin(m->ry))));
	// r->x2 = (int)(((double)r->x2 * cos(m->ry)) + ((double)r->x2 * -(sin(m->ry))));
	// if (!r->lock)
	// 	r->z1 = (int)(((double)r->z1 * sin(m->ry)) + ((double)r->z1 * cos(m->ry)));
	// r->z2 = (int)(((double)r->z2 * sin(m->ry)) + ((double)r->z2 * cos(m->ry)));

	if (!r->lock)
		r->x1 = (int)(((double)r->x1 * cos(m->ry)) + ((double)r->z1 * sin(m->ry)));
	r->x2 = (int)(((double)r->x2 * cos(m->ry)) + ((double)r->z2 * sin(m->ry)));
	if (!r->lock)
		r->z1 = (int)(((double)r->x1 * -(sin(m->ry))) + ((double)r->z1 * cos(m->ry)));
	r->z2 = (int)(((double)r->x2 * -(sin(m->ry))) + ((double)r->z2 * cos(m->ry)));
}

void	matz(t_map *m, t_mat *r)
{
	if (!r->lock)
		r->x1 = (int)(((double)r->x1 * cos(m->rz)) + ((double)r->x1 * sin(m->ry)));
	r->x2 = (int)(((double)r->x2 * cos(m->rz)) + ((double)r->x2 * sin(m->ry)));
	if (!r->lock)
		r->y1 = (int)(((double)r->y1 * -(sin(m->rz))) + ((double)r->y1 * cos(m->rz)));
	r->y2 = (int)(((double)r->y2 * -(sin(m->rz))) + ((double)r->y2 * cos(m->rz)));
}

void	matx(t_map *m, t_mat *r)
{
	// if (!r->lock)
	// 	r->y1 = (int)(((double)r->y1 * cos(m->rx)) + ((double)r->y1 * sin(m->rx)));
	// r->y2 = (int)(((double)r->y2 * cos(m->rx)) + ((double)r->y2 * sin(m->rx)));
	// if (!r->lock)
	// 	r->z1 = (int)(((double)r->z1 * -(sin(m->rx))) + ((double)r->z1 * cos(m->rx)));
	// r->z2 = (int)(((double)r->z2 * -(sin(m->rx))) + ((double)r->z2 * cos(m->rx)));


	if (!r->lock)
		r->y1 = (int)(((double)r->y1 * cos(m->rx)) - ((double)r->z1 * sin(m->rx)));
	r->y2 = (int)(((double)r->y2 * cos(m->rx)) - ((double)r->z2 * sin(m->rx)));
	if (!r->lock)
		r->z1 = (int)(((double)r->y1 * sin(m->rx)) + ((double)r->z1 * cos(m->rx)));
	r->z2 = (int)(((double)r->y2 * sin(m->rx)) + ((double)r->z2 * cos(m->rx)));
}

void	addmatrice(t_map *m)
{
	matx(m, &m->mat);
	maty(m, &m->mat);
	// matz(m, &m->mat);
	m->mat.lock = 1;
}
