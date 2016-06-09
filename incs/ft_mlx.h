/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:15:30 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:45:56 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H
# include "ft_mlx_struct.h"

# define WIN_TITLE "Fil De Fer - mlinhard@student.42.fr"
# define SCENE_START MAIN_LOAD
# define INTRO_FADE_SPEED 2
# define WIN_X 1200
# define WIN_Y 675

# define USLEEP_TIME 20000
# define USLEEP_BOOL 1

# define MAP_DIR "./maps/"
# define XPM_INTRO "./xpm/intro.xpm"
# define XPM_PRESSANY "./xpm/pressanykey.xpm"
# define XPM_PRESSANY2 "./xpm/pressanykey2.xpm"
# define XPM_BKG "./xpm/background.xpm"
# define XPM_MENU "./xpm/menu.xpm"
# define XPM_ARROWU1 "./xpm/arrowu1.xpm"
# define XPM_ARROWU2 "./xpm/arrowu2.xpm"
# define XPM_ARROWD1 "./xpm/arrowd1.xpm"
# define XPM_ARROWD2 "./xpm/arrowd2.xpm"

# define ASC_FREEDATA "./ascii/freedata"
# define ASC_EXIT_0 "./ascii/exit0"
# define ASC_EXIT_1 "./ascii/exit1"
# define ASC_FDFINIT "./ascii/fdfinit"
# define ASC_LOGHOOK "./ascii/loghook"
# define ASC_USAGE "./ascii/usage"
# define ASC_LOGO "./ascii/logo"

# define LINE_GREY "\e[93m║\e[90m"
# define LINE_GREEN "\e[93m║\e[92m"
# define LINE_BLUE "\e[93m║\e[36m"
# define LINE_GREEN2 "\e[93m║\e[32m"
# define LINE_MAG "\e[93m║\e[35m"
# define LINE_YEL "\e[93m║"

# define LOG_ITOW 0
# define LOG_XTOI 0
# define LOG_NEWI 0
# define LOG_KEY 0
# define LOG_MOUSE 1

# define C ft_memcpy
# define CC &(int [6])

# define W ft_putendl

int		loop(int step);
void	*newi(t_img *img, int x, int y, char *name);
void	*xtoi(t_img *img, char *path);
int		itow(void *img, int x, int y, char *name);

int		red_cross(void);
void	mlx_handler(t_data *d, int step);

int		loop_hook(t_data *d);

int		mousem_hook(int x, int y, t_data *d);
int		keyr_hook(int key, t_data *d);
int		keyp_hook(int key, t_data *d);
int		mousep_hook(int btn, int x, int y, t_data *d);
int		mouser_hook(int btn, int x, int y, t_data *d);

void	line(int x1, int y1, int x2, int y2);

int		pascii(char *path);
int		pasciimsg(char *msg, int color);
void	pasciiclose(void);
void	pasciiopen(int i);

int		l(int ico, char *name, char *info);
int		l2(int ico, char *name, char *info, int val);
int		l3(int ico);
int		l4(int btn, int x, int y, char *action);

int		*x(enum coord coord);
int		mo(enum coord coord);

#endif
