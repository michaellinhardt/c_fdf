/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:09:39 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/01 11:09:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	mlx_handler(t_data *d, int step)
{
	if (step == 0)
	{
		d->mlx = mlx_init();
		d->win = mlx_new_window(d->mlx, 400, 400, "MLX BITCH");
	}
	if (step == 1)
	{
		mlx_key_hook(d->win, input_key, (void *)d);
		mlx_mouse_hook(d->win, input_mouse, (void *)d);
		mlx_loop(d->mlx);
	}
}
