/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 03:07:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		flmenu(t_data *d)
{
	t_lmenu	*lst;
	t_lmenu	*del;

	if (!d->menu.lst)
		return (1);
	lst = d->menu.lst;
	while (lst)
	{
		del = lst;
		lst = lst->p;
		ft_memdel((void **)&del);
	}
	d->menu.lst = NULL;
	return (1);
}

void	fdestroyimg(t_data *d)
{
	(d->img.img) ? mlx_destroy_image(d->mlx, d->img.img) : 1;
	(d->intro.img) ? mlx_destroy_image(d->mlx, d->intro.img) : 1;
	(d->pressany.img) ? mlx_destroy_image(d->mlx, d->pressany.img) : 1;
	(d->bkg.img) ? mlx_destroy_image(d->mlx, d->bkg.img) : 1;
	(d->imenu.img) ? mlx_destroy_image(d->mlx, d->imenu.img) : 1;
}

void	fdatabox(t_data *d)
{
	ft_strdel(&d->map);
	flmenu(d);
	fdestroyimg(d);
}
