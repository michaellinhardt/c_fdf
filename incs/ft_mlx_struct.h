/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 05:28:15 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 21:17:53 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gnl is reading, map select, music change (avec titre)
// LOG EN BAS DE LECRAN SUR LETAT DE LA MAP
// IPS EN HAUT DE LECRAN

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

typedef struct		s_mat
{
	char			lock;
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
}					t_mat;

typedef struct		s_map
{
	char			*path;
	char			read[BUFF_SIZE + 1];
	int				**map;
	unsigned char	**col;
	t_mat			mat;
	int				i;
	int				j;
	int				x;
	int				y;
	int				xm;
	int				ym;
	int				zm;
	double			rx;
	double			ry;
	double			rz;
	double			heigh;
	double			heigh2;
	int				color;
	int				size;
	int				maxy;
	int				posx;
	int				posy;
	int				fd;
	int				status; // 1 = parse erreur , 2 = build array // 0 = aucune map // -1 ready to draw
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

typedef struct		s_input
{
	int				pageup;
	int				pagedw;
	int				left;
	int				mleft;
	int				right;
	int				mright;
	int				up;
	int				down;
	int				shift;
	int				x;
	int				y;
}					t_input;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_input			input;
	char			loop;
	char			loopstop;
	t_img			img;
	t_img			intro;
	t_img			pressany;
	t_img			bkg;
	t_img			border;
	t_img			imenu;
	t_img			fdf;
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
	t_lmenu			*l;
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
