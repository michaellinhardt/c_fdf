/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/11 06:52:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		fascii(int ico, char *type, char *data)
{
	wchar_t		uni;
	char		msg[4096];
	char		bar[100];

	uni = (ico == 1) ? L'✅' : L'❕';
	(ico == 1) ?
	ft_memcpy(msg, "free\0", 8) : ft_memcpy(msg, "-\0", 14);
	ft_memcpy(bar, ((ico == 1) ? LINE_GREEN : LINE_GREY), 13);
	ft_printf(" %C %s %12s %s %-23s %s %-28s %s\e[93m\n", uni, bar, type, bar, data
																, bar, msg, bar);
	return (1);
}

int		flmenu(t_data *d, int log)
{
	t_lmenu	*lst;
	t_lmenu	*del;

	if (log == 1)
		fascii(((d->menu.lst) ? 1 : 0), "t_lmenu *", "d->menu.lst");
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
	fascii(((d->img.img) ? 1 : 0), "t_img *", "d->img.img");
	(d->img.img) ? mlx_destroy_image(d->mlx, d->img.img) : 0;
	fascii(((d->intro.img) ? 1 : 0), "t_img *", "d->intro.img");
	(d->intro.img) ? mlx_destroy_image(d->mlx, d->intro.img) : 0;
	fascii(((d->pressany.img) ? 1 : 0), "t_img *", "d->pressany.img");
	(d->pressany.img) ? mlx_destroy_image(d->mlx, d->pressany.img) : 0;
	fascii(((d->bkg.img) ? 1 : 0), "t_img *", "d->bkg.img");
	(d->bkg.img) ? mlx_destroy_image(d->mlx, d->bkg.img) : 0;
	fascii(((d->imenu.img) ? 1 : 0), "t_img *", "d->imenu.img");
	(d->imenu.img) ? mlx_destroy_image(d->mlx, d->imenu.img) : 0;
	fascii(((d->btnoff.img) ? 1 : 0), "t_img *", "d->btnoff.img");
	(d->btnoff.img) ? mlx_destroy_image(d->mlx, d->btnoff.img) : 0;
	fascii(((d->btnover.img) ? 1 : 0), "t_img *", "d->btnover.img");
	(d->btnover.img) ? mlx_destroy_image(d->mlx, d->btnover.img) : 0;
	fascii(((d->arrowu1.img) ? 1 : 0), "t_img *", "d->arrowu1.img");
	(d->arrowu1.img) ? mlx_destroy_image(d->mlx, d->arrowu1.img) : 0;
	fascii(((d->arrowu2.img) ? 1 : 0), "t_img *", "d->arrowu2.img");
	(d->arrowu2.img) ? mlx_destroy_image(d->mlx, d->arrowu2.img) : 0;
	fascii(((d->arrowu3.img) ? 1 : 0), "t_img *", "d->arrowu3.img");
	(d->arrowu3.img) ? mlx_destroy_image(d->mlx, d->arrowu3.img) : 0;
	fascii(((d->arrowd1.img) ? 1 : 0), "t_img *", "d->arrowd1.img");
	(d->arrowd1.img) ? mlx_destroy_image(d->mlx, d->arrowd1.img) : 0;
	fascii(((d->arrowd2.img) ? 1 : 0), "t_img *", "d->arrowd2.img");
	(d->arrowd2.img) ? mlx_destroy_image(d->mlx, d->arrowd2.img) : 0;
	fascii(((d->arrowd3.img) ? 1 : 0), "t_img *", "d->arrowd3.img");
	(d->arrowd3.img) ? mlx_destroy_image(d->mlx, d->arrowd3.img) : 0;
	fascii(((d->fdf.img) ? 1 : 0), "t_img *", "d->fdf.img");
	(d->fdf.img) ? mlx_destroy_image(d->mlx, d->fdf.img) : 0;
	fascii(((d->border.img) ? 1 : 0), "t_img *", "d->border.img");
	(d->border.img) ? mlx_destroy_image(d->mlx, d->border.img) : 0;
}

int		fmap(t_data *d, int i, int log)
{
	if (log == 1)
	{
		fascii(((d->map.map) ? 1 : 0), "int **", "d->map.map");
		fascii(((d->map.col) ? 1 : 0), "int **", "d->map.col");
		fascii(((d->map.path) ? 1 : 0), "char *", "d->map.path");
	}
	if (d->map.map)
		while (++i < d->map.ym)
			ft_memdel((void **)&d->map.map[i]);
	if (d->map.map)
		ft_memdel((void **)&d->map.map);
	i = -1;
	if (d->map.col)
		while (++i < d->map.ym)
			ft_memdel((void **)&d->map.col[i]);
	if (d->map.col)
		ft_memdel((void **)&d->map.col);
	ft_strdel(&d->map.path);
	return (1);
}

void	fdatabox(t_data *d)
{
	pascii(ASC_FREEDATA);
	flmenu(d, 1);
	fmap(d, -1, 1);
	get_next_line(-10, NULL);
	fdestroyimg(d);
}
