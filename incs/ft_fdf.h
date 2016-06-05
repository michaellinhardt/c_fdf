/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/05 19:25:14 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "mlx.h"
# include "libft.h"
# include "ft_mlx.h"
# define WIN_X 1200
# define WIN_Y 675
# define WIN_TITLE "Fil De Fer - mlinhard@student.42.fr"
# define XPM_LOGO "./xpm/logo.xpm"
# define INTRO_FADE_SPEED 2

void	fdatabox(t_data *d);

void	intro_menu(t_data *d, t_img *i, t_img *l);
void	intro_load(t_data *d, t_img *l, t_img *i);
void	background(t_data *d, t_img *b);

int		exit1(t_data *d, char *msg);
int		exit2(t_data *d, char *del, char *msg);

#endif
