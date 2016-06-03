/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:50:14 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 02:26:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "mlx.h"
# include "libft.h"
# include "ft_mlx.h"
# define XPM_LOGO "./xpm/logo.xpm"

void	fdatabox(t_data *d);

void	intro(t_data *d, t_img *i);
void	background(t_data *d, t_img *b);

int		exit1(t_data *d, char *msg);
int		exit2(t_data *d, char *del, char *msg);

#endif
