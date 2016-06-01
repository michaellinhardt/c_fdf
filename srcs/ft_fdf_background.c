/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:28:16 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/01 20:05:33 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	sBackground(t_data *d, t_img *b)
{
	b->img = mlx_new_image(d->mlx, WIN_X, WIN_Y);
	b->str = mlx_get_data_addr(b->img, &b->bpp, &b->sl
								, &b->end);
	b->i = -4;
	while ((b->i += 4) < (b->sl * WIN_Y))
	{
		b->str[b->i] = 0;
		b->str[b->i + 1] = 0;
		b->str[b->i + 2] = 255;
		b->str[b->i + 3] = 0;
	}
	mlx_put_image_to_window(d->mlx, d->win, b->img, 0, 0);
}
