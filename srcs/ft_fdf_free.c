/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 08:30:09 by mlinhard         ###   ########.fr       */
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
	+ w("🆓(t_img *)img: destroy") : w("🆓(t_img *)img: already empty");
	(d->intro.img) ? mlx_destroy_image(d->mlx, d->intro.img)
	+ w("🆓(t_img *)intro: destroy") : w("🆓(t_img *)intro: already empty");
	(d->pressany.img) ? mlx_destroy_image(d->mlx, d->pressany.img)
	+ w("🆓(t_img *)presany: destroy") : w("🆓(t_img *)presany: already empty");
	(d->bkg.img) ? mlx_destroy_image(d->mlx, d->bkg.img)
	+ w("🆓(t_img *)bkg: destroy") : w("🆓(t_img *)bkg: already empty");
	(d->imenu.img) ? mlx_destroy_image(d->mlx, d->imenu.img)
	+ w("🆓(t_img *)imenu: destroy") : w("🆓(t_img *)imenu: already empty");
	(d->btnact.img) ? mlx_destroy_image(d->mlx, d->btnact.img)
	+ w("🆓(t_img *)btnact: destroy") : w("🆓(t_img *)btnact: already empty");
	(d->btnoff.img) ? mlx_destroy_image(d->mlx, d->btnoff.img)
	+ w("🆓(t_img *)btnoff: destroy") : w("🆓(t_img *)btnoff: already empty");
	(d->btnover.img) ? mlx_destroy_image(d->mlx, d->btnover.img)
	+ w("🆓(t_img *)btnover: destroy") : w("🆓(t_img *)btnover: already empty");
}

void	fdatabox(t_data *d)
{
	ft_strdel(&d->map);
	flmenu(d);
	fdestroyimg(d);
}
