/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:48:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		menu_data(t_data *d, t_lmenu *new, DIR *dir, struct dirent *f)
{
	(d->menu.lst) ? flmenu(d) : 0;
	ft_printf("menu load\n");
	if (!(dir = opendir(MAP_DIR)))
		exit1(1, d, "Cant open maps dir.");
	while ((f = readdir(dir)))
	{
		if (f->d_namlen > 4095 || !ft_strcmp(".", f->d_name)
		|| !ft_strcmp("..", f->d_name) || !ft_strcmp(".DS_Store", f->d_name))
			continue ;
		if (!(new = (t_lmenu *)ft_memalloc(sizeof(t_lmenu))))
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
	while (new->n)
		new = new->n;
	d->menu.lst = new;
	return (1);
}

void	menu_open(t_data *d, t_img *i, t_menu *m)
{
	if (!(i->img) && !(i->img = mlx_xpm_file_to_image(d->mlx, XPM_MENU
		, &i->sl, &i->end)))
		exit1(1, d, "Cant load menu.xpm in data.menu!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if (i->str[i->i] == 0 && i->str[i->i + 1] == 0 && i->str[i->i + 2] == 0)
			i->str[i->i + 3] = 255;
		else
			i->str[i->i + 3] = m->fade;
	}
	(m->fade > 0) ? (m->fade -= 15) : 0;
	mlx_put_image_to_window(d->mlx, d->win, i->img, m->x, m->y);
	(m->fade == 0 && menu_data(d, (t_lmenu *)NULL, (DIR *)NULL
	 													,(struct dirent *)NULL))
	 	? (d->loop = 0) : 1;
}
