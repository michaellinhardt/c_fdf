/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/06 00:11:37 by mlinhard         ###   ########.fr       */
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
# define XPM_INTRO "./xpm/intro.xpm"
# define XPM_PRESSANY "./xpm/pressanykey.xpm"
# define XPM_PRESSANY2 "./xpm/pressanykey2.xpm"
# define INTRO_FADE_SPEED 2

void	fdatabox(t_data *d);

void	intro_out(t_data *d, t_img *i, t_img *l, t_img *p);
void	intro_menu(t_data *d, t_img *i, t_img *l);
void	intro_load(t_data *d, t_img *l, t_img *i);

int		exit1(int err, t_data *d, char *msg);
int		exit2(int err, t_data *d, char *del, char *msg);

#endif
