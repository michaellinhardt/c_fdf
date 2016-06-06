/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:24:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 20:21:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	scene_main(t_data *d, t_menu *m)
{
	mlx_put_image_to_window(d->mlx, d->win, d->bkg.img, 0, 0);
	(m->open == 1) ? menu_open(d, &d->imenu, m) : 1;
}

void	scene_hook(t_data *d)
{
	if (d->scene == INTRO_LOAD)
		intro_load(d, &d->img, &d->intro);
	else if (d->scene == INTRO_MENU)
		intro_menu(d, &d->pressany, &d->intro);
	else if (d->scene == INTRO_OUT)
		intro_out(d, &d->img, &d->intro, &d->pressany);
	else if (d->scene == MAIN_LOAD)
		background_load(d, &d->bkg, &d->img);
	else if (d->scene == MAIN)
		scene_main(d, &d->menu);
}

int		loop_hook(t_data *d)
{
	scene_hook(d);
	return (0);
}
