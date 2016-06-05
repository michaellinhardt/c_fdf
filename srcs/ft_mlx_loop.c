/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:24:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 00:36:31 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	scene_hook(t_data *d)
{
	if (d->scene == INTRO_LOAD)
		intro_load(d, &d->img, &d->intro);
	else if (d->scene == INTRO_MENU)
		intro_menu(d, &d->pressany, &d->intro);
	else if (d->scene == INTRO_OUT)
		intro_out(d, &d->img, &d->intro, &d->pressany);
	else if (d->scene == MAIN)
		d->scene = INTRO_LOAD;
}

int		loop_hook(t_data *d)
{
	scene_hook(d);
	return (0);
}
