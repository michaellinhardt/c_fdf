/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 07:44:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/08 08:22:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		itow(void *img, int x, int y, char *name)
{
	t_data	*d;

	d = data();
	if (LOG_ITOW == 1)
		l(3, "IMG TO WINDOW", name);
	return (mlx_put_image_to_window(d->mlx, d->win, img, x, y));
}

void	*xtoi(t_img *img, char *path)
{
	t_data	*d;

	d = data();
	if (LOG_XTOI == 1)
		l(8, "GET XPM TO IMG", path);
	if (!(img->img = mlx_xpm_file_to_image(d->mlx, path, &img->sl, &img->end)))
		exit1(1, d, "Cant load xpm file");
	if (LOG_XTOI == 1)
		l(8, "GET XPM DATA", path);
	if (!(img->str))
		img->str = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
	return (img->img);
}

void	*newi(t_img *img, int x, int y, char *name)
{
	t_data	*d;

	d = data();
	if (LOG_NEWI == 1)
		l(9, "GET NEW IMG", name);
	if (!(img->img = mlx_new_image(d->mlx, x, y)))
		exit1(1, d, "Cant get new img");
	if (LOG_NEWI == 1)
		l(9, "GET IMG DATA", name);
	if (!(img->str))
		img->str = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->end);
	return (img->img);
}
