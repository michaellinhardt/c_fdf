/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 05:51:30 by mlinhard         ###   ########.fr       */
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
		mlx_destroy_window(d->mlx, d->win), exit(0);
	return (0);
}

int		keyp_hook(int key, t_data *d)
{
	ft_printf("key_press..: %d\n", key);
	return (0);
}

int		mousep_hook(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSEPress: X.: %d\t\tY.: %d\n", x, y);
	return (0);
}

int		mouser_hook(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSERelease: X.: %d\t\tY.: %d\n", x, y);
	return (0);
}
