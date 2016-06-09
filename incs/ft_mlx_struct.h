/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 17:15:37 by mlinhard         ###   ########.fr       */
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

enum coord {
	INIT,
	MENU,
	ARROWU,
	ARROWD
};

typedef struct		s_mo
{
	int				area[4];
}					t_mo;

typedef struct		s_lmenu
{
	char			path[4096];
	int				area[6];
	int				id;
	struct s_lmenu	*p;
	struct s_lmenu	*n;
}					t_lmenu;

typedef struct		s_menu
{
	int				open;
	int				fade;
	t_lmenu			*lst;
	t_lmenu			*start;
	int				size;
	int				xpos;
	int				ypos;
	int				btnpos[6];
	char			u;
	char			d;
	enum coord		mo;
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
	char			*map;
	char			loop;
	char			loopstop;
	t_img			img;
	t_img			intro;
	t_img			pressany;
	t_img			bkg;
	t_img			imenu;
	t_menu			menu;
	int				i;
	int				mx;
	int				my;
	int				x;
	int				y;
	t_img			btnoff;
	t_img			btnover;
	t_img			arrowu1;
	t_img			arrowu2;
	t_img			arrowd1;
	t_img			arrowd2;
	enum scene		scene;
	enum scene		scenelast;
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
