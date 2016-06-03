/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 02:56:12 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		main(void)
{
	t_data	d;

	mlx_handler(&d, 0);
	intro(&d, &d.intro);
	// background(&d, &d.bkg);
	// ft_printf("BEFORE DRAW: X: %d\tY: %d\n", d.x, d.y);
	// line(&d, 200, 100);
	// line(&d, 200, 200);
	// line(&d, 100, 200);
	// line(&d, 100, 100);
	// ft_printf("AFTER DRAW: X: %d\tY: %d\n", d.x, d.y);
	mlx_handler(&d, 1);
	return (0);
}
