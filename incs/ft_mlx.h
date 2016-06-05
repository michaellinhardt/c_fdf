/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:15:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/05 19:18:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H
# include "ft_mlx_struct.h"

void	mlx_handler(t_data *d, int step);

int		loop_hook(t_data *d);

int		red_cross(void);
int		keyr_hook(int key, t_data *d);
int		keyp_hook(int key, t_data *d);
int		mousep_hook(int btn, int x, int y, t_data *d);
int		mouser_hook(int btn, int x, int y, t_data *d);

void 	line(t_data *d, int x2, int y2);

#endif
