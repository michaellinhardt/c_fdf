/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/08 04:44:57 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		exit1(int err, t_data *d, char *msg)
{
	fdatabox(d);
	if (err != 0)
		pascii(ASC_EXIT_1);
	else
		pascii(ASC_EXIT_0);
	ft_putstr("🎼  ╔═════════════════════════════════════════════════════════");
	ft_putendl1("═════════════════╗");
	ft_printf(" %C ║ %s%-72s%s ║\n", ((err == 1) ? L'🚨' : L'🌙')
		, ((err == 1) ? "\e[91m" : "\e[96m"), msg, "\e[93m");
	ft_putstr("🎼  ╚═════════════════════════════════════════════════════════");
	ft_putendl1("═════════════════╝");
	exit(0);
	return (1);
}

int		exit2(int err, t_data *d, char *del, char *msg)
{
	ft_strdel(&del);
	fdatabox(d);
	if (err != 0)
		pascii(ASC_EXIT_1);
	else
		pascii(ASC_EXIT_0);
	ft_putstr("  🎼╔═════════════════════════════════════════════════════════");
	ft_putendl1("════════════╗");
	ft_printf("  %C║ %-67s ║\n", ((err == 0) ? L'🚨' : L'🌙'), msg);
	ft_putstr("  🎼╚═════════════════════════════════════════════════════════");
	ft_putendl1("════════════╝");
	exit(0);
	return (1);
}
