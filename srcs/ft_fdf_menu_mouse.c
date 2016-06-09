/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 18:21:21 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouserelease(t_data *d, t_menu *m, int x, int y)
{
	(m->u && mr(ARROWU, x, y) && (m->start = m->start->n)) ? loop(1) : 1;
	(m->d && mr(ARROWD, x, y) && (m->start = m->start->p)) ? loop(1) : 1;
}

void	menu_mouseover(t_data *d, t_menu *m, t_lmenu *l)
{
	(m->u && mo(ARROWU) && m->mo != ARROWU && (m->mo = ARROWU)) ? loop(1) : 0;
	(m->u && !mo(ARROWU) && m->mo == ARROWU && !(m->mo = INIT)) ? loop(1) : 0;
	(m->d && mo(ARROWD) && m->mo != ARROWD && (m->mo = ARROWD)) ? loop(1) : 0;
	(m->d && !mo(ARROWD) && m->mo == ARROWD && !(m->mo = INIT)) ? loop(1) : 0;
	while (l && l->id <= (m->start->id + 9))
	{
		if (d->mx >= l->area[2] && d->mx <= l->area[4]
		&& d->my >= l->area[3] && d->my <= l->area[5])
			loop(1);
		l = l->p;
	}
}
