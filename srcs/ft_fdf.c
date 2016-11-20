/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 01:49:54 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 19:46:23 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	data_ascii2(void)
{
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl1("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG NEW IMG"
	, LINE_GREEN2, ((LOG_NEWI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG IMG TO WIN"
	, LINE_GREEN2, ((LOG_ITOW) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG XPM TO IMG"
	, LINE_GREEN2, ((LOG_XTOI) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG MOUSE INPUT"
	, LINE_GREEN2, ((LOG_MOUSE) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG KEY INPUT"
	, LINE_GREEN2, ((LOG_KEY) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "LOG LOOP"
	, LINE_GREEN2, ((LOG_LOOP) ? "true" : "false"), LINE_YEL);
}

void	data_ascii(char **argv)
{
	static char *strnum[] = { "INTRO_LOAD", "INTRO_MENU", "INTRO_OUT"
	, "MAIN_LOAD", "MAIN" };

	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "WIN_TITLE"
	, LINE_GREEN2, WIN_TITLE, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "SCENE_START"
	, LINE_GREEN2, strnum[SCENE_START], LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "INTRO_FADE_SPEED"
	, LINE_GREEN2, INTRO_FADE_SPEED, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "ARGV[1]", LINE_GREEN2
	, ((argv[1]) ? "true" : "false"), LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47s %s\n", LINE_MAG, "MAP_DIR", LINE_GREEN2
	, MAP_DIR, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47d %s\n", LINE_MAG, "WIN_X", LINE_GREEN2
	, WIN_X, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %47d %s\n", LINE_MAG, "WIN_Y", LINE_GREEN2
	, WIN_Y, LINE_YEL);
	ft_putstr("🎼  ╠═══════════════════════╬═══════════════════════════════");
	ft_putendl1("═══════════════════╣");
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_BOOL"
	, LINE_GREEN2, USLEEP_BOOL, LINE_YEL);
	ft_printf("🎼  %s %20s  %s  %-47d %s\n", LINE_MAG, "USLEEP_TIME"
	, LINE_GREEN2, USLEEP_TIME, LINE_YEL);
	data_ascii2();
}

t_data	*data(void)
{
	static t_data d;

	return (&d);
}

int		main(int argc, char **argv)
{
	t_data	*d;

	d = data();
	data_init(d, argc, argv);
	pascii(ASC_LOGO);
	(!d->map.path) ? pascii(ASC_USAGE) : 1;
	pascii(ASC_FDFINIT);
	data_ascii(argv);
	pascii(ASC_LOGHOOK);
	mlx_handler(d, 0);
	mlx_handler(d, 1);
	return (0);
}
