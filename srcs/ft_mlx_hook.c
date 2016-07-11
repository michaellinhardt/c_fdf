/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/11 21:17:03 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		mousem_hook(int x, int y, t_data *d)
{
	d->mx = x;
	d->my = y;

	if (d->menu.open == 2)
		menu_mouseover(d, &d->menu, d->menu.start);
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	l2(2, "RELEASE", "-> (int) key", key);
	if (key == 53)
		exit1(0, d, "by pressing echap");
	else if (d->scene == INTRO_MENU)
		d->scene = INTRO_OUT;
	else if (d->scene == MAIN && key == 49 && loop(1))
	{
		d->menu.open = (d->menu.open != 0 && (d->menu.fade = 255)) ? 0 : 1;
		d->loopstop = (d->menu.open == 0 && l(1, "MENU", "CLOSE")) ? 1 : 0;
	}
	else if (d->menu.open == 0)
	{
		(key == 123) ? d->input.left = 0 * loop(1): 0;
		(key == 124) ? d->input.right = 0 * loop(1): 0;
		(key == 125) ? d->input.down = 0 * loop(1): 0;
		(key == 126) ? d->input.up = 0 * loop(1): 0;
	}
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	d->i += 0;
	l2(2, "PRESS", "-> (int) key", key);
	if (d->menu.open == 0)
	{
		(key == 123) ? d->input.left = loop(1): 0;
		(key == 124) ? d->input.right = loop(1): 0;
		(key == 125) ? d->input.down = loop(1): 0;
		(key == 126) ? d->input.up = loop(1): 0;
	}
	return (0);
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
	if (d->menu.open == 2)
		menu_mouserelease(d, &d->menu, x, y);
	return (0);
	d->x += 0;
	btn += 0;
}
