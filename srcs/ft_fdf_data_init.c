/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_data_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 20:25:13 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 20:25:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	data_init3(t_data *d)
{
	d->btnoff.img = (void *)NULL;
	d->btnoff.str = (char *)NULL;
	d->btnover.img = (void *)NULL;
	d->btnover.str = (char *)NULL;
	d->arrowu1.img = (void *)NULL;
	d->arrowu1.str = (char *)NULL;
	d->arrowu2.img = (void *)NULL;
	d->arrowu2.str = (char *)NULL;
	d->arrowu3.img = (void *)NULL;
	d->arrowu3.str = (char *)NULL;
	d->arrowd1.img = (void *)NULL;
	d->arrowd1.str = (char *)NULL;
	d->arrowd2.img = (void *)NULL;
	d->arrowd2.str = (char *)NULL;
	d->arrowd3.img = (void *)NULL;
	d->arrowd3.str = (char *)NULL;
	d->border.img = (void *)NULL;
	d->border.str = (char *)NULL;
}

void	data_init2(t_data *d)
{
	d->img.img = (void *)NULL;
	d->img.str = (char *)NULL;
	d->intro.img = (void *)NULL;
	d->intro.str = (char *)NULL;
	d->pressany.img = (void *)NULL;
	d->pressany.str = (char *)NULL;
	d->fdf.img = (void *)NULL;
	d->fdf.str = (char *)NULL;
	d->imenu.img = (void *)NULL;
	d->imenu.str = (char *)NULL;
	data_init3(d);
}

void	data_init(t_data *d, int argc, char **argv)
{
	ft_bzero(d, sizeof(t_data));
	data_init2(d);
	d->scene = MAIN_LOAD;
	d->scenelast = d->scene;
	d->menu.fade = 255;
	d->menu.xpos = 471;
	d->menu.ypos = 117;
	d->menu.lst = (t_lmenu *)NULL;
	d->map.read[0] = '\0';
	d->map.i = -1;
	d->map.path = (argc == 2) ? ft_strdup(argv[1]) : (char *)NULL;
	d->map.status = (d->map.path) ? 1 : 0;
	d->menu.open = (argv[1]) ? 0 : 1;
	d->menu.mo = INIT;
	d->loop = 1;
	C(d->menu.btnpos, x(MENU), 24);
}
