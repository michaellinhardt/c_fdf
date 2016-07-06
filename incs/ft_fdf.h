/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/06 04:21:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <fcntl.h>
# include <dirent.h>
# include <limits.h>
# include "mlx.h"
# include "libft.h"
# include "ft_mlx.h"

t_data	*data(void);

void	parse(t_data *d, t_map *map);

int		pformatcheck(t_map *m, char *line);
int		pbuildarray(t_map *m, char *line);
int		pclear(int err, t_data *d, t_map *m, char *msg);

int		fmap(t_data *d, int i, int log);
int		flmenu(t_data *d);
void	fdatabox(t_data *d);

void	menu_mouserelease(t_data *d, t_menu *m, int x, int y);
void	menu_mouseover(t_data *d, t_menu *m, t_lmenu *l);

int		menu_close(t_data *d, t_img *im, t_menu *m, t_lmenu *l);
int		menu_refresh(t_data *d, t_img *im, t_menu *m, t_lmenu *l);
void	menu_open(t_data *d, t_img *i, t_menu *m);

void	background_load(t_data *d, t_img *b, t_img *i);

void	intro_out(t_data *d, t_img *i, t_img *l, t_img *p);
void	intro_menu(t_img *i, t_img *l);
void	intro_load(t_data *d, t_img *l, t_img *i);

int		exit1(int err, t_data *d, char *msg);
int		exit2(int err, t_data *d, char *del, char *msg);

#endif
