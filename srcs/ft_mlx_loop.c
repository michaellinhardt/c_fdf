/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:24:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/08/04 18:19:16 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	scene_main(t_data *d, t_menu *m, t_input *i)
{
	if (!m->open)
		itow(d->bkg.img, 0, 0, "background");
	(m->open == 3) ? menu_close(d, &d->imenu, &d->menu, d->menu.start) : 1;
	(m->open == 2) ? menu_refresh(d, &d->imenu, &d->menu, d->menu.start) : 1;
	(m->open == 1) ? menu_open(d, &d->imenu, m) : 1;
	if (d->map.status == -1 && m->open == 0)
	{
		i->left += 0;
		(i->left) ? (d->map.rz += 0.1) : 0;
		(i->right) ? (d->map.rz -= 0.1) : 0;
		// (i->left) ? (d->map.posx -= MOVE_SPEED) : 0;
		// (i->right) ? (d->map.posx += MOVE_SPEED) : 0;
		// (i->up) ? (d->map.posy -= MOVE_SPEED) : 0;
		// (i->down) ? (d->map.posy += MOVE_SPEED) : 0;
		draw(d, &d->map, &d->fdf);
	}
	if (!m->open)
		itow(d->border.img, 0, 0, "border");
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
		scene_main(d, &d->menu, &d->input);
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
