/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_intro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 15:28:16 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 00:39:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	intro_out_fade(t_img *i, int fade)
{
	i->i = -4;
	while ((i->i += 4) < (i->sl * WIN_Y))
	{
		i->str[i->i] = 0;
		i->str[i->i + 1] = 0;
		i->str[i->i + 2] = 0;
		i->str[i->i + 3] = fade;
	}
}

void	intro_out(t_data *d, t_img *i, t_img *l, t_img *p)
{
	static int	fade = 255;

	if (fade == 255 && !mlx_destroy_image(d->mlx, p->img)
								&& !(p->img = (void *)NULL))
		p->str = (char *)NULL;
	fade -= 5;
	if (fade == -5 && !mlx_destroy_image(d->mlx, p->img)
								&& !(p->img = (void *)NULL))
	{
		p->str = (char *)NULL;
		d->scene = MAIN;
		fade = 255;
		return ;
	}
	else if (!(p->img) && !(p->img = mlx_xpm_file_to_image(d->mlx, XPM_PRESSANY2
							, &p->sl, &p->end)))
		exit1(1, d, "Cant load pressanykey2.xpm in data.pressanykey!");
	if (!(p->str))
		p->str = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->end);
	intro_out_fade(i, fade);
	mlx_put_image_to_window(d->mlx, d->win, l->img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, p->img, 500, 455);
	mlx_put_image_to_window(d->mlx, d->win, i->img, 0, 0);
}

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
	if (!(i->img) && !(i->img = mlx_xpm_file_to_image(d->mlx, XPM_PRESSANY
							, &i->sl, &i->end)))
		exit1(1, d, "Cant load pressanykey.xpm in data.pressanykey!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
	i->i = -4;
	while ((i->i += 4) < (i->sl * 22))
		i->str[i->i + 3] = fade;
	mlx_put_image_to_window(d->mlx, d->win, l->img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, i->img, 500, 455);
}

void	intro_load(t_data *d, t_img *i, t_img *l)
{
	static int	fade = 0;
	int			width;
	int			height;

	if (!(l->img) && !(l->img = mlx_xpm_file_to_image(d->mlx, XPM_INTRO
		, &width, &height)))
		exit1(1, d, "Cant load intro.xpm in data.intro!");
	if (!(i->img) && !(i->img = mlx_new_image(d->mlx, WIN_X, WIN_Y)))
		exit1(1, d, "Cant load image in data.img!");
	if (!(i->str))
		i->str = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->end);
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
	(fade == 0) ? (d->scene = INTRO_MENU) : 1;
	mlx_put_image_to_window(d->mlx, d->win, i->img, 0, 0);
}
