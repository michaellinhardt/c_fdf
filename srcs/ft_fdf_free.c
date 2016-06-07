/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 08:38:48 by mlinhard         ###   ########.fr       */
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
	(d->img.img) ? mlx_destroy_image(d->mlx, d->img.img)
	+ W("🆓(t_img *)img: destroy") : W("🆓(t_img *)img: already empty");
	(d->intro.img) ? mlx_destroy_image(d->mlx, d->intro.img)
	+ W("🆓(t_img *)intro: destroy") : W("🆓(t_img *)intro: already empty");
	(d->pressany.img) ? mlx_destroy_image(d->mlx, d->pressany.img)
	+ W("🆓(t_img *)presany: destroy") : W("🆓(t_img *)presany: already empty");
	(d->bkg.img) ? mlx_destroy_image(d->mlx, d->bkg.img)
	+ W("🆓(t_img *)bkg: destroy") : W("🆓(t_img *)bkg: already empty");
	(d->imenu.img) ? mlx_destroy_image(d->mlx, d->imenu.img)
	+ W("🆓(t_img *)imenu: destroy") : W("🆓(t_img *)imenu: already empty");
	(d->btnact.img) ? mlx_destroy_image(d->mlx, d->btnact.img)
	+ W("🆓(t_img *)btnact: destroy") : W("🆓(t_img *)btnact: already empty");
	(d->btnoff.img) ? mlx_destroy_image(d->mlx, d->btnoff.img)
	+ W("🆓(t_img *)btnoff: destroy") : W("🆓(t_img *)btnoff: already empty");
	(d->btnover.img) ? mlx_destroy_image(d->mlx, d->btnover.img)
	+ W("🆓(t_img *)btnover: destroy") : W("🆓(t_img *)btnover: already empty");
}

void	fdatabox(t_data *d)
{
	ft_strdel(&d->map);
	flmenu(d);
	fdestroyimg(d);
}
