/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:12:19 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/31 19:13:35 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		input_key(int key, t_data *d)
{
	if (key == 65307)
		mlx_destroy_window(d->mlx, d->win), exit(0);
	ft_printf("key: %d\n", key);
	return (0);
}

int		input_mouse(int btn, int x, int y, t_data *d)
{
	ft_printf("MOUSE: X.: %d\t\tY.: %d\n", x, y);
	return (0);
}

int		abs(int i)
{
	return ((i < 0) ? i * -1 : i);
}
