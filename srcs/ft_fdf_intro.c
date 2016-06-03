/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_intro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:28:16 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 04:42:02 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	intro_load_fade(t_data *d, t_img *i, int step)
{
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 0;
		i->str[i->i + 1] = 0;
		i->str[i->i + 2] = 0;
		i->str[i->i + 3] = 0xFF;
	}
	ft_printf("ici\n");
}

void	intro_load(t_data *d, t_img *l, t_img *i)
{
	static int	step = 0;
	int			width;
	int			height;

	ft_printf("Load intro!\n");
	if (!(l->img) && !(l->img = mlx_xpm_file_to_image(d->mlx, XPM_LOGO, &width, &height)))
		exit1(d, "Cant load logo.xpm in data.logo!");
	if (!(i->img) && !(i->img = mlx_new_image(d->mlx, WIN_X, WIN_Y)))
		exit1(d, "Cant load image in data.img!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	// mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, l->img, 100, 178); // 228 = moitié
	intro_load_fade(d, i, step);
	// step += (step > -1) ?  : 0;
	d->scene = (step == 0) ? INTRO_WAIT : INTRO_LOAD;
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
