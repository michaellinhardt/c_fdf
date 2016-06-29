/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/29 08:40:29 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gnl is reading, map select, music change (avec titre)
// LOG EN BAS DE LECRAN SUR LETAT DE LA MAP
// IPS EN HAUT DE LECRAN

#ifndef FT_FDF_STRUCT_H
# define FT_FDF_STRUCT_H

enum pseq {
	START_Z,
	READ_Z,
	READ_Z_3,
	READ_Z_4,
	READ_Z_5,
	READ_Z_6,
	READ_Z_7,
	READ_Z_8,
	READ_Z_9,
	READ_Z_10,
	READ_Z_11,
	READ_COLOR_0,
	READ_COLOR_X,
	READ_COLOR_1,
	READ_COLOR_2,
	READ_COLOR_3,
	READ_COLOR_4,
	READ_COLOR_5,
	READ_COLOR_6,
	READ_SPACE,
};

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

typedef struct		s_map
{
	char			*path;
	char			read[BUFF_SIZE + 1];
	int				**map;
	int				i;
	int				x;
	int				y;
	int				xm;
	int				ym;
	int				fd;
	enum pseq		seq;
	int				status; // 1 = lire fichier
}					t_map;

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
	int				calcpos;
	t_lmenu			*lst;
	t_lmenu			*start;
	t_lmenu			*over;
	int				size;
	int				xpos;
	int				ypos;
	int				yclose;
	int				close;
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
	t_map			map;
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
	t_img			arrowu3;
	t_img			arrowd1;
	t_img			arrowd2;
	t_img			arrowd3;
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
