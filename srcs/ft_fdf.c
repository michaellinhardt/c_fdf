/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 10:03:49 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	data_ascii2(t_data *d)
{
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "LOG NEW IMG"
	,LINE_GREEN2 , ((LOG_NEWI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "LOG IMG TO WIN"
	,LINE_GREEN2 , ((LOG_ITOW) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "LOG XPM TO IMG"
	,LINE_GREEN2 , ((LOG_XTOI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "LOG MOUSE INPUT"
	,LINE_GREEN2 , ((LOG_MOUSE) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "LOG KEY INPUT"
	,LINE_GREEN2 , ((LOG_KEY) ? "true" : "false"), LINE_YEL);
}

void	data_ascii(t_data *d, int argc, char **argv)
{
	static char *strnum[] = { "INTRO_LOAD", "INTRO_MENU", "INTRO_OUT"
	, "MAIN_LOAD", "MAIN" };

	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "WIN_TITLE"
	, LINE_GREEN2, WIN_TITLE, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "SCENE_START"
	, LINE_GREEN2, strnum[SCENE_START], LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "INTRO_FADE_SPEED"
	, LINE_GREEN2, INTRO_FADE_SPEED, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "ARGV[1]", LINE_GREEN2
	, ((argv[1]) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_MAG, "MAP_DIR", LINE_GREEN2
	, MAP_DIR, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "WIN_X", LINE_GREEN2
	, WIN_X, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "WIN_Y", LINE_GREEN2
	, WIN_Y, LINE_YEL);
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_BOOL"
	, LINE_GREEN2, USLEEP_BOOL, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_TIME"
	, LINE_GREEN2, USLEEP_TIME, LINE_YEL);
	data_ascii2(d);
}

t_data	*data(void)
{
	static t_data d;

	return (&d);
}

void	data_init(t_data *d, int argc, char **argv)
{
	ft_bzero(d, sizeof(t_data));
	d->scene = INTRO_LOAD;
	d->scenelast = d->scene;
	d->img.img = (void *)NULL;
	d->img.str = (char *)NULL;
	d->intro.img = (void *)NULL;
	d->intro.str = (char *)NULL;
	d->pressany.img = (void *)NULL;
	d->pressany.str = (char *)NULL;
	d->imenu.img = (void *)NULL;
	d->imenu.str = (char *)NULL;
	d->menu.fade = 255;
	d->menu.xpos = 471;
	d->menu.ypos = 117;
	d->menu.lst = (t_lmenu *)NULL;
	d->map = (argc == 2) ? ft_strdup(argv[1]) : (char *)NULL;
	d->loop = 1;
}

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	data_init(d, argc, argv);
	pascii(ASC_LOGO);
	(!d->map) ? pascii(ASC_USAGE) : 1;
	pascii(ASC_FDFINIT);
	data_ascii(d, argc, argv);
	pascii(ASC_LOGHOOK);
	mlx_handler(d, 0);
	mlx_handler(d, 1);
	return (0);
}
