/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 21:52:46 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 21:52:47 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	fdestroyimg2(t_data *d)
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
}

void	fdestroyimg(t_data *d)
{
	fdestroyimg2(d);
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
