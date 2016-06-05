/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 19:24:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/05 19:23:45 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	scene_hook(t_data *d)
{
	if (d->scene == INTRO_LOAD)
		intro_load(d, &d->img, &d->logo);
	if (d->scene == INTRO_MENU)
		intro_menu(d, &d->img, &d->logo);
}

int		loop_hook(t_data *d)
{
	scene_hook(d);
	return (0);
}
