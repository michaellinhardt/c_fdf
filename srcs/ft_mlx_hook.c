/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/08 09:45:58 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		red_cross(void)
{
	t_data *d;

	d = data();
	exit1(0, d, "by clic on red cross");
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	l2(2, "RELEASE", "-> (int) key", key);
	if (key == 53)
		exit1(0, d, "by pressing echap");
	else if (d->scene == INTRO_MENU)
		d->scene = INTRO_OUT;
	else if (d->scene == MAIN && key == 49 && (d->loop = 1))
	{
		d->menu.open = (d->menu.open == 1 && (d->menu.fade = 255)) ? 0 : 1;
		d->loopstop = (d->menu.open == 0 && l(1, "MENU", "CLOSE")) ? 1 : 0;
	}
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	l2(2, "PRESS", "-> (int) key", key);
	return (0);
	d->x += 0;
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	l4(btn, x, y, "PRESS");
	return (0);
	d->x += 0;
	btn += 0;
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	l4(btn, x, y, "RELEASE");
	return (0);
	d->x += 0;
	btn += 0;
}
