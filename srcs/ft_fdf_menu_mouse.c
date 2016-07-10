/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/10 05:05:10 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouserelease(t_data *d, t_menu *m, int x, int y)
{
	t_lmenu		*l;

	((l = m->start) && m->u == 1 && mr(ARROWU, x, y) && (m->start = m->start->n)
	&& (m->calcpos = 1)) ? loop(1) : 1;
	(m->d == 1 && mr(ARROWD, x, y) && (m->start = m->start->p)
	&& (m->calcpos = 1)) ? loop(1) : 1;
	while (l && l->id <= (m->start->id + 9))
	{
		if (d->mx >= l->area[2] && d->mx <= l->area[4]
		&& d->my >= l->area[3] && d->my <= l->area[5])
		{
			if (d->map.status > 0)
				l2(1, l->path, "already reading a map", l->id);
			else if ((m->over = l))
			{
				((m->open = 3) && ((m->yclose = l->area[1]) || 1)) ?
				fmap(d, -1, 0) : 1;
				d->loopstop = 0;
				ft_printf("%!./maps/%s", &d->map.path, l->path);
				(d->map.status = 1) ? loop(1) : 0;
			}
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
			d->loopstop = 15;
			return ;
		}
		l = l->p;
	}
	if (((m->u && mo(ARROWU) && m->mo != ARROWU && (m->mo = ARROWU))
	|| (m->u && !mo(ARROWU) && m->mo == ARROWU && !(m->mo = INIT))
	|| (m->d && mo(ARROWD) && m->mo != ARROWD && (m->mo = ARROWD))
	|| (m->d && !mo(ARROWD) && m->mo == ARROWD && !(m->mo = INIT))) && loop(1))
		return ;
	if (m->mo == MENU && ((m->mo = INIT) || 1))
		d->loopstop = loop(1) + 15;
}
