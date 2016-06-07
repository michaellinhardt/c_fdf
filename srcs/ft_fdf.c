/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 11:39:04 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	data_ascii_break(void)
{
	ft_putstr("  🎼╠═══════════════════════╬════════════════════════════════");
	ft_putendl("═══════════════════╣");
}

void	data_ascii(t_data *d, int argc, char **argv)
{
	static char *strnum[] = { "INTRO_LOAD", "INTRO_MENU", "INTRO_OUT"
	, "MAIN_LOAD", "MAIN" };

	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "WIN_TITLE", WIN_TITLE);
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "ARGC", argc);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "ARGV[1]", ((argv[1]) ? "true" : "false"));
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "SCENE_START", strnum[SCENE_START]);
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "INTRO_FADE_SPEED", INTRO_FADE_SPEED);
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "WIN_X", WIN_X);
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "WIN_Y", WIN_Y);
	data_ascii_break();
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "USLEEP_BOOL", USLEEP_BOOL);
	ft_printf("  🎼║ %20s  ║  %-48d ║\n", "USLEEP_TIME", USLEEP_TIME);
	data_ascii_break();
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "MAP_DIR", MAP_DIR);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "XPM_INTRO", XPM_INTRO);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "XPM_PRESSANY", XPM_PRESSANY);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "XPM_PRESSANY2", XPM_PRESSANY2);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "XPM_BKG", XPM_BKG);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "XPM_MENU", XPM_MENU);
	data_ascii_break();
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "ASC_FREEDATA", ASC_FREEDATA);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "ASC_EXIT_0", ASC_EXIT_0);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "ASC_EXIT_1", ASC_EXIT_1);
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "ASC_FDFINIT", ASC_FDFINIT);
	data_ascii_break();
	ft_printf("  🎼║ %20s  ║  %-48s ║\n", "D->LOOP", ((d->loop == 1) ? "true" : "false"));
}

t_data	*data(void)
{
	static t_data d;

	return (&d);
}

void	data_init(t_data *d, int argc, char **argv)
{
	ft_bzero(d, sizeof(t_data));
	d->scene = SCENE_START;
	d->img.img = (void *)NULL;
	d->img.str = (char *)NULL;
	d->intro.img = (void *)NULL;
	d->intro.str = (char *)NULL;
	d->pressany.img = (void *)NULL;
	d->pressany.str = (char *)NULL;
	d->imenu.img = (void *)NULL;
	d->imenu.str = (char *)NULL;
	d->menu.fade = 255;
	d->menu.x = 471;
	d->menu.y = 117;
	d->menu.lst = (t_lmenu *)NULL;
	if (argc == 2)
		d->map = ft_strdup(argv[1]);
	else
		d->map = (char *)NULL;
	d->loop = 1;
}

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	data_init(d, argc, argv);
	pascii(ASC_FDFINIT);
	data_ascii(d, argc, argv);
	ft_putstr("  🎼╚═══════════════════════╩══════════════════════════════");
	ft_putendl("═════════════════════╝");
	mlx_handler(d, 0);
	mlx_handler(d, 1);
	return (0);
}
