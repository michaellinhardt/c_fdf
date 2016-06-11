/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/11 05:48:35 by mlinhard         ###   ########.fr       */
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
				l2(1, l->path, "cant load now", l->id);
			else if (l2(1, l->path, "is loading", l->id) && (m->over = l))
			{
				((m->open = 3) && ((m->yclose = l->area[1]) || 1)) ?
				ft_strdel(&d->map.path) : 1;
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
