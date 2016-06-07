/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 10:42:34 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <fcntl.h>
# include <dirent.h>
# include "mlx.h"
# include "libft.h"
# include "ft_mlx.h"

t_data	*data(void);

int		flmenu(t_data *d);
void	fdatabox(t_data *d);

void	menu_open(t_data *d, t_img *i, t_menu *m);

void	background_load(t_data *d, t_img *b, t_img *i);

void	intro_out(t_data *d, t_img *i, t_img *l, t_img *p);
void	intro_menu(t_data *d, t_img *i, t_img *l);
void	intro_load(t_data *d, t_img *l, t_img *i);

int		exit1(int err, t_data *d, char *msg);
int		exit2(int err, t_data *d, char *del, char *msg);

#endif
