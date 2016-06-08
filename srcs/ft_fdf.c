/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/08 05:03:52 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	l(int ico, char *name, char *info)
{
	wchar_t		uni;

	(ico == 1) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 2) ? (uni = L'🕹') : (wchar_t)NULL;
	(ico == 3) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 4) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 5) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 6) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 7) ? (uni = L'➿') : (wchar_t)NULL;
	ft_printf(" %C %s %20s  %s  %-47s %s\n", uni, LINE_BLUE, name
	, LINE_GREEN2, info, LINE_YEL);
}

void	data_ascii(t_data *d, int argc, char **argv)
{
	static char *strnum[] = { "INTRO_LOAD", "INTRO_MENU", "INTRO_OUT"
	, "MAIN_LOAD", "MAIN" };

	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_BLUE, "WIN_TITLE"
	, LINE_GREEN2, WIN_TITLE, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_BLUE, "SCENE_START"
	, LINE_GREEN2, strnum[SCENE_START], LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_BLUE, "INTRO_FADE_SPEED"
	, LINE_GREEN2, INTRO_FADE_SPEED, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_BLUE, "ARGV[1]", LINE_GREEN2
	, ((argv[1]) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47s %s\n", LINE_BLUE, "MAP_DIR", LINE_GREEN2
	, MAP_DIR, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_BLUE, "WIN_X", LINE_GREEN2
	, WIN_X, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_BLUE, "WIN_Y", LINE_GREEN2
	, WIN_Y, LINE_YEL);
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_BLUE, "USLEEP_BOOL"
	, LINE_GREEN2, USLEEP_BOOL, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_BLUE, "USLEEP_TIME"
	, LINE_GREEN2, USLEEP_TIME, LINE_YEL);
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
