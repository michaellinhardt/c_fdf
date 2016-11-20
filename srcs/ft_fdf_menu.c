/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 22:16:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		menu_close(t_data *d, t_img *im, t_menu *m, t_lmenu *lst)
{
	static char		tmp[15] = { 'a' };

	if (tmp[0] == 'a' && ft_bzero(tmp, 15) && (tmp[13] = '.'))
	{
		tmp[12] = '.';
		tmp[11] = '.';
	}
	itow(im->img, m->xpos, m->ypos, "menu xpm");
	itow(xtoi(&d->arrowu3, XPM_ARROWU3), x(ARROWU)[0], x(ARROWU)[1]
	, "Arrow up off");
	itow(xtoi(&d->arrowd3, XPM_ARROWD3), x(ARROWD)[0], x(ARROWD)[1]
	, "Arrow down off");
	m->close = 0;
	while (lst && lst->id <= (m->start->id + 9))
	{
		m->close += menu_close_anim(m, lst);
		menu_btndisplay(d, lst, tmp, 0);
		lst = lst->p;
	}
	menu_btndisplay(d, m->over, tmp, 0);
	if (m->close == 0 && (m->fade = 255))
		m->open = 0;
	return (1);
}

int		menu_refresh(t_data *d, t_img *im, t_menu *m, t_lmenu *l)
{
	static char		tmp[15] = { 'a' };

	if (tmp[0] == 'a' && ft_bzero(tmp, 15) && (tmp[13] = '.'))
	{
		tmp[12] = '.';
		tmp[11] = '.';
	}
	itow(im->img, m->xpos, m->ypos, "menu xpm");
	(!l->n && !(m->u = 0)) ? itow(xtoi(&d->arrowu3
		, XPM_ARROWU3), x(ARROWU)[0], x(ARROWU)[1], "Arrow up off") : 1;
	((m->start->id + 10) > m->size && !(m->d = 0)) ? itow(xtoi(&d->arrowd3
		, XPM_ARROWD3), x(ARROWD)[0], x(ARROWD)[1], "Arrow down off") : 1;
	(l->n && (m->u = 1) && !mo(ARROWU)) ? itow(xtoi(&d->arrowu1, XPM_ARROWU1)
	, x(ARROWU)[0], x(ARROWU)[1], "Arrow up") : 1;
	(l->n && (m->u = 1) && mo(ARROWU)) ? itow(xtoi(&d->arrowu2, XPM_ARROWU2)
	, x(ARROWU)[0], x(ARROWU)[1], "Arrow up mouse over") : 1;
	((m->start->id + 10) <= m->size && (m->d = 1) && !mo(ARROWD)) ? itow(xtoi(
	&d->arrowd1, XPM_ARROWD1), x(ARROWD)[0], x(ARROWD)[1], "Arrow down") : 1;
	((m->start->id + 10) <= m->size && (m->d = 1) && mo(ARROWD)) ? itow(xtoi(
	&d->arrowd2, XPM_ARROWD2), x(ARROWD)[0], x(ARROWD)[1], "Arrow down") : 1;
	menu_btnpos(d, m, l, tmp);
	return (1);
}

int		truc_nul(t_data *d, t_lmenu *new)
{
	d->menu.lst = new;
	d->menu.start = new;
	return (1);
}

int		menu_data(t_data *d, t_lmenu *new, DIR *dir, struct dirent *f)
{
	(!(d->i = 0) && d->menu.lst) ? flmenu(d, 0) : 0;
	if (!(dir = opendir(MAP_DIR)))
		exit1(1, d, "Cant open maps dir.");
	while ((f = readdir(dir)))
	{
		if (f->d_namlen > 4095 || !ft_strcmp(".", f->d_name)
		|| !ft_strcmp("..", f->d_name) || !ft_strcmp(".DS_Store", f->d_name))
			continue ;
		if (++d->i && !(new = (t_lmenu *)ft_memalloc(sizeof(t_lmenu))))
			exit1(1, d, "Cant malloc t_lmenu struct.");
		ft_memcpy(new->path, f->d_name, f->d_namlen);
		if (!d->menu.lst && (d->menu.lst = new))
			(!(new->p = (t_lmenu *)NULL))
				? new->n = (t_lmenu *)NULL : (t_lmenu *)NULL;
		else if ((new->n = d->menu.lst))
			((d->menu.lst->p = new))
			? d->menu.lst = new : (t_lmenu *)NULL;
	}
	closedir(dir);
	if (!(new = d->menu.lst))
		return (d->menu.open = 0 * l1(1, "MENU", "maps dir is empty"));
	d->menu.size = d->i;
	while (((new->id = d->i--) || 1) && new->n)
		new = new->n;
	return (truc_nul(d, new));
}

void	menu_open(t_data *d, t_img *i, t_menu *m)
{
	if (!menu_data(d, (t_lmenu *)NULL, (DIR *)NULL, (struct dirent *)NULL))
		return ;
	i->img = xtoi(i, XPM_MENU);
	i->i = -4;
	while ((i->i += 4) < (i->sl * 454))
	{
		if (i->str[i->i] == 0 && i->str[i->i + 1] == 0 && i->str[i->i + 2] == 0)
			i->str[i->i + 3] = 255;
		else
			i->str[i->i + 3] = m->fade;
	}
	(m->fade > 0) ? (m->fade -= 15) : 0;
	itow(i->img, m->xpos, m->ypos, "menu xpm");
	if (m->fade == 0 && l1(1, "MENU", "OPEN") && l1(1, "READDIR", MAP_DIR)
	&& (m->calcpos = 1)
	&& menu_refresh(d, &d->imenu, &d->menu, d->menu.start))
		m->open = 2;
	d->loopstop = 15;
}
