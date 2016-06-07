/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:48:15 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		red_cross(void)
{
	exit (0);
	return (0);
}

int		keyr_hook(int key, t_data *d)
{
	ft_printf("key_release: %d\n", key);
	if (key == 53)
		exit1(0, d, "Exit!\n");
	else if (d->scene == INTRO_MENU)
		d->scene = INTRO_OUT;
	else if (d->scene == MAIN && key == 49 && (d->loop = 1))
	{
		d->menu.open = (d->menu.open == 1 && (d->menu.fade = 255)) ? 0 : 1;
		d->loopstop = (d->menu.open == 0) ? 1 : 0;
	}
	return (0);
	d->x += 0;
}

int		keyp_hook(int key, t_data *d)
{
	ft_printf("key_press..: %d\n", key);
	return (0);
	d->x += 0;
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSEPress: X.: %d\t\tY.: %d\n", x, y);
	return (0);
	d->x += 0;
	btn += 0;
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSERelease: X.: %d\t\tY.: %d\n", x, y);
	return (0);
	d->x += 0;
	btn += 0;
}
