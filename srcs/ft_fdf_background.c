/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 19:27:48 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/08 08:16:45 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	background_load(t_data *d, t_img *b, t_img *i)
{
	static int	fade = 0;

	(!(b->img)) ? (b->img = xtoi(b, XPM_BKG)) : (t_img *)NULL;
	if (!(i->img))
		i->img = newi(i, WIN_X, WIN_Y, "d->img");
	itow(b->img, 0, 0, "background");
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
	(fade == 0) ? (d->loop = 0) : 1;
	itow(i->img, 0, 0, "fade in");
}
