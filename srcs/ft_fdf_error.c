/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 10:59:30 by mlinhard         ###   ########.fr       */
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
	ft_putstr("  🎼╔═════════════════════════════════════════════════════════");
	ft_putendl("════════════╗");
	ft_printf("  %C║ %-67s ║\n", ((err == 1) ? L'❌' : L'✅'), msg);
	ft_putstr("  🎼╚═════════════════════════════════════════════════════════");
	ft_putendl("════════════╝");
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
	ft_putendl("════════════╗");
	ft_printf("  %C║ %-67s ║\n", ((err == 0) ? L'❌' : L'✅'), msg);
	ft_putstr("  🎼╚═════════════════════════════════════════════════════════");
	ft_putendl("════════════╝");
	exit(0);
	return (1);
}
