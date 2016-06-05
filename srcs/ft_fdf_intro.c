/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_intro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:28:16 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/05 21:21:05 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	intro_menu(t_data *d, t_img *i, t_img *l)
{
	static int	fade = 255;
	static int	dir = 6;

	if ((fade += dir) && fade >= 255)
		dir = -6;
	else if (fade <= 1)
		dir = 6;
	fade = (fade < 0) ? 0 : fade;
	fade = (fade > 255) ? 255 : fade;
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 0;
		i->str[i->i + 1] = 0;
		i->str[i->i + 2] = 0;
		i->str[i->i + 3] = (i->i >= (4 * 485) + (i->sl * 450) &&
				i->i <= (4 * 710) + (i->sl * 485)) ? fade : 255;
	}
	d->img.sl += 0;
	l->sl += 0;
	mlx_put_image_to_window(d->mlx, d->win, l->img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, i->img, 0, 0);
}

void	intro_load(t_data *d, t_img *i, t_img *l)
{
	static int	fade = 0;
	int			width;
	int			height;

	if (!(l->img) && !(l->img = mlx_xpm_file_to_image(d->mlx, XPM_LOGO, &width, &height)))
		exit1(d, "Cant load logo.xpm in data.logo!");
	if (!(i->img) && !(i->img = mlx_new_image(d->mlx, WIN_X, WIN_Y)))
		exit1(d, "Cant load image in data.img!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	if (fade == 0)
		mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, l->img, 0, 0);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 255;
		i->str[i->i + 1] = 255;
		i->str[i->i + 2] = 255;
		i->str[i->i + 3] = fade;
	}
	fade += ((fade + INTRO_FADE_SPEED) < 255) ? INTRO_FADE_SPEED : (fade * -1);
	d->scene = (fade == 0) ? INTRO_MENU : INTRO_LOAD;
	mlx_put_image_to_window(d->mlx, d->win, i->img, 0, 0);
}

// void	background(t_data *d, t_img *b)
// {
// 	b->img = mlx_new_image(d->mlx, WIN_X, WIN_Y);
// 	b->str = mlx_get_data_addr(b->img, &b->bpp, &b->sl
// 								, &b->end);
// 	b->i = -4;
// 	while ((b->i += 4) < (b->sl * WIN_Y))
// 	{
// 		b->str[b->i] = 0;
// 		b->str[b->i + 1] = 255;
// 		b->str[b->i + 2] = 0;
// 		b->str[b->i + 3] = 0;
// 	}
// 	mlx_put_image_to_window(d->mlx, d->win, b->img, 0, 0);
// }
