/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_interface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:28:16 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 02:55:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	intro(t_data *d, t_img *i)
{
	// mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
	// mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );

	int width;
	int height;

	if (!(i->img = mlx_xpm_file_to_image(d->mlx, XPM_LOGO, &width, &height)))
		exit1(d, "Cant init new image!");

	mlx_put_image_to_window(d->mlx, d->win, i->img, 100, 178); // 228 = moitié
}

void	background(t_data *d, t_img *b)
{
	b->img = mlx_new_image(d->mlx, WIN_X, WIN_Y);
	b->str = mlx_get_data_addr(b->img, &b->bpp, &b->sl
								, &b->end);
	b->i = -4;
	while ((b->i += 4) < (b->sl * WIN_Y))
	{
		b->str[b->i] = 0;
		b->str[b->i + 1] = 255;
		b->str[b->i + 2] = 0;
		b->str[b->i + 3] = 0;
	}
	mlx_put_image_to_window(d->mlx, d->win, b->img, 0, 0);
}
