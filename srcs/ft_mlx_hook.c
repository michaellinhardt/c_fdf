/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 22:03:33 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		mousem_hook(int x, int y, t_data *d)
{
	d->mx = x;
	d->my = y;
	if (d->menu.open == 2)
		menu_mouseover(d, &d->menu, d->menu.start);
	if (d->menu.open == 0 && d->map.status == -1 && d->input.mleft == 1)
	{
		d->map.posx += (x - d->input.x);
		d->map.posy += (y - d->input.y);
		d->input.x = x;
		d->input.y = y;
		d->loopstop = loop(1) * 10;
	}
	if (d->menu.open == 0 && d->map.status == -1 && d->input.mright == 1)
	{
		d->map.rx += (double)(y - d->input.y) / 80;
		d->map.ry -= (double)(x - d->input.x) / 80;
		d->input.x = x;
		d->input.y = y;
		d->loopstop = loop(1) * 10;
	}
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	if (l2(2, "RELEASE", "-> (int) key", key) && key == 53)
		exit1(0, d, "by pressing echap");
	else if (d->scene == INTRO_MENU)
		d->scene = INTRO_OUT;
	else if (d->scene == MAIN && key == 49 && loop(1))
	{
		d->menu.open = (d->menu.open != 0
			&& (d->menu.fade = 255)) ? 0 : 1;
		d->loopstop = (d->menu.open == 0 && l1(1, "MENU", "CLOSE")) ? 1 : 0;
	}
	else if (d->menu.open == 0)
	{
		(key == 116 && d->input.shift == 0) ? zoomin(d, &d->map
			, d->input.x, d->input.y) : 1;
		(key == 121 && d->input.shift == 0) ? zoomout(d, &d->map
			, d->input.x, d->input.y) : 1;
		(key == 116 && d->input.shift == 1) ? zoomzin(d, &d->map) : 1;
		(key == 121 && d->input.shift == 1) ? zoomzout(d, &d->map) : 1;
		(key == 123) ? d->input.left = 0 * loop(1) : 0;
		(key == 124) ? d->input.right = 0 * loop(1) : 0;
		(key == 125) ? d->input.down = 0 * loop(1) : 0;
		(key == 126) ? d->input.up = 0 * loop(1) : 0;
		(key == 257) ? d->input.shift = 0 : 0;
	}
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	d->i += 0;
	l2(2, "PRESS", "-> (int) key", key);
	if (d->menu.open == 0)
	{
		(key == 123) ? d->input.left = loop(1) : 0;
		(key == 124) ? d->input.right = loop(1) : 0;
		(key == 125) ? d->input.down = loop(1) : 0;
		(key == 126) ? d->input.up = loop(1) : 0;
		(key == 257) ? d->input.shift = 1 : 0;
	}
	return (0);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	l4(btn, x, y, "PRESS");
	if (d->menu.open == 0 && d->map.status == -1)
	{
		(btn == 4 && d->input.shift == 0) ? zoomin(d, &d->map, x, y) : 1;
		(btn == 5 && d->input.shift == 0) ? zoomout(d, &d->map, x, y) : 1;
		(btn == 6 && d->input.shift == 1) ? zoomzin(d, &d->map) : 1;
		(btn == 7 && d->input.shift == 1) ? zoomzout(d, &d->map) : 1;
		(btn == 1) ? d->input.mleft = 1 : 0;
		(btn == 2) ? d->input.mright = 1 : 0;
		d->input.x = x;
		d->input.y = y;
	}
	return (0);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	l4(btn, x, y, "RELEASE");
	if (d->menu.open == 2)
		menu_mouserelease(d, &d->menu, x, y);
	if (d->menu.open == 0 && d->map.status == -1)
	{
		if (btn == 1)
			d->input.mleft = 0;
		else if (btn == 2)
			d->input.mright = 0;
	}
	return (0);
}
