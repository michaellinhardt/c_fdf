/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:24:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/29 07:54:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	scene_main(t_data *d, t_menu *m)
{
	itow(d->bkg.img, 0, 0, "background");
	(m->open == 3) ? menu_close(d, &d->imenu, &d->menu, d->menu.start) : 1;
	(m->open == 2) ? menu_refresh(d, &d->imenu, &d->menu, d->menu.start) : 1;
	(m->open == 1) ? menu_open(d, &d->imenu, m) : 1;
}

void	scene_hook(t_data *d)
{
	if (d->scene == INTRO_LOAD)
		intro_load(d, &d->img, &d->intro);
	else if (d->scene == INTRO_MENU)
		intro_menu(&d->pressany, &d->intro);
	else if (d->scene == INTRO_OUT)
		intro_out(d, &d->img, &d->intro, &d->pressany);
	else if (d->scene == MAIN_LOAD)
		background_load(d, &d->bkg, &d->img);
	else if (d->scene == MAIN)
		scene_main(d, &d->menu);
}

int		loop_hook(t_data *d)
{
	if (d->map.status > 0)
		parse(d, &d->map);
	if (USLEEP_BOOL && d->loop == 0 && !usleep(USLEEP_TIME))
		return (0);
	if (d->loopstop > 0 && --d->loopstop == 0)
		loop(0);
	if (d->scenelast != d->scene && l3(1))
		d->scenelast = d->scene;
	scene_hook(d);
	return (0);
}
