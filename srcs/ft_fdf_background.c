/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:27:48 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 20:07:50 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	background_load(t_data *d, t_img *b, t_img *i)
{
	static int	fade = 0;

	if (!(b->img) && !(b->img = mlx_xpm_file_to_image(d->mlx, XPM_BKG
													, &b->sl, &b->end)))
		exit1(1, d, "Cant load background.xpm in data.bkg!");
	if (!(i->img) && !(i->img = mlx_new_image(d->mlx, WIN_X, WIN_Y)))
		exit1(1, d, "Cant load image in data.img!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	mlx_put_image_to_window(d->mlx, d->win, b->img, 0, 0);
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 0;
		i->str[i->i + 1] = 0;
		i->str[i->i + 2] = 0;
		i->str[i->i + 3] = fade;
	}
	fade += ((fade + (INTRO_FADE_SPEED * 3)) < 255) ?
						(INTRO_FADE_SPEED * 3) : (fade * -1);
	(fade == 0) ? (d->scene = MAIN) : 1;
	mlx_put_image_to_window(d->mlx, d->win, i->img, 0, 0);
}
