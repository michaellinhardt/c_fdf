/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/05/30 06:00:37 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_STRUCT_H
# define FT_FDF_STRUCT_H

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				x;
	int				x2;
	int				y;
	int				y2;
}					t_data;

typedef struct		s_draw
{
	char			start;
	int				big;
	int				big2;
	int				small;
	int				small2;
}					t_draw;

#endif
