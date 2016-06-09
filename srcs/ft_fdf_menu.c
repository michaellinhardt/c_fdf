/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:10:55 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	debug_mo(enum coord coord)
{
	line(x(coord)[2], x(coord)[3], x(coord)[4], x(coord)[5]);
}

int		menu_refresh(t_data *d, t_img *im, t_menu *m, t_lmenu *l)
{

	itow(im->img, m->xpos, m->ypos, "menu xpm");
	((l->n || 1) && !mo(ARROWU1)) ? itow(xtoi(&d->arrowu1, XPM_ARROWU1), x(ARROWU1)[0], x(ARROWU1)[1], "Arrow up") : 1;
	((l->n || 1) && mo(ARROWU1)) ? itow(xtoi(&d->arrowu2, XPM_ARROWU2), x(ARROWU1)[0], x(ARROWU1)[1], "Arrow up mouse over") : 1;
	// debug_mo(ARROWU1);
	loop(0);
	return (1);
}

int		menu_data(t_data *d, t_lmenu *new, DIR *dir, struct dirent *f)
{
	(!(d->i = 0) && d->menu.lst) ? flmenu(d) : 0;
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
			(!(new->p = (t_lmenu *)NULL)) ?
				new->n = (t_lmenu *)NULL : (t_lmenu *)NULL;
		else if ((new->n = d->menu.lst))
			((d->menu.lst->p = new)) ? d->menu.lst = new : (t_lmenu *)NULL;
	}
	closedir(dir);
	new = d->menu.lst;
	d->menu.size = d->i;
	while (((new->id = d->i--) || 1) && new->n)
		new = new->n;
	d->menu.lst = new;
	d->menu.start = new;
	return (1);
}

void	menu_open(t_data *d, t_img *i, t_menu *m)
{
	if (!(i->img))
		i->img = xtoi(i, XPM_MENU);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if (i->str[i->i] == 0 && i->str[i->i + 1] == 0 && i->str[i->i + 2] == 0)
			i->str[i->i + 3] = 255;
		else
			i->str[i->i + 3] = m->fade;
	}
	(m->fade > 0) ? (m->fade -= 15) : 0;
	itow(i->img, m->xpos, m->ypos, "menu xpm");
	(m->fade == 0 && l(1, "MENU", "OPEN") && l(1, "READDIR", MAP_DIR)
	&& menu_data(d, (t_lmenu *)NULL, (DIR *)NULL, (struct dirent *)NULL)
	&& menu_refresh(d, i, &d->menu, d->menu.start) && (m->open = 2))
	 	? (loop(0)) : 1;
}
