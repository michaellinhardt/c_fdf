/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:21:54 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	data_init(t_data *d)
{
	ft_bzero(d, sizeof(t_data));
	d->scene = SCENE_START;
	d->img.img = (void *)NULL;
	d->img.str = (char *)NULL;
	d->intro.img = (void *)NULL;
	d->intro.str = (char *)NULL;
	d->pressany.img = (void *)NULL;
	d->pressany.str = (char *)NULL;
	d->imenu.img = (void *)NULL;
	d->imenu.str = (char *)NULL;
	d->menu.fade = 255;
	d->menu.x = 471;
	d->menu.y = 117;
	d->menu.lst = (t_lmenu *)NULL;
	d->loop = 1;
}

int		main(void)
{
	t_data	d;

	data_init(&d);
	mlx_handler(&d, 0);
	mlx_handler(&d, 1);
	return (0);
}
