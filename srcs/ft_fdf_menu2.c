/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 22:15:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_btndisplay(t_data *d, t_lmenu *l, char tmp[15], int mode)
{
	if ((mode == 1 && d->mx >= l->area[2] && d->mx <= l->area[4]
	&& d->my >= l->area[3] && d->my <= l->area[5]) || (mode == 0
	&& l->id == d->menu.over->id))
		itow(xtoi(&d->btnover, XPM_BTNOVER)
		, l->area[0], l->area[1], "Btn over");
	else
		itow(xtoi(&d->btnoff, XPM_BTNOFF)
		, l->area[0], l->area[1], "Btn off");
	if (ft_strlen(l->path) <= 14)
		mlx_string_put(d->mlx, d->win, l->area[0] + 10
		, l->area[1] + 7, 0xFFFFFF, l->path);
	else if (ft_memcpy(tmp, l->path, 11))
		mlx_string_put(d->mlx, d->win, l->area[0] + 10
	, l->area[1] + 7, 0xFFFFFF, tmp);
}

void	menu_btnpos(t_data *d, t_menu *m, t_lmenu *lst, char tmp[15])
{
	while (lst && lst->id <= (m->start->id + 9))
	{
		if (m->calcpos == 1)
		{
			lst->area[0] = m->btnpos[0];
			lst->area[1] = m->btnpos[1] + (38 * (lst->id - m->start->id));
			lst->area[2] = lst->area[0];
			lst->area[3] = lst->area[1];
			lst->area[4] = m->btnpos[4];
			lst->area[5] = m->btnpos[5] + (38 * (lst->id - m->start->id));
		}
		menu_btndisplay(d, lst, tmp, 1);
		lst = lst->p;
	}
	m->calcpos = 0;
}

int		menu_close_anim(t_menu *m, t_lmenu *lst)
{
	if (lst->area[1] != m->yclose)
	{
		if (lst->area[1] > m->yclose && ((lst->area[1] -= 8) || 1) &&
			lst->area[1] < m->yclose)
			lst->area[1] = m->yclose;
		else if (lst->area[1] < m->yclose && ((lst->area[1] += 8) || 1) &&
			lst->area[1] > m->yclose)
			lst->area[1] = m->yclose;
		return (1);
	}
	return (0);
}
