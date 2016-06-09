/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouseover.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:12:26 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouseover(t_data *d, t_menu *m)
{
	(mo(ARROWU1) && m->mo != ARROWU1 && (m->mo = ARROWU1)) ? loop(1) : 0;
	(!mo(ARROWU1) && m->mo == ARROWU1 && !(m->mo = INIT)) ? loop(1) : 0;
}
