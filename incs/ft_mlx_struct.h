/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:40:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_STRUCT_H
# define FT_FDF_STRUCT_H

enum scene {
	INTRO_LOAD,
	INTRO_MENU,
	INTRO_OUT,
	MAIN_LOAD,
	MAIN
};

typedef struct		s_lmenu
{
	char			path[4096];
	char			start;
	struct s_lmenu	*p;
	struct s_lmenu	*n;
}					t_lmenu;

typedef struct		s_menu
{
	int				open;
	int				fade;
	t_lmenu			*lst;
	int				x;
	int				y;
}					t_menu;

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sl;
	int				end;
	int				i;
}					t_img;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	char			loop;
	char			loopstop;
	int				frame;
	t_img			img;
	t_img			intro;
	t_img			pressany;
	t_img			bkg;
	t_img			imenu;
	int				x;
	int				y;
	enum scene		scene;
	t_menu			menu;
}					t_data;

typedef struct		s_line
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_line;

#endif
