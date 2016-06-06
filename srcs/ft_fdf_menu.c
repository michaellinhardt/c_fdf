/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:43:55 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 23:34:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_open(t_data *d, t_img *i, t_menu *m)
{
	if (m->fade == 0 && !mlx_put_image_to_window(d->mlx, d->win, i->img, m->x
																	, m->y))
		return ;
	if (!(i->img) && !(i->img = mlx_xpm_file_to_image(d->mlx, XPM_MENU
		, &i->sl, &i->end)))
		exit1(1, d, "Cant load menu.xpm in data.menu!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		if (i->str[i->i] == 0 && i->str[i->i + 1] == 0 && i->str[i->i + 2] == 0)
			i->str[i->i + 3] = 255;
		else
			i->str[i->i + 3] = m->fade;
	}
	(m->fade > 0) ? (m->fade -= 5) : 0;
	mlx_put_image_to_window(d->mlx, d->win, i->img, m->x, m->y);
	(m->fade == 0) ? (d->loop = 0) : 1;
}
