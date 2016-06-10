/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/10 04:26:11 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouserelease(t_data *d, t_menu *m, int x, int y)
{
	t_lmenu		*l;

	l = m->start;
	(m->u == 1 && mr(ARROWU, x, y) && (m->start = m->start->n)
	&& (m->calcpos = 1)) ? loop(1) : 1;
	(m->d == 1 && mr(ARROWD, x, y) && (m->start = m->start->p)
	&& (m->calcpos = 1)) ? loop(1) : 1;
	while (l && l->id <= (m->start->id + 9))
	{
		if (d->mx >= l->area[2] && d->mx <= l->area[4]
		&& d->my >= l->area[3] && d->my <= l->area[5])
		{
			(d->path) ? l2(1, l->path, "cant load now", l->id) : 0;
			(!d->path) ? l2(1, l->path, "is loading", l->id) : 0;
			m->over = l;
			m->yclose = l->area[1];
			m->open = 3;
			loop(1);
			break ;
		}
		l = l->p;
	}
}

void	menu_mouseover(t_data *d, t_menu *m, t_lmenu *l)
{
	while (l && l->id <= (m->start->id + 9))
	{
		if (d->mx >= l->area[2] && d->mx <= l->area[4]
		&& d->my >= l->area[3] && d->my <= l->area[5])
		{
			m->mo = MENU;
			loop(1);
			return ;
		}
		l = l->p;
	}
	if (((m->u && mo(ARROWU) && m->mo != ARROWU && (m->mo = ARROWU))
	|| (m->u && !mo(ARROWU) && m->mo == ARROWU && !(m->mo = INIT))
	|| (m->d && mo(ARROWD) && m->mo != ARROWD && (m->mo = ARROWD))
	|| (m->d && !mo(ARROWD) && m->mo == ARROWD && !(m->mo = INIT))) && loop(1))
		return ;
	(m->mo == MENU && ((m->mo = INIT) || 1)) ? loop(1) : 0;
}
